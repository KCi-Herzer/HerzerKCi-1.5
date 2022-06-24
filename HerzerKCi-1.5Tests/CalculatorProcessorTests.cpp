#include "pch.h"
#include "CppUnitTest.h"
#include "../HerzerKCi-1.5/CalculatorProcessor.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace HerzerKCi15Tests
{
	TEST_CLASS(CalculatorProcessorTests)
	{
	public:
		CalculatorProcessor* testProcessor = CalculatorProcessor::GetInstance();
		TEST_METHOD(TestMethod1)
		{

		}
	};
}
