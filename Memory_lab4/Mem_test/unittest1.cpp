#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Memory/Memory.h"
#include "../../Frac_lab1/Frac/Frac.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Mem_test
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		

		TEST_METHOD(Construct)
		{
			Memory<Frac> m;
			string str("0/1");
			Assert::AreEqual(str, m.get().getFrac());
		}

		TEST_METHOD(Write)
		{
			Memory<int> m;
			m.write(9);
			Assert::AreEqual(9, m.get());
		}

		TEST_METHOD(Add)
		{
			Memory<int> m;
			m.write(100);
			m.add(11);
			Assert::AreEqual(111, m.get());
		}

		TEST_METHOD(Clear)
		{
			Memory<Frac> m;
			m.write(string("4/5"));
			m.clear();
			string str("_Off");
			Assert::AreEqual(str, m.getState());
		}

		TEST_METHOD(GetState)
		{
			Memory <int> m1;
			Memory <Frac> m2;
			m1.write(120);
			string str1("_On"), str2("_Off");
			Assert::AreEqual(str1, m1.getState());
			Assert::AreEqual(str2, m2.getState());
		}

	};
}