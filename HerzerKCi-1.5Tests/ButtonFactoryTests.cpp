#include "pch.h"
#include "CppUnitTest.h"
#include "../HerzerKCi-1.5/mainFrame.h"
#include "../HerzerKCi-1.5/mainFrame.cpp"
#include "../HerzerKCi-1.5/ButtonFactory.h"
#include "../HerzerKCi-1.5/ButtonFactory.cpp"




using namespace Microsoft::VisualStudio::CppUnitTestFramework;
class mainFrame;
namespace HerzerKCi15Tests
{
	TEST_CLASS(ButtonFactoryTests)
	{
	public:
		mainFrame* testFrame = new mainFrame();
		ButtonFactory* factory = new ButtonFactory();
		TEST_METHOD(EnsureCorrectAmountOfButtonsAreMade) //1
		{
			factory->CreateButtons(testFrame);
			int numOfButtons = factory->buttonSizer->GetItemCount();
			Assert::AreEqual(24, numOfButtons);
		}
		TEST_METHOD(EnsureUnusedButton1IsDisabled) //2
		{
			factory->CreateButtons(testFrame);
			Assert::IsFalse(factory->calcButtons[3]->IsEnabled());
		}
		TEST_METHOD(EnsureUnusedButton2IsDisabled) //3
		{
			factory->CreateButtons(testFrame);
			Assert::IsFalse(factory->calcButtons[11]->IsEnabled());
		}
		TEST_METHOD(EnsureUnusedButton3IsDisabled) //4
		{
			factory->CreateButtons(testFrame);
			Assert::IsFalse(factory->calcButtons[22]->IsEnabled());
		}
		TEST_METHOD(EnsureLableForEqualsIsCorrect) //5
		{
			factory->CreateButtons(testFrame);
			Assert::AreEqual("=", factory->calcButtons[23]->GetLabelText());
		}
		TEST_METHOD(EnsureLableForHexIsCorrect) //6
		{
			factory->CreateButtons(testFrame);
			Assert::AreEqual("(hex)", factory->calcButtons[17]->GetLabelText());
		}
		TEST_METHOD(EnsureLableForSevenIsNotOne) //7
		{
			factory->CreateButtons(testFrame);
			Assert::AreNotEqual("1", factory->calcButtons[0]->GetLabelText());
		}
		TEST_METHOD(EnsureLableForZeroIsNotSeven) //8
		{
			factory->CreateButtons(testFrame);
			Assert::AreNotEqual("7", factory->calcButtons[7]->GetLabelText());
		}
		TEST_METHOD(EnsureButtonIdOfMinusIsCorrect) //9
		{
			factory->CreateButtons(testFrame);
			int buttonId = factory->calcButtons[13]->GetId();
			Assert::AreEqual(10013, buttonId);
		}
		TEST_METHOD(EnsureButtonIdOfClearIsCorrect) //10
		{
			factory->CreateButtons(testFrame);
			int buttonId = factory->calcButtons[18]->GetId();
			Assert::AreEqual(10018, buttonId);
		}
		
	};
}