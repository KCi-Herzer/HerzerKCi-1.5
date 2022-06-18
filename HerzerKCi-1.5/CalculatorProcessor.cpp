#include "CalculatorProcessor.h"

CalculatorProcessor* CalculatorProcessor::GetInstance()
{
	if (_processor == nullptr)
	{
		_processor = new CalculatorProcessor();
	}
	return _processor;
}

void CalculatorProcessor::SetBaseNumber(int _baseNumber)
{
	baseNumber = _baseNumber;
}

std::string CalculatorProcessor::GetDecimal()
{
	return std::to_string(baseNumber);
}

std::string CalculatorProcessor::GetHexadecimal()
{
	return std::string();
} 

std::string CalculatorProcessor::GetBinary()
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
