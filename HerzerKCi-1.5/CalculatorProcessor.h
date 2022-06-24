#pragma once
#include <string>
#include <vector>
#include "mainFrame.h"
#include "IBaseCommand.h"
#include "Add.h"
#include "Subtract.h"
#include "Multiply.h"
#include "Divide.h"
#include "Mod.h"
#include "GetHexadecimal.h"
#include "Invert.h"
#include "GetBinary.h"
#include "GetDecimal.h"


class CalculatorProcessor
{
private:
	CalculatorProcessor() 
	{
		commands.push_back(&add);
		commands.push_back(&sub);
		commands.push_back(&mult);
		commands.push_back(&div);
		commands.push_back(&mod);
		commands.push_back(&hex);
		commands.push_back(&inv);
		commands.push_back(&bin);
		commands.push_back(&dec);
	}
	static CalculatorProcessor* _processor;
	double firstNumber = 0;
	double baseNumber = 0;
	int operationId = 0;
	std::string mathResult;

#pragma region Commands
	std::vector<IBaseCommand*> commands;
	Add add;
	Subtract sub;
	Multiply mult;
	Divide div;
	Mod mod;
	GetHexadecimal hex;
	Invert inv;
	GetBinary bin;
	GetDecimal dec;
#pragma endregion
	
public:
	static CalculatorProcessor* GetInstance() //Most important part of a singleton
	{
		if (_processor == nullptr)
		{
			_processor = new CalculatorProcessor();
		}
		return _processor;
	}

	void SetBaseNumber(int _numToAdd)
	{
		baseNumber = (baseNumber * 10) + _numToAdd;
	}

	void ResetProcessor() 
	{
		baseNumber = 0;
		firstNumber = 0;
		operationId = 0;
		mathResult = "";
	}

	void SetFirstNumber() 
	{
		firstNumber = baseNumber;
		baseNumber = 0;
	}

	void SetOperationId(int _operationId) 
	{
		operationId = _operationId;
	}

	CalculatorProcessor(CalculatorProcessor& other) = delete; //Makes it so we can't call the copy constructor
	void operator = (const CalculatorProcessor& other) = delete;

	std::string DoMath()
	{
		//TODO: add decimal percision to remove trailing 0's
		
		switch (operationId)
		{
		case 12:
			commands[0]->Execute(baseNumber, firstNumber, mathResult); //Add
			break;
		case 13:
			commands[1]->Execute(baseNumber, firstNumber, mathResult); //Subtract
			break;
		case 14:
			commands[2]->Execute(baseNumber, firstNumber, mathResult); //Multiply
			break;
		case 15:
			commands[3]->Execute(baseNumber, firstNumber, mathResult); //Divide
			break;
		case 16:
			commands[4]->Execute(baseNumber, firstNumber, mathResult); //Mod
			break;
		case 17:
			commands[5]->Execute(baseNumber, firstNumber, mathResult); //Hex
			break;
		case 19:
			commands[6]->Execute(baseNumber, firstNumber, mathResult); //Invert
			break;
		case 20:
			commands[7]->Execute(baseNumber, firstNumber, mathResult); //Bin
			break;
		case 21:
			commands[8]->Execute(baseNumber, firstNumber, mathResult); //Dec
			break;
		default:
			mathResult = std::to_string(baseNumber);
			break;
		}
		operationId = 0;
		return mathResult;
	}
	
};

CalculatorProcessor* CalculatorProcessor::_processor = nullptr;

