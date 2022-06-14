#pragma once
#include "wx/wx.h".
#include "string"

class mainFrame : public wxFrame
{
public:
	mainFrame();
	~mainFrame();
	wxTextCtrl* textBox = nullptr;
	std::string calcText = "";

	//tomove to fac
	/*wxButton** calcButtons;
	int buttonSizerRows = 4;
	int buttonSizerCols = 6;*/
	
	//void OnButtonClicked(wxCommandEvent & click);

};