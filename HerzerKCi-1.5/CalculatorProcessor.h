#pragma once
#include <string>

class CalculatorProcessor
{
private:
	CalculatorProcessor() {}
	static CalculatorProcessor* _processor;
	int firstNumber = 0;
	int baseNumber = 0;
	
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
		baseNumber = _numToAdd;
	}

	CalculatorProcessor(CalculatorProcessor& other) = delete; //Makes it so we can't call the copy constructor
	void operator = (const CalculatorProcessor& other) = delete;
	
	std::string Add(int _secondNumber) 
	{
		baseNumber = baseNumber + _secondNumber;
		return std::to_string(baseNumber);
	}

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
};

CalculatorProcessor* CalculatorProcessor::_processor = nullptr;

