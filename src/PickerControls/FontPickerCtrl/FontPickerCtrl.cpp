#include <wx/wx.h>
#include <wx/fontpicker.h>

class Frame : public wxFrame {
public:
  Frame() : wxFrame(nullptr, wxID_ANY, "FontPickerCtrl example", wxDefaultPosition, {300, 300}) {
    picker->SetSelectedFont(label->GetFont());
#if wxMAJOR_VERSION > 3 || (wxMAJOR_VERSION == 3 && wxMINOR_VERSION >= 1)
    picker->SetSelectedColour(label->GetForegroundColour());
#endif
    picker->Bind(wxEVT_FONTPICKER_CHANGED, [&](wxFontPickerEvent& event) {
      label->SetFont(picker->GetSelectedFont());
#if wxMAJOR_VERSION > 3 || (wxMAJOR_VERSION == 3 && wxMINOR_VERSION >= 1)
      label->SetForegroundColour(picker->GetSelectedColour());
#endif
    });
  }
  
private:
  wxPanel* panel = new wxPanel(this);
  wxStaticText* label = new wxStaticText(panel, wxID_ANY,
    u8"The quick brown fox jumps over the lazy dog.\n"
    u8"THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG.\n"
    u8"0123456789+-*/%~^&|=<>≤≥±÷≠{{[()]}},;:.?¿!¡\n"
    u8"àçéèêëïî@@°_#§$ù£€æœøπµ©®∞\\\"'\n"
    u8"\u0400\u0401\u0402\u0403\u0404\u0405\u0406\u0407\u0408\u0409\u040a\u040b\u040c\u040d\u040e\u040f\n"
    u8"\u0410\u0411\u0412\u0413\u0414\u0415\u0416\u0417\u0418\u0419\u041a\u041b\u041c\u041d\u041e\u041f\n"
    u8"\u4ea0\u4ea1\u4ea2\u4ea3\u4ea4\u4ea5\u4ea6\u4ea7\u4ea8\u4ea9\u4eaa\u4eab\u4eac\u4ead\u4eae\u4eaf\n"
    u8"\u4eb0\u4eb1\u4eb2\u4eb3\u4eb4\u4eb5\u4eb6\u4eb7\u4eb8\u4eb9\u4eba\u4ebb\u4ebc\u4ebd\u4ebe\u4ebf\n"
    u8"\U0001F428", wxPoint(10, 50));
  wxFontPickerCtrl* picker = new wxFontPickerCtrl(panel, wxID_ANY, {}, {10, 10});
};

class Application : public wxApp {
  bool OnInit() override {(new Frame())->Show(); return true;}
};

wxIMPLEMENT_APP(Application);
