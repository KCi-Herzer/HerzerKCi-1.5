#pragma once
#include "wx/wx.h".
#include "string"

class mainFrame : public wxFrame
{
public:
	mainFrame();
	~mainFrame();
	wxTextCtrl* textBox = nullptr;
	wxButton** calcButtons;
	int buttonsX = 4;
	int buttonsY = 6;
	std::string calcText = "";
	
	void OnButtonClicked(wxCommandEvent & click);

};