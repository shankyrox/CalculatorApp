// wxWidgets "Hello world" Program
// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

class CalculatorApp : public wxApp
{
public:
	virtual bool OnInit();
};
class CalcMainFrame : public wxFrame
{
public:
	CalcMainFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
private:
	void OnHello(wxCommandEvent& event);
	void OnExit(wxCommandEvent& event);
	void OnAbout(wxCommandEvent& event);
	wxDECLARE_EVENT_TABLE();
};
enum class MenuID
{
	ID_Hello = 1
};
wxBEGIN_EVENT_TABLE(CalcMainFrame, wxFrame)
EVT_MENU(static_cast<int>(MenuID::ID_Hello), CalcMainFrame::OnHello)
EVT_MENU(wxID_EXIT, CalcMainFrame::OnExit)
EVT_MENU(wxID_ABOUT, CalcMainFrame::OnAbout)
wxEND_EVENT_TABLE()
wxIMPLEMENT_APP(CalculatorApp);
bool CalculatorApp::OnInit()
{
	CalcMainFrame *frame = new CalcMainFrame("Simple Calculator", wxPoint(50, 50), wxSize(450, 340));
	frame->Show(true);
	return true;
}
CalcMainFrame::CalcMainFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
	: wxFrame(NULL, wxID_ANY, title, pos, size)
{
	auto menuFile = std::make_unique<wxMenu>();
	menuFile->Append(static_cast<int>(MenuID::ID_Hello), "&Hello...\tCtrl-H",
		"Help string shown in status bar for this menu item");
	menuFile->AppendSeparator();
	menuFile->Append(wxID_EXIT);

	auto menuHelp = std::make_unique<wxMenu>();
	menuHelp->Append(wxID_ABOUT);

	auto menuBar = std::make_unique<wxMenuBar>();
	menuBar->Append(menuFile.release(), "&File");
	menuBar->Append(menuHelp.release(), "&Help");
	SetMenuBar(menuBar.release());
	CreateStatusBar();
	SetStatusText("Welcome to Simple Cacli !");
}
void CalcMainFrame::OnExit(wxCommandEvent& event)
{
	Close(true);
}
void CalcMainFrame::OnAbout(wxCommandEvent& event)
{
	wxMessageBox("This is a Simple Calci App",
		"About Simple Calculator", wxOK | wxICON_INFORMATION);
}
void CalcMainFrame::OnHello(wxCommandEvent& event)
{
	wxLogMessage("Hello world from Shanky!");
}