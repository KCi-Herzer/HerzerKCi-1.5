#pragma once
#include "wx/wx.h"

class ButtonFactory
{
public:
	wxButton** calcButtons;
	wxGridSizer* buttonSizer;
	int buttonSizerRows = 4;
	int buttonSizerCols = 6;

	ButtonFactory();
	~ButtonFactory();
	void CreateButtons();

	
};

