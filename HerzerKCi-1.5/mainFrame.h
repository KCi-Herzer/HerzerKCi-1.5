#pragma once
#include "wx/wx.h"
#include "string"

class mainFrame : public wxFrame
{
public:
	mainFrame();
	~mainFrame();
	wxTextCtrl* textBox = nullptr;
	std::string calcText = "";

	
	
	//void OnButtonClicked(wxCommandEvent & click);

};