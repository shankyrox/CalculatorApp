/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CalculatorApp.h
 * Author: shashank
 *
 * Created on 1 December, 2018, 2:14 AM
 */

#ifndef CALCULATORAPP_H
#define CALCULATORAPP_H

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include <memory>
#include <queue>

class IdGenerator {
private :
    static int count;
    static std::queue<int> available_ids;
    int curr_id;
    IdGenerator(const IdGenerator&) = delete;
    IdGenerator& operator=(const IdGenerator&) = delete;
    IdGenerator(IdGenerator&& ) = delete;
    IdGenerator& operator=(IdGenerator&& ) = delete;
    
protected:
    IdGenerator();
    virtual ~IdGenerator();
    int getId() { return curr_id; }
};


#endif /* CALCULATORAPP_H */

