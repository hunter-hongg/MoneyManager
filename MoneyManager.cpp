#include "MoneyManager.hpp"
#include "simple.hpp"

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

    panel -> SetSizer(vbox);
    panel -> Layout();
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
