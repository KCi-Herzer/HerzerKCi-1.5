#pragma once
#include <string>
class IBaseCommand
{
public:
	virtual void Execute(double& _baseNumber, double& _firstNumber, std::string& _mathResult) = 0;
};

