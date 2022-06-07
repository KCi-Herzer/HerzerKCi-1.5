#include "CalculatorApp.h"

wxIMPLEMENT_APP(CalculatorApp);

bool CalculatorApp::OnInit()
{
    frame1 = new mainFrame();
    frame1->Show();

    return true;
}