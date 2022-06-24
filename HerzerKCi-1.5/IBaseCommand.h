#pragma once
class IBaseCommand
{
	//abstract base class
	//contain at least one pure virtual function
	//That function will be called execute
	//The execute function will be responsible for running the command's logic
	//All operands (+,-,*,/) will create a different command (AddCommand, SubtractCommand) 
	//that will be stored in a vector inside the CalculatorProcessor
	virtual void Execute(double & _baseNumber) = 0;
	//needs to pass the base number by reff maybe
};

