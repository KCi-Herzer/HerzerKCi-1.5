#pragma once
#include <string>

class CalculatorProcessor
{
private:
	CalculatorProcessor() {}
	static CalculatorProcessor* _processor;
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

	void SetBaseNumber(int _baseNumber)
	{
		baseNumber = _baseNumber;
	}

	CalculatorProcessor(CalculatorProcessor& other) = delete; //Makes it so we can't call the copy constructor
	void operator = (const CalculatorProcessor& other) = delete;
	
	std::string GetDecimal()
	{
		return std::to_string(baseNumber);
	}

	std::string GetHexadecimal()
	{
		return std::string();
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

