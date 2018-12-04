/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "CAMainFrame.h"
#include "Button.h"

enum class MenuID {
    ID_Hello = 1
};

wxBEGIN_EVENT_TABLE(CalcMainFrame, wxFrame)
EVT_MENU(static_cast<int> (MenuID::ID_Hello), CalcMainFrame::OnHello)
EVT_MENU(wxID_EXIT, CalcMainFrame::OnExit)
EVT_MENU(wxID_ABOUT, CalcMainFrame::OnAbout)
wxEND_EVENT_TABLE()

CalcMainFrame::CalcMainFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
: wxFrame(NULL, wxID_ANY, title, pos, size)  { }

void CalcMainFrame::draw() {
    // Menu Bar Items
    std::unique_ptr<wxMenu> menuFile = std::make_unique<wxMenu>();
    menuFile->Append(static_cast<int> (MenuID::ID_Hello), "&Hello...\tCtrl-H",
            "Help string shown in status bar for this menu item");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);
    std::unique_ptr<wxMenu> menuHelp = std::make_unique<wxMenu>();
    menuHelp->Append(wxID_ABOUT);

    // Menu Bar 
    std::unique_ptr<wxMenuBar> menuBar = std::make_unique<wxMenuBar>();
    menuBar->Append(menuFile.release(), "&File");
    menuBar->Append(menuHelp.release(), "&Help");
    SetMenuBar(menuBar.release());
    
    // Status Bar 
    CreateStatusBar();
    SetStatusText("Welcome to Simple Cacli !");
    
    // Seems like a case for composite pattern 
    // Buttons
    int border_val = 2;
    wxBoxSizer* fulldisplay = new wxBoxSizer(wxVERTICAL);
    fulldisplay->Add(new wxTextCtrl(this, -1, "", wxPoint(-1, -1), wxSize(-1, -1), wxTE_RIGHT), \
            0, wxEXPAND | wxALL, border_val);
    
    wxBoxSizer* first_column = new wxBoxSizer(wxVERTICAL);
    
    first_column->Add((new CAwxButton1(this, "7"))->getWxButtonPtr(), 0, wxEXPAND | wxALL, border_val);
    first_column->Add((new CAwxButton1(this, "4"))->getWxButtonPtr(), 0, wxEXPAND | wxALL, border_val);
    first_column->Add((new CAwxButton1(this, "1"))->getWxButtonPtr(), 0, wxEXPAND | wxALL, border_val);
    first_column->Add((new CAwxButton1(this, "0"))->getWxButtonPtr(), 0, wxEXPAND | wxALL, border_val);
    
    wxBoxSizer* second_column = new wxBoxSizer(wxVERTICAL);
    second_column->Add((new CAwxButton1(this, "8"))->getWxButtonPtr(), 0, wxEXPAND | wxALL, border_val);
    second_column->Add((new CAwxButton1(this, "5"))->getWxButtonPtr(), 0, wxEXPAND | wxALL, border_val);
    second_column->Add((new CAwxButton1(this, "2"))->getWxButtonPtr(), 0, wxEXPAND | wxALL, border_val);
    second_column->Add((new CAwxButton1(this, "."))->getWxButtonPtr(), 0, wxEXPAND | wxALL, border_val);
    
    wxBoxSizer* third_column = new wxBoxSizer(wxVERTICAL);
    third_column->Add((new CAwxButton1(this, "9"))->getWxButtonPtr(), 0, wxEXPAND | wxALL, border_val);
    third_column->Add((new CAwxButton1(this, "6"))->getWxButtonPtr(), 0, wxEXPAND | wxALL, border_val);
    third_column->Add((new CAwxButton1(this, "3"))->getWxButtonPtr(), 0, wxEXPAND | wxALL, border_val);
    third_column->Add((new CAwxButton1(this, "%"))->getWxButtonPtr(), 0, wxEXPAND | wxALL, border_val);
    
    wxBoxSizer* fourth_column = new wxBoxSizer(wxVERTICAL);
    fourth_column->Add((new CAwxButton1(this, "/"))->getWxButtonPtr(), 0, wxEXPAND | wxALL, border_val);  // correct text for this
    fourth_column->Add((new CAwxButton1(this, "x"))->getWxButtonPtr(), 0, wxEXPAND | wxALL, border_val);
    fourth_column->Add((new CAwxButton1(this, "-"))->getWxButtonPtr(), 0, wxEXPAND | wxALL, border_val);
    fourth_column->Add((new CAwxButton1(this, "+"))->getWxButtonPtr(), 0, wxEXPAND | wxALL, border_val);
    
    wxBoxSizer* fifth_column = new wxBoxSizer(wxVERTICAL);
    fifth_column->Add((new CAwxButton1(this, "<-"))->getWxButtonPtr(), 0, wxEXPAND | wxALL, border_val);
    fifth_column->Add((new CAwxButton1(this, "("))->getWxButtonPtr(),  0, wxEXPAND | wxALL, border_val);
    fifth_column->Add((new CAwxButton1(this, "x^2"))->getWxButtonPtr(),0, wxEXPAND | wxALL, border_val);
    
    wxBoxSizer* sixth_column = new wxBoxSizer(wxVERTICAL);
    sixth_column->Add((new CAwxButton1(this, "C"))->getWxButtonPtr(), 0, wxEXPAND | wxALL, border_val);
    sixth_column->Add((new CAwxButton1(this, ")"))->getWxButtonPtr(), 0, wxEXPAND | wxALL, border_val);
    sixth_column->Add((new CAwxButton1(this, "^/"))->getWxButtonPtr(), 0, wxEXPAND | wxALL, border_val);

    wxBoxSizer* last_columns = new wxBoxSizer(wxHORIZONTAL);
    last_columns->Add(fifth_column, 0, wxEXPAND);
    last_columns->Add(sixth_column, 0, wxEXPAND);
    
    wxBoxSizer* composite_column = new wxBoxSizer(wxVERTICAL);
    composite_column->Add(last_columns, 0, wxEXPAND, 0);
    composite_column->Add((new CAwxButton1(this, "="))->getWxButtonPtr(), 0, wxEXPAND|wxALL, border_val);
    
    wxFlexGridSizer* buttonsContainer = new wxFlexGridSizer(5, 0, 0);
    buttonsContainer->Add(first_column, 0, 0);
    buttonsContainer->Add(second_column, 0, 0);
    buttonsContainer->Add(third_column, 0, 0);
    buttonsContainer->Add(fourth_column, 0, 0);
    buttonsContainer->Add(composite_column, 0, 0);
    
    fulldisplay->Add(buttonsContainer, 0, wxEXPAND);
    SetSizerAndFit(fulldisplay);
    
    wxFrame::Show(true);
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
