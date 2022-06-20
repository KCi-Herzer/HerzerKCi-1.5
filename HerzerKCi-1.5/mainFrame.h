#pragma once
#include "wx/wx.h"
#include "string"

class CalculatorProcessor;
class ButtonFactory; //This is a forward declaration
class mainFrame : public wxFrame
{
public:
	
	mainFrame();
	~mainFrame();
	wxTextCtrl* textBox = nullptr;
	ButtonFactory* buttonFactory;
	CalculatorProcessor* processor;
	
	void OnButtonClicked(wxCommandEvent & click);

};