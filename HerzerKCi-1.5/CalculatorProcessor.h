#pragma once
#include <string>
#include "mainFrame.h"

class CalculatorProcessor
{
private:
	CalculatorProcessor() {}
	static CalculatorProcessor* _processor;
	int firstNumber = 0;
	int baseNumber = 0;
	int operationId = 0;
	
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

	std::string DoMath() //Maybe I could pass in the Id
	{
		//TODO: make the numbers doubles so we can have decimals
		switch (operationId)
		{
		case 12:
			Add();
			break;
		case 13:
			Subtract();
			break;
		case 14:
			Multiply();
			break;
		case 15:
			Divide();
			break;
		case 16:
			Mod();
			break;
		case 17:
			//"hex"
			break;
		case 18:
			//"C"
			break;
		case 19:
			//"-/+"
			break;
		case 20:
			//"bin"
			break;
		case 21:
			//"dec"
			break;
		case 23:
			//"="
			break;
		default:
			break;
		}
		return std::to_string(baseNumber);
	}
	
#pragma region Two number Operators
	void Add()
	{
		baseNumber = firstNumber + baseNumber;
	}

	void Subtract()
	{
		baseNumber = firstNumber - baseNumber;
	}

	void Multiply()
	{
		baseNumber = firstNumber * baseNumber;
	}

	void Divide()
	{
		baseNumber = firstNumber / baseNumber;
	}

	void Mod()
	{
		baseNumber = firstNumber % baseNumber;
	}
#pragma endregion

#pragma region Single number Operators

	std::string GetDecimal()
	{
		return std::to_string(baseNumber);
	}

	std::string GetHexadecimal()
	{
		std::string result = "";
		int number = baseNumber;
		while (number > 0)
		{
			int mod = number % 16;
			if (mod < 10)
			{
				result = std::to_string(mod) + result;
			}
			else if (mod == 10)
			{
				result = "A" + result;
			}
			else if (mod == 11)
			{
				result = "B" + result;
			}
			else if (mod == 12)
			{
				result = "C" + result;
			}
			else if (mod == 13)
			{
				result = "D" + result;
			}
			else if (mod == 14)
			{
				result = "E" + result;
			}
			else if (mod == 15)
			{
				result = "F" + result;
			}
			number = number / 16;
		}
		result = "0x" + result;
		return result;
	}

	std::string GetBinary()
	{
		std::string result = "";
		int number = baseNumber;
		for (int i = 0; i < 32; i++)
		{
			if (baseNumber % 2 == 0)
			{
				result = "0" + result;
			}
			else
			{
				result = "1" + result;
			}
			number = number / 2;
		}

		return result;
	}
#pragma endregion


	
};

CalculatorProcessor* CalculatorProcessor::_processor = nullptr;

