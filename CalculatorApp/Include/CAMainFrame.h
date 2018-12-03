/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CAMainFrame.h
 * Author: shashank
 *
 * Created on 2 December, 2018, 9:33 PM
 */

#ifndef CAMAINFRAME_H
#define CAMAINFRAME_H

class CAMainFrameIf {
public: 
    virtual void draw()=0;
    virtual ~CAMainFrameIf(){};
};

class CalcMainFrame : public CAMainFrameIf, public wxFrame {
public:
    CalcMainFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
    virtual void draw();
private:
    void OnHello(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    wxDECLARE_EVENT_TABLE();
};

#endif /* CAMAINFRAME_H */

