#include "mainFrame.h"

wxBEGIN_EVENT_TABLE(mainFrame, wxFrame)
//
wxEND_EVENT_TABLE()

mainFrame::mainFrame() : wxFrame(nullptr, wxID_ANY, "Calculator", wxPoint(560, 240), wxSize(540, 495))
{
	
}

mainFrame::~mainFrame()
{
	
}



