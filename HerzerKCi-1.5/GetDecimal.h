#pragma once
#include <bitset>
#include "IBaseCommand.h"

class GetDecimal : public IBaseCommand
{
public:
	void Command(double& baseNumber, double& firstNumber, std::string& mathResult)
	{
		mathResult = " = " + std::to_string(baseNumber);
	}
	void Execute(double& _baseNumber, double& _firstNumber, std::string& _mathResult)
	{
		Command(_baseNumber, _firstNumber, _mathResult);
	}
};