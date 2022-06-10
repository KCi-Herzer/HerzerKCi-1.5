#include "mainFrame.h"

wxBEGIN_EVENT_TABLE(mainFrame, wxFrame)
//
wxEND_EVENT_TABLE()

mainFrame::mainFrame() : wxFrame(nullptr, wxID_ANY, "Calculator", wxPoint(560, 240), wxSize(540, 495))
{
	textBox = new wxTextCtrl(this, wxID_ANY, "0", wxPoint(wxDefaultPosition), wxSize(560, 90), wxTE_READONLY);	//
	textBox->SetAutoLayout(true);
	/*wxFo
	textBox->SetFont*/
	calcButtons = new wxButton * [buttonsX * buttonsY];
	wxGridSizer* buttonSizer = new wxGridSizer(buttonsX, buttonsY, 0, 0);
	wxFlexGridSizer* calcSizer = new wxFlexGridSizer(1);
	
	for (int x = 0; x < buttonsX; x++)
	{
		for (int y = 0; y < buttonsY; y++)
		{
			calcButtons[y * buttonsX + x] = new wxButton(this, 10000 + (y * buttonsX + x));
			buttonSizer->Add(calcButtons[y * buttonsX + x], 1, wxEXPAND | wxALL);
		}
	}
	/*this->SetSizer(buttonSizer);
	buttonSizer->Layout();*/
	calcSizer->AddGrowableCol(0);
	calcSizer->AddGrowableRow(1);
	calcSizer->Add(textBox, 1, wxEXPAND | wxALL);
	calcSizer->Add(buttonSizer, 1, wxEXPAND | wxALL);
	this->SetSizer(calcSizer);
	calcSizer->Layout();
}

mainFrame::~mainFrame()
{
	
}



