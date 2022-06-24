#pragma once
#include <bitset>
#include "IBaseCommand.h"

class GetBinary : public IBaseCommand
{
public:
	void Command(double& baseNumber, double& firstNumber, std::string& mathResult)
	{
		std::string result = std::bitset< 32 >(baseNumber).to_string();
		mathResult = " = " + result;
	}
	void Execute(double& _baseNumber, double& _firstNumber, std::string& _mathResult)
	{
		Command(_baseNumber, _firstNumber, _mathResult);
	}
};