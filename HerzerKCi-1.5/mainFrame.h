#pragma once
#include "wx/wx.h"

class mainFrame : public wxFrame
{
public:
	mainFrame();
	~mainFrame();
	wxTextCtrl* textBox = nullptr;
	wxButton** calcButtons;
	int buttonsX = 4;
	int buttonsY = 6;
	

	wxDECLARE_EVENT_TABLE();
};