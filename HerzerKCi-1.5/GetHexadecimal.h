#pragma once
#include "IBaseCommand.h"

class GetHexadecimal : public IBaseCommand
{
public:
	void Command(double& baseNumber, double& firstNumber, std::string& mathResult)
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
	void Execute(double& _baseNumber, double& _firstNumber, std::string& _mathResult)
	{
		Command(_baseNumber, _firstNumber, _mathResult);
	}
};