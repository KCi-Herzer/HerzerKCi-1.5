#include "pch.h"
#include "CppUnitTest.h"
#include "../HerzerKCi-1.5/ButtonFactory.h"
#include "../HerzerKCi-1.5/mainFrame.h"
#include "../HerzerKCi-1.5/mainFrame.cpp"
#include "../HerzerKCi-1.5/ButtonFactory.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

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
		//TEST_METHOD(EnsureCorrectAmountOfButtonsAreMade) //2
		//{
		//	factory->CreateButtons(testFrame);
		//	int numOfButtons = factory->buttonSizer->GetItemCount();
		//	Assert::AreEqual(24, numOfButtons);
		//}
		//TEST_METHOD(EnsureCorrectAmountOfButtonsAreMade) //3
		//{
		//	factory->CreateButtons(testFrame);
		//	int numOfButtons = factory->buttonSizer->GetItemCount();
		//	Assert::AreEqual(24, numOfButtons);
		//}
		//TEST_METHOD(EnsureCorrectAmountOfButtonsAreMade) //4
		//{
		//	factory->CreateButtons(testFrame);
		//	int numOfButtons = factory->buttonSizer->GetItemCount();
		//	Assert::AreEqual(24, numOfButtons);
		//}
		//TEST_METHOD(EnsureCorrectAmountOfButtonsAreMade) //5
		//{
		//	factory->CreateButtons(testFrame);
		//	int numOfButtons = factory->buttonSizer->GetItemCount();
		//	Assert::AreEqual(24, numOfButtons);
		//}
		//TEST_METHOD(EnsureCorrectAmountOfButtonsAreMade) //6
		//{
		//	factory->CreateButtons(testFrame);
		//	int numOfButtons = factory->buttonSizer->GetItemCount();
		//	Assert::AreEqual(24, numOfButtons);
		//}
		//TEST_METHOD(EnsureCorrectAmountOfButtonsAreMade) //7
		//{
		//	factory->CreateButtons(testFrame);
		//	int numOfButtons = factory->buttonSizer->GetItemCount();
		//	Assert::AreEqual(24, numOfButtons);
		//}
		//TEST_METHOD(EnsureCorrectAmountOfButtonsAreMade) //8
		//{
		//	factory->CreateButtons(testFrame);
		//	int numOfButtons = factory->buttonSizer->GetItemCount();
		//	Assert::AreEqual(24, numOfButtons);
		//}
		//TEST_METHOD(EnsureCorrectAmountOfButtonsAreMade) //9
		//{
		//	factory->CreateButtons(testFrame);
		//	int numOfButtons = factory->buttonSizer->GetItemCount();
		//	Assert::AreEqual(24, numOfButtons);
		//}
		//TEST_METHOD(EnsureCorrectAmountOfButtonsAreMade) //10
		//{
		//	factory->CreateButtons(testFrame);
		//	int numOfButtons = factory->buttonSizer->GetItemCount();
		//	Assert::AreEqual(24, numOfButtons);
		//}
	};
}