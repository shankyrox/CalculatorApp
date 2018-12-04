/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Button.h"

CAwxButton1::CAwxButton1(wxFrame* frame, std::string text):
        frame(frame), text(text){    
    wx_button = new wxButton(frame, getId(), text);
}

void CAwxButton1::setText(std::string text) {
    
}

void CAwxButton1::draw() {
    // , wxDefaultPosition, wxDefaultSize, 0
}

void CAwxButton1::hide() {
    
}

wxButton* CAwxButton1::getWxButtonPtr() {
    return wx_button;
}

// start ButtonDecorator 
void ButtonDecorator::draw() {
    button_ptr->draw();
}


// end ButtonDecorator 