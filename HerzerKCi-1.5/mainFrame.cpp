#include "mainFrame.h"
#include <string>

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

#pragma region Other Initializations
	calcButtons = new wxButton * [buttonsX * buttonsY];
	wxGridSizer* buttonSizer = new wxGridSizer(buttonsX, buttonsY, 0, 0);
	wxFlexGridSizer* calcSizer = new wxFlexGridSizer(1);
#pragma endregion

#pragma region Buttons
	//Nested for loops to create the buttons
	for (int x = 0; x < buttonsX; x++)
	{
		for (int y = 0; y < buttonsY; y++)
		{
			calcButtons[y * buttonsX + x] = new wxButton(this, 10000 + (y * buttonsX + x));
			buttonSizer->Add(calcButtons[y * buttonsX + x], 1, wxEXPAND | wxALL);

			//Need to bind the buttons to an event here
			calcButtons[y * buttonsX + x]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &mainFrame::OnButtonClicked, this);
		}
	}

	//Disableing unneeded buttons
	calcButtons[3]->Disable();
	calcButtons[11]->Disable();
	calcButtons[22]->Disable();

	//Assigning lables to buttons
	std::vector <std::string> lables = { "7", "4", "1", "", "8", "5", "2", "0", "9", "6", "3", "", 
		"C", "-/+", "*", "/", "mod", "hex", "+", "-", "bin", "dec",  "", "=" };
	for (int i = 0; i < 24; i++)
	{
		calcButtons[i]->SetLabel(lables[i]);
	}

	//TODO: Make lable size dinamic based on how much text is in the box

#pragma endregion

#pragma region Sizers
	calcSizer->AddGrowableCol(0);
	calcSizer->AddGrowableRow(1);
	calcSizer->Add(textBox, 1, wxEXPAND | wxALL);
	calcSizer->Add(buttonSizer, 1, wxEXPAND | wxALL);
	this->SetSizer(calcSizer);
	calcSizer->Layout();
#pragma endregion
}

mainFrame::~mainFrame()
{
	//TODO: Clean memory leaks
}

void mainFrame::OnButtonClicked(wxCommandEvent& click)
{
	

	//Get Cord. of button in the field
	int x = (click.GetId() - 10000) % buttonsX;
	int y = (click.GetId() - 10000) / buttonsX;

	calcText = calcText + calcButtons[y * buttonsX + x]->GetLabelText();
	//wxMessageBox("Button Clicked (" + calcButtons[y * buttonsX + x]->GetLabelText() + ")"); //Used for testing
	
	//I need to update the textBox to show the new calc text
	textBox->AppendText(calcButtons[y * buttonsX + x]->GetLabelText());

	//Need to handel the following
	click.Skip();
}



