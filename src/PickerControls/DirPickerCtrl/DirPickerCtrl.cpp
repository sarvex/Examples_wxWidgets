#include <wx/wx.h>
#include <wx/filepicker.h>

class Frame : public wxFrame {
public:
  Frame() : wxFrame(nullptr, wxID_ANY, "DirPickerCtrl example", wxDefaultPosition, {300, 300}) {
    picker->Bind(wxEVT_DIRPICKER_CHANGED, [&](wxFileDirPickerEvent& event) {
      label->SetLabel(wxString::Format("Path = %s", event.GetPath()));
    });
  }
  
private:
  wxPanel* panel = new wxPanel(this);
  wxStaticText* label = new wxStaticText(panel, wxID_ANY, "Path = ", wxPoint(10, 50));
  wxDirPickerCtrl* picker = new wxDirPickerCtrl(panel, wxID_ANY, wxEmptyString, wxEmptyString, {10, 10});
};

class Application : public wxApp {
  bool OnInit() override {(new Frame())->Show(); return true;}
};

wxIMPLEMENT_APP(Application);
