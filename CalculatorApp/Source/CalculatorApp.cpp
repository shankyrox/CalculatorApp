// wxWidgets "Hello world" Program
// For compilers that support precompilation, includes "wx/wx.h".

#include "CalculatorApp.h"
#include "Button.h"
#include "CAMainFrame.h"

class CalculatorApp : public wxApp {
public:
    virtual bool OnInit();
};

wxIMPLEMENT_APP(CalculatorApp);

bool CalculatorApp::OnInit() {
    CalcMainFrame *frame = new CalcMainFrame("Simple Calculator", wxPoint(-1, -1), wxSize(450, 340));
    frame->Show(true);
    return true;
}

// start IdGenerator
int IdGenerator::count = 1;     // static member of this class 
std::queue<int> IdGenerator::available_ids;

IdGenerator::IdGenerator() {
    if(!available_ids.empty()) {
        curr_id = available_ids.front();
        available_ids.pop();
    }
    else
        curr_id = count;
    count++;
}

IdGenerator::~IdGenerator() {
    available_ids.push(curr_id);
}
