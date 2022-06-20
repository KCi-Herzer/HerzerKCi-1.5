#pragma once
#include <string>
#include <bitset>
#include "mainFrame.h"

class CalculatorProcessor
{
private:
	CalculatorProcessor() {}
	static CalculatorProcessor* _processor;
	double firstNumber = 0;
	double baseNumber = 0;
	int operationId = 0;
	std::string mathResult;
	
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
			GetHexadecimal();
			break;
		case 19:
			Invert();
			break;
		case 20:
			GetBinary();
			break;
		case 21:
			GetDecimal();
			break;
		default:
			mathResult = std::to_string(baseNumber);
			break;
		}
		operationId = 0;
		return mathResult;
	}
	
#pragma region Two number Operators
	void Add()
	{
		baseNumber = firstNumber + baseNumber;
		mathResult = std::to_string(baseNumber);
	}

	void Subtract()
	{
		baseNumber = firstNumber - baseNumber;
		mathResult = std::to_string(baseNumber);
	}

	void Multiply()
	{
		baseNumber = firstNumber * baseNumber;
		mathResult = std::to_string(baseNumber);
	}

	void Divide()
	{
		baseNumber = firstNumber / baseNumber;
		mathResult = std::to_string(baseNumber);
	}

	void Mod()
	{
		baseNumber = std::fmod(firstNumber, baseNumber);
		mathResult = std::to_string(baseNumber);
	}
#pragma endregion

#pragma region Single number Operators

	void GetDecimal()
	{
		mathResult = " = " + std::to_string(baseNumber);
	}

	void GetHexadecimal()
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
		mathResult = " = " + result;
	}

	void GetBinary()
	{
		std::string result = std::bitset< 32 >(baseNumber).to_string();
		mathResult = " = " + result;
	}

	void Invert() 
	{
		baseNumber = -baseNumber;
		mathResult = " = " + std::to_string(baseNumber);
	}

#pragma endregion


	
};

CalculatorProcessor* CalculatorProcessor::_processor = nullptr;

