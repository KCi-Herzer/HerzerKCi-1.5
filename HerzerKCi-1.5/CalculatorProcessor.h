#pragma once
#include <string>

class CalculatorProcessor
{
private:
	static CalculatorProcessor* _processor;
	int baseNumber;
	CalculatorProcessor() {}
public:
	static CalculatorProcessor* GetInstance(); //Most important part of a singleton
	void SetBaseNumber(int _baseNumber);

	CalculatorProcessor(CalculatorProcessor& other) = delete; //Makes it so we can't call the copy constructor
	void operator = (const CalculatorProcessor& other) = delete;

	std::string GetHexadecimal();
	std::string GetBinary();
};

