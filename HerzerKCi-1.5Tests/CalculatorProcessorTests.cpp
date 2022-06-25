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
			double testNumber = 45;
			std::string testString = std::to_string(testNumber);
			testProcessor->SetOperationId(0);
			Assert::AreEqual(testString, testProcessor->DoMath());
		}
		TEST_METHOD(TestTwoPlusTwo)
		{
			testProcessor->ResetProcessor();
			testProcessor->SetBaseNumber(2);
			testProcessor->SetFirstNumber();
			testProcessor->SetBaseNumber(2);
			testProcessor->SetOperationId(12);
			double testNumber = 4;
			std::string testString = std::to_string(testNumber);
			Assert::AreEqual(testString, testProcessor->DoMath());
		}
		TEST_METHOD(Test432Minus400)
		{
			testProcessor->ResetProcessor();
			testProcessor->SetBaseNumber(4);
			testProcessor->SetBaseNumber(3);
			testProcessor->SetBaseNumber(2);
			testProcessor->SetFirstNumber();
			testProcessor->SetBaseNumber(4);
			testProcessor->SetBaseNumber(0);
			testProcessor->SetBaseNumber(0);
			testProcessor->SetOperationId(13);
			double testNumber = 32;
			std::string testString = std::to_string(testNumber);
			Assert::AreEqual(testString, testProcessor->DoMath());
		}
		TEST_METHOD(Test17Times38)
		{
			testProcessor->ResetProcessor();
			testProcessor->SetBaseNumber(1);
			testProcessor->SetBaseNumber(7);
			testProcessor->SetFirstNumber();
			testProcessor->SetBaseNumber(3);
			testProcessor->SetBaseNumber(8);
			testProcessor->SetOperationId(14);
			double testNumber = 646;
			std::string testString = std::to_string(testNumber);
			Assert::AreEqual(testString, testProcessor->DoMath());
		}
		TEST_METHOD(Test400Div80)
		{
			testProcessor->ResetProcessor();
			testProcessor->SetBaseNumber(4);
			testProcessor->SetBaseNumber(0);
			testProcessor->SetBaseNumber(0);
			testProcessor->SetFirstNumber();
			testProcessor->SetBaseNumber(8);
			testProcessor->SetBaseNumber(0);
			testProcessor->SetOperationId(15);
			double testNumber = 5;
			std::string testString = std::to_string(testNumber);
			Assert::AreEqual(testString, testProcessor->DoMath());
		}
		TEST_METHOD(Test942Mod12)
		{
			testProcessor->ResetProcessor();
			testProcessor->SetBaseNumber(9);
			testProcessor->SetBaseNumber(4);
			testProcessor->SetBaseNumber(2);
			testProcessor->SetFirstNumber();
			testProcessor->SetBaseNumber(1);
			testProcessor->SetBaseNumber(2);
			testProcessor->SetOperationId(16);
			double testNumber = 6;
			std::string testString = std::to_string(testNumber);
			Assert::AreEqual(testString, testProcessor->DoMath());
		}
		TEST_METHOD(Test942asHex)
		{
			testProcessor->ResetProcessor();
			testProcessor->SetBaseNumber(9);
			testProcessor->SetBaseNumber(4);
			testProcessor->SetBaseNumber(2);
			testProcessor->SetOperationId(17);
			std::string testString = " = 0x3AE";
			Assert::AreEqual(testString, testProcessor->DoMath());
		}
		TEST_METHOD(Test7854asHex)
		{
			testProcessor->ResetProcessor();
			testProcessor->SetBaseNumber(7);
			testProcessor->SetBaseNumber(8);
			testProcessor->SetBaseNumber(5);
			testProcessor->SetBaseNumber(4);
			testProcessor->SetOperationId(17);
			std::string testString = " = 0x1EAE";
			Assert::AreEqual(testString, testProcessor->DoMath());
		}
		TEST_METHOD(Test2319asBin)
		{
			testProcessor->ResetProcessor();
			testProcessor->SetBaseNumber(2);
			testProcessor->SetBaseNumber(3);
			testProcessor->SetBaseNumber(1);
			testProcessor->SetBaseNumber(9);
			testProcessor->SetOperationId(20);
			std::string testString = " = 00000000000000000000100100001111";
			Assert::AreEqual(testString, testProcessor->DoMath());
		}
		TEST_METHOD(Test1738asBin)
		{
			testProcessor->ResetProcessor();
			testProcessor->SetBaseNumber(1);
			testProcessor->SetBaseNumber(7);
			testProcessor->SetBaseNumber(3);
			testProcessor->SetBaseNumber(8);
			testProcessor->SetOperationId(20);
			std::string testString = " = 00000000000000000000011011001010";
			Assert::AreEqual(testString, testProcessor->DoMath());
		}
	};
}
