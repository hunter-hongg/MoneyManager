#include <cstdlib>
#include <string>
#include <fstream>
#include "MoneyManager.hpp"
#include "simple.hpp"

int ReadMoney() {
    std::string home = getenv("HOME");
    std::string money = home + "/.moneymanager";
    std::ifstream tmp(money);
    if(!tmp.is_open()){
        std::ofstream ttmp(money);
        ttmp << 0;
        ttmp.close();
    }
    tmp.close();
    std::ifstream inmoney(money);
    std::string a;
    inmoney >> a;
    inmoney.close();
    return atoi(a.c_str());
}
bool MyApp::OnInit()
{
    MyFrame *frame = new MyFrame("Money Manager", wxDefaultPosition, wxSize(500, 500));
    frame->Show(true);
    return true;
}

MyFrame::MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
    : wxFrame(nullptr, wxID_ANY, title, pos, size)
{
    panel = new wxPanel(this, wxID_ANY);
    this -> start();
}

void MyFrame::start() {
    auto vbox = Simple::Init(panel, this);

    Simple::TitleNoSpacer("零花钱管理", panel, vbox);
    Simple::ShowButton("目前零花钱："+std::__cxx11::to_string(ReadMoney()), panel, vbox);

    Simple::Button(&MyFrame::moneyadd, "增加零花钱", panel, vbox, this); 

    panel -> AddStretchSpacer();
    panel -> SetSizer(vbox);
    panel -> Layout();
}

void MyFrame::moneyadd(WXBTNEVT&) {
    auto vbox = Simple::Init(panel, this);

    Simple::Title("零花钱增加", panel, vbox);

    Simple::BackButton(&MyFrame::back_main, panel, vbox, this);
}

void MyFrame::back_main(WXBTNEVT&){
    this -> start();
}

void MyFrame::clean_panel()
{
    if (!panel) return;
    wxSizer* sizer = panel->GetSizer();
    if (!sizer) return;
    wxSizerItemList& items = sizer->GetChildren();
    for (wxSizerItemList::iterator it = items.begin(); it != items.end(); ++it) {
        wxSizerItem* item = *it;
        if (item->IsWindow()) {
            wxWindow* window = item->GetWindow();
            if (window) {
                if (wxStaticText* staticText = wxDynamicCast(window, wxStaticText)) {
                    staticText->SetLabel(wxT(""));
                }
            }
        }
    }
    sizer->Clear(true);
    panel->SetSizer(sizer);
    panel->Layout();
}

IMPLEMENT_APP(MyApp)
