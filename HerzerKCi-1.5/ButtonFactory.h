#pragma once

class ButtonFactory
{
public:
	ButtonFactory();
	~ButtonFactory();

	void CreateButton();
	//My approach to making the button factory
	//Have mainFrame call it with parameters like
	//What button ie(1-9,or the operators)
	//Have it pass in the parent frame
	// optional: Enabled? default as true
	//jk
};

