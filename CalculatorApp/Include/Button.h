/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Button.h
 * Author: shashank
 *
 * Created on 1 December, 2018, 1:43 AM
 */

#ifndef BUTTON_H
#define BUTTON_H

#include "CalculatorApp.h"

class Button {
public : 
    virtual void setText(std::string text) =0;
    virtual  void draw()=0;
    virtual void hide()=0;
};

class CAwxButton1 : public Button, public IdGenerator {
    wxButton* wx_button;
    wxFrame* frame;
    std::string text;
public:
    CAwxButton1(wxFrame* frame, std::string text);
    virtual void setText(std::string text);
    virtual void draw() override;
    virtual void hide();
    wxButton* getWxButtonPtr();
};

class ButtonDecorator : public Button {
    std::shared_ptr<Button> button_ptr;
public:
    ButtonDecorator(std::shared_ptr<Button> button_ptr);
    virtual void draw();
};

#endif /* BUTTON_H */

