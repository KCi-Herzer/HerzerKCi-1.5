#include "mainFrame.h"
#include <string>
#include "ButtonFactory.h"


mainFrame::mainFrame() : wxFrame(nullptr, wxID_ANY, "Calculator", wxPoint(560, 240), wxSize(540, 495))
{
#pragma region TEXT BOX
	textBox = new wxTextCtrl(this, wxID_ANY, "", wxPoint(wxDefaultPosition), wxSize(560, 90), wxTE_READONLY);
	textBox->SetAutoLayout(true);
	wxFont font(48, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false);
	textBox->SetFont(font);
	//TODO: Make text size dinamic based on how much text is in the box
	//TODO: Make text align to the right of the box
#pragma endregion
	
	buttonFactory = new ButtonFactory();
	buttonFactory->CreateButtons(this);

#pragma region Sizers
	wxFlexGridSizer* calcSizer = new wxFlexGridSizer(1);
	calcSizer->AddGrowableCol(0);
	calcSizer->AddGrowableRow(1);
	calcSizer->Add(textBox, 1, wxEXPAND | wxALL);
	calcSizer->Add(buttonFactory->buttonSizer, 1, wxEXPAND | wxALL);
	this->SetSizer(calcSizer);
	calcSizer->Layout();
#pragma endregion
}

mainFrame::~mainFrame()
{
	//TODO: Clean memory leaks
	delete buttonFactory;
	
}

//void mainFrame::OnButtonClicked(wxCommandEvent& click)
//{
//	
//
//	//Get Cord. of button in the field
//	int x = (click.GetId() - 10000) % buttonSizerRows;
//	int y = (click.GetId() - 10000) / buttonSizerRows;
//
//	calcText = calcText + calcButtons[y * buttonSizerRows + x]->GetLabelText();
//	//wxMessageBox("Button Clicked (" + calcButtons[y * buttonSizerRows + x]->GetLabelText() + ")"); //Used for testing
//	
//	//I need to update the textBox to show the new calc text
//	textBox->AppendText(calcButtons[y * buttonSizerRows + x]->GetLabelText());
//
//	//Need to handel the following
//	click.Skip();
//}



