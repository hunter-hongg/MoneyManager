#include <wx/wx.h>
#include <type.hpp>

class MyApp : public wxApp
{
public:
    virtual bool OnInit();
};

class MyFrame : public wxFrame
{
public:
    MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
    void start();
    void moneyadd(WXBTNEVT&);
    void back_main(WXBTNEVT&);
    void clean_panel();
private: 
    wxPanel* panel;
};


