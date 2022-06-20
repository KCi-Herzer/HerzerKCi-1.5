#include "mainFrame.h"
#include <string>
#include "ButtonFactory.h"
#include <sstream>
#include "CalculatorProcessor.h"

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
	delete processor;
}

void mainFrame::OnButtonClicked(wxCommandEvent& click)
{
	processor = CalculatorProcessor::GetInstance();
	//CalculatorProcessor* processor = CalculatorProcessor::GetInstance();
	//Get Cord. of button in the field
	int x = (click.GetId() - 10000) % buttonFactory->buttonSizerRows;
	int y = (click.GetId() - 10000) / buttonFactory->buttonSizerRows;
	int buttonID = buttonFactory->calcButtons[y * buttonFactory->buttonSizerRows + x]->GetId() - 10000;
	std::string result = "";

#pragma region Updating the TextBox
	//calcText = calcText + buttonFactory->calcButtons[y * buttonFactory->buttonSizerRows + x]->GetLabelText();
	//calcText = calcText + std::to_string(buttonFactory->calcButtons[y * buttonFactory->buttonSizerRows + x]->GetId());

	//Update the textBox
	textBox->AppendText(buttonFactory->calcButtons[y * buttonFactory->buttonSizerRows + x]->GetLabelText());
	
	//textBox->AppendText(std::to_string(buttonID)); //Gets the ID of the button //Used for testing
	//wxString lable = buttonFactory->calcButtons[y * buttonFactory->buttonSizerRows + x]->GetLabelText(); //Used for testing
	//wxMessageBox("Button Clicked (" + calcButtons[y * buttonSizerRows + x]->GetLabelText() + ")"); //Used for testing
#pragma endregion

#pragma region Using the Processor to do math things
	//make the baseNumber
	//TODO: ensure that a number was pressed

	/// <summary>
	/// So if any number was pressed I update the baseNumber, if I press an operator I store the first number then when I click "=" i make the math happen.
	/// Everytime we call Do math it will return text to be printed.
	/// </summary>
	/// <param name="click"></param>
	
	if (buttonID == 12 || buttonID == 13 || buttonID == 14 || buttonID == 15 || buttonID == 16) //Operations that need to take a second number, i.e. 2+2.
	{
		processor->SetFirstNumber();
		processor->SetOperationId(buttonID);
	}
	else if (buttonID == 17 || buttonID == 18 || buttonID == 19 || buttonID == 20 || buttonID == 21) //Operations that dont need to take a second number, i.e. 52hex.
	{
		processor->SetOperationId(buttonID);
		result = processor->DoMath();
		textBox->AppendText(result);
	}
	else if (buttonID == 23) //The equals button. Do math for the 2 number operations
	{
		result = processor->DoMath();
		textBox->AppendText(result);
	}
	else
	{
		processor->SetBaseNumber(ConvertToIntiger(buttonFactory->calcButtons[y * buttonFactory->buttonSizerRows + x]->GetLabelText()));
	}
	
#pragma region Old Implementation
	//if (buttonFactory->calcButtons[y * buttonFactory->buttonSizerRows + x]->GetId() == 10018) //If "+" was clicked
	//{
	//	processor->SetFirstNumber();
	//	//firstNumber = textBaseNumber; //old implementation
	//	//textBaseNumber = 0; //old implementation
	//}
	//else if (buttonFactory->calcButtons[y * buttonFactory->buttonSizerRows + x]->GetId() == 10023) //If "=" was clicked
	//{
	//	textBaseNumber = firstNumber + textBaseNumber;
	//	textBox->AppendText(std::to_string(textBaseNumber));
	//}
	//else //store the numbers inside the processor
	//{
	//	//textBaseNumber = (textBaseNumber * 10) + ConvertToIntiger(buttonFactory->calcButtons[y * buttonFactory->buttonSizerRows + x]->GetLabelText()); //old implementation

	//}


	//->AppendText(std::to_string(textBaseNumber)); //Used for testing
#pragma endregion

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



