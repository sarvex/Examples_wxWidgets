#include <wx/app.h>
#include <wx/commandlinkbutton.h>
#include <wx/frame.h>
#include <wx/panel.h>
#include <wx/stattext.h>

class Frame : public wxFrame {
public:
  Frame() : wxFrame(nullptr, wxID_ANY, "CommandLinkButton example", wxDefaultPosition, wxSize(300, 300)) {
    commandLinkButton1->Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
      staticText1->SetLabel(wxString::Format("commandLinkButton1 clicked %d times", ++commandLinkButton1Clicked));
    });
  }
  
private:
  wxPanel* panel = new wxPanel(this);
  wxCommandLinkButton* commandLinkButton1 = new wxCommandLinkButton(panel, wxID_ANY, "Link", "Information text", wxPoint(30, 30), wxSize(150, 40));
  wxStaticText* staticText1 = new wxStaticText(panel, wxID_ANY, "commandLinkButton1 clicked 0 times", wxPoint(30, 100), wxSize(200, 20));
  int commandLinkButton1Clicked = 0;
};

class Application : public wxApp {
  bool OnInit() override {(new Frame())->Show(); return true;}
};

wxIMPLEMENT_APP(Application);