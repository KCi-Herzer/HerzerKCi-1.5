#pragma once
#include "wx/wx.h"
#include "string"

class ButtonFactory; //This is a forward declaration
class mainFrame : public wxFrame
{
public:
	
	mainFrame();
	~mainFrame();
	wxTextCtrl* textBox = nullptr;
	std::string calcText = "";
	ButtonFactory* buttonFactory;
	int textBaseNumber = 0;
	int firstNumber = 0;
	
	void OnButtonClicked(wxCommandEvent & click);

};