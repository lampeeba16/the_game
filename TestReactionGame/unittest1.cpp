#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Reactiongame/iomanager.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestReactionGame
{		
	TEST_CLASS(IO_test)
	{
	public:
		
		TEST_METHOD(Test_construction)
		{
			Io_manager Tester;
			Assert::IsFalse(Tester.check(1));
			Tester.reserve(1);
			Assert::IsTrue(Tester.check(1));//Gibt false zurück wenn das Element nicht vorhanden ist --> wird hier getestet.
			Tester.release(1);
			Assert::IsFalse(Tester.check(1));
		}

	};
}