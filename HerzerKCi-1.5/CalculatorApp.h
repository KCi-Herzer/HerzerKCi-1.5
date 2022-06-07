#pragma once
#include "wx/wx.h"
#include "mainFrame.h"

class CalculatorApp : public wxApp
{
public:
	virtual bool OnInit();

private:
	mainFrame* frame1 = nullptr;
};