#include "mainFrame.h"
#include <string>
#include "ButtonFactory.h"
#include "CalculatorProcessor.h"
#include <sstream>

int ConvertToIntiger(wxString _toConvert);
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
	delete buttonFactory;
}

void mainFrame::OnButtonClicked(wxCommandEvent& click)
{
	CalculatorProcessor* processor = CalculatorProcessor::GetInstance();

	//Get Cord. of button in the field
	int x = (click.GetId() - 10000) % buttonFactory->buttonSizerRows;
	int y = (click.GetId() - 10000) / buttonFactory->buttonSizerRows;

#pragma region Updating the TextBox
	//calcText = calcText + buttonFactory->calcButtons[y * buttonFactory->buttonSizerRows + x]->GetLabelText();
	calcText = calcText + std::to_string(buttonFactory->calcButtons[y * buttonFactory->buttonSizerRows + x]->GetId());

	//Update the textBox
	textBox->AppendText(buttonFactory->calcButtons[y * buttonFactory->buttonSizerRows + x]->GetLabelText());
	
	//textBox->AppendText(std::to_string(buttonFactory->calcButtons[y * buttonFactory->buttonSizerRows + x]->GetId())); //Gets the ID of the button //Used for testing
	//wxString lable = buttonFactory->calcButtons[y * buttonFactory->buttonSizerRows + x]->GetLabelText(); //Used for testing
	//wxMessageBox("Button Clicked (" + calcButtons[y * buttonSizerRows + x]->GetLabelText() + ")"); //Used for testing
#pragma endregion

#pragma region Using the Processor to do math things
	//make the baseNumber
	//TODO: ensure that a number was pressed
	if (buttonFactory->calcButtons[y * buttonFactory->buttonSizerRows + x]->GetId() == 10018) //If "+" was clicked
	{
		//processor->Add()
		firstNumber = textBaseNumber;
		textBaseNumber = 0;
	}
	else if (buttonFactory->calcButtons[y * buttonFactory->buttonSizerRows + x]->GetId() == 10023) //If "=" was clicked
	{
		textBaseNumber = firstNumber + textBaseNumber;
		textBox->AppendText(std::to_string(textBaseNumber));
	}
	else //store the numbers inside the processor
	{
		textBaseNumber = (textBaseNumber * 10) + ConvertToIntiger(buttonFactory->calcButtons[y * buttonFactory->buttonSizerRows + x]->GetLabelText());
		//processor->SetBaseNumber(ConvertToIntiger(buttonFactory->calcButtons[y * buttonFactory->buttonSizerRows + x]->GetLabelText()));
	}

	
	//->AppendText(std::to_string(textBaseNumber)); //Used for testing

#pragma endregion

	

	

	
	
	
	

	//Need to handel the following
	click.Skip();
}

#pragma region Other Functions
int ConvertToIntiger(wxString _toConvert)
{
	int number = 0;
	std::stringstream ss;
	if (ss << _toConvert)
	{
		if (ss >> number)
		{
			
		}
	}
	return number;
}

#pragma endregion



