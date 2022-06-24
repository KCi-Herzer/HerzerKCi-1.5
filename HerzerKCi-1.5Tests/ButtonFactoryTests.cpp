#include "pch.h"
#include "CppUnitTest.h"

#include "../HerzerKCi-1.5/ButtonFactory.h"




using namespace Microsoft::VisualStudio::CppUnitTestFramework;
class mainFrame;
namespace HerzerKCi15Tests
{
	TEST_CLASS(ButtonFactoryTests)
	{
	public:
		mainFrame* testFrame = new mainFrame();
		ButtonFactory* testFactory = new ButtonFactory();
		TEST_METHOD(EnsureCorrectAmountOfButtonsAreMade) //1
		{
			testFactory->CreateButtons(testFrame);
			int numOfButtons = testFactory->buttonSizer->GetItemCount();
			Assert::AreEqual(24, numOfButtons);
		}
		TEST_METHOD(EnsureUnusedButton1IsDisabled) //2
		{
			testFactory->CreateButtons(testFrame);
			Assert::IsFalse(testFactory->calcButtons[3]->IsEnabled());
		}
		TEST_METHOD(EnsureUnusedButton2IsDisabled) //3
		{
			testFactory->CreateButtons(testFrame);
			Assert::IsFalse(testFactory->calcButtons[11]->IsEnabled());
		}
		TEST_METHOD(EnsureUnusedButton3IsDisabled) //4
		{
			testFactory->CreateButtons(testFrame);
			Assert::IsFalse(testFactory->calcButtons[22]->IsEnabled());
		}
		TEST_METHOD(EnsureLableForEqualsIsCorrect) //5
		{
			testFactory->CreateButtons(testFrame);
			Assert::AreEqual("=", testFactory->calcButtons[23]->GetLabelText());
		}
		TEST_METHOD(EnsureLableForHexIsCorrect) //6
		{
			testFactory->CreateButtons(testFrame);
			Assert::AreEqual("(hex)", testFactory->calcButtons[17]->GetLabelText());
		}
		TEST_METHOD(EnsureLableForSevenIsNotOne) //7
		{
			testFactory->CreateButtons(testFrame);
			Assert::AreNotEqual("1", testFactory->calcButtons[0]->GetLabelText());
		}
		TEST_METHOD(EnsureLableForZeroIsNotSeven) //8
		{
			testFactory->CreateButtons(testFrame);
			Assert::AreNotEqual("7", testFactory->calcButtons[7]->GetLabelText());
		}
		TEST_METHOD(EnsureButtonIdOfMinusIsCorrect) //9
		{
			testFactory->CreateButtons(testFrame);
			int buttonId = testFactory->calcButtons[13]->GetId();
			Assert::AreEqual(10013, buttonId);
		}
		TEST_METHOD(EnsureButtonIdOfClearIsCorrect) //10
		{
			testFactory->CreateButtons(testFrame);
			int buttonId = testFactory->calcButtons[18]->GetId();
			Assert::AreEqual(10018, buttonId);
		}
		
	};
}