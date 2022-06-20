#include "ButtonFactory.h"

ButtonFactory::ButtonFactory()
{
	calcButtons = new wxButton * [buttonSizerRows * buttonSizerCols];
	buttonSizer = new wxGridSizer(buttonSizerRows, buttonSizerCols, 0, 0);
}

ButtonFactory::~ButtonFactory()
{
	delete[] calcButtons;
}

void ButtonFactory::CreateButtons(mainFrame* _parent)
{
	//Nested for loops to create the buttons
	for (int x = 0; x < buttonSizerRows; x++)
	{
		for (int y = 0; y < buttonSizerCols; y++)
		{
			calcButtons[y * buttonSizerRows + x] = new wxButton(_parent, 10000 + (y * buttonSizerRows + x));
			buttonSizer->Add(calcButtons[y * buttonSizerRows + x], 1, wxEXPAND | wxALL);

			//Binding the buttons to the click event on the mainFrame.
			calcButtons[y * buttonSizerRows + x]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &mainFrame::OnButtonClicked, _parent);
		}
	}

	//Disableing unneeded buttons
	calcButtons[3]->Disable();
	calcButtons[11]->Disable();
	calcButtons[22]->Disable();

	//Assigning lables to buttons
	std::vector <std::string> lables = { "7", "4", "1", "", "8", "5", "2", "0", "9", "6", "3", "", 
		"+", "-", "*", "/", "mod", "hex", "C", "+/-", "bin", "dec",  "", "=" };
	for (int i = 0; i < 24; i++)
	{
		calcButtons[i]->SetLabel(lables[i]);
	}

	//TODO: Make lable size dinamic based on how much text is in the box
}
