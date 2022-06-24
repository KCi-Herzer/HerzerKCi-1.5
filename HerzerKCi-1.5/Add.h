#pragma once
#include "IBaseCommand.h"

class Add : public IBaseCommand 
{
public:
	void AddCommand(double& baseNumber, double& firstNumber, std::string& mathResult)
	{
		baseNumber = firstNumber + baseNumber;
		mathResult = std::to_string(baseNumber);
	}
	void Execute(double& _baseNumber, double& _firstNumber, std::string& _mathResult)
	{
		AddCommand(_baseNumber, _firstNumber, _mathResult);
	}
};