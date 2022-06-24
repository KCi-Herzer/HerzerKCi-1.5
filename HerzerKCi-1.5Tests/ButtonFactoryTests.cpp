#include "pch.h"
#include "CppUnitTest.h"
#include "../HerzerKCi-1.5/ButtonFactory.h"
#include "../HerzerKCi-1.5/ButtonFactory.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace HerzerKCi15Tests
{
	TEST_CLASS(HerzerKCi15Tests)
	{
	public:
		
		TEST_METHOD(FactoryTest1)
		{
			Assert::AreEqual(1, 3);
		}
	};
}
