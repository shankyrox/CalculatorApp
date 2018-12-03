/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "CAMainFrame.h"
#include "CalculatorApp.h"

enum class MenuID {
    ID_Hello = 1
};

wxBEGIN_EVENT_TABLE(CalcMainFrame, wxFrame)
EVT_MENU(static_cast<int> (MenuID::ID_Hello), CalcMainFrame::OnHello)
EVT_MENU(wxID_EXIT, CalcMainFrame::OnExit)
EVT_MENU(wxID_ABOUT, CalcMainFrame::OnAbout)
wxEND_EVENT_TABLE()

CalcMainFrame::CalcMainFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
: wxFrame(NULL, wxID_ANY, title, pos, size)  {
    std::unique_ptr<wxMenu> menuFile = std::make_unique<wxMenu>();
    //wxMenu *menuFile = new wxMenu;
    menuFile->Append(static_cast<int> (MenuID::ID_Hello), "&Hello...\tCtrl-H",
            "Help string shown in status bar for this menu item");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);

    std::unique_ptr<wxMenu> menuHelp = std::make_unique<wxMenu>();
    //wxMenu* menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);

    std::unique_ptr<wxMenuBar> menuBar = std::make_unique<wxMenuBar>();
    //wxMenuBar* menuBar = new wxMenuBar;
    menuBar->Append(menuFile.release(), "&File");
    menuBar->Append(menuHelp.release(), "&Help");
    SetMenuBar(menuBar.release());
    CreateStatusBar();
    SetStatusText("Welcome to Simple Cacli !");
    
    std::unique_ptr<Button> button = std::make_unique<CAwxButton1>(this, "Test");
}

void CalcMainFrame::OnExit(wxCommandEvent& event) {
    Close(true);
}

void CalcMainFrame::OnAbout(wxCommandEvent& event) {
    wxMessageBox("This is a Simple Calci App",
            "About Simple Calculator", wxOK | wxICON_INFORMATION);
}

void CalcMainFrame::OnHello(wxCommandEvent& event) {
    wxLogMessage("Hello world from Shanky!");
}
