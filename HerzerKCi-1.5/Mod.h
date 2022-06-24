#pragma once
#include "IBaseCommand.h"
#include <cmath>

class Mod : public IBaseCommand
{
public:
	void Command(double& baseNumber, double& firstNumber, std::string& mathResult)
	{
		baseNumber = std::fmod(firstNumber, baseNumber);
		mathResult = std::to_string(baseNumber);
	}
	void Execute(double& _baseNumber, double& _firstNumber, std::string& _mathResult)
	{
		Command(_baseNumber, _firstNumber, _mathResult);
	}
};