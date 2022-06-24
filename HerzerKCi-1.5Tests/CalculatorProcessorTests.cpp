#include "pch.h"
#include "CppUnitTest.h"
#include <string>
#include "../HerzerKCi-1.5/CalculatorProcessor.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace HerzerKCi15Tests
{
	TEST_CLASS(CalculatorProcessorTests)
	{
	public:
		CalculatorProcessor* testProcessor = CalculatorProcessor::GetInstance();
		TEST_METHOD(EsureSetBaseNumber)
		{
			testProcessor->SetBaseNumber(4);
			testProcessor->SetBaseNumber(5);
			std::string testString = "45";
			testProcessor->SetOperationId(0);
			Assert::AreEqual(testString, testProcessor->DoMath());
		}
		TEST_METHOD(TestMethod2)
		{

		}
		TEST_METHOD(TestMethod3)
		{

		}
		TEST_METHOD(TestMethod4)
		{

		}
		TEST_METHOD(TestMethod5)
		{

		}
		TEST_METHOD(TestMethod6)
		{

		}
		TEST_METHOD(TestMethod7)
		{

		}
		TEST_METHOD(TestMethod8)
		{

		}
		TEST_METHOD(TestMethod9)
		{

		}
		TEST_METHOD(TestMethod10)
		{

		}
	};
}
