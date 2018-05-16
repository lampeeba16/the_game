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
			Assert::IsFalse(Tester.check(1));//Gibt false zurück wenn das Element nicht vorhanden ist --> wird hier getestet.
		}

	};
}