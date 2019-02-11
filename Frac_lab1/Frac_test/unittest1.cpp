#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\Frac\Frac.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Frac_test
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(Constructor1)
		{
			Frac f1;
			string str("0/1");
			Assert::AreEqual(str, f1.getFrac());
		}

		TEST_METHOD(Constructor2)
		{
			Frac f2(4, 6);
			string str = "2/3";
			Assert::AreEqual(str, f2.getFrac());
		}

		TEST_METHOD(Constructor3)
		{
			Frac f3("-24/48");
			string str = "-1/2";
			Assert::AreEqual(str, f3.getFrac());
		}
		TEST_METHOD(Copy)
		{
			Frac f(2,3);
			Frac f1 = f.copy();
			string str("2/3");
			Assert::AreEqual(str, f1.getFrac());
		}

		TEST_METHOD(Sum)
		{
			Frac f1(1, 2);
			Frac f2(2, 3);
			Frac f3 = f1 + f2;
			string str("7/6");
			Assert::AreEqual(str, f3.getFrac());
		}

		TEST_METHOD(Minus)
		{
			Frac f1(1, 2);
			Frac f2(2, 3);
			Frac f3 = f1 - f2;
			string str = "-1/6";
			Assert::AreEqual(str, f3.getFrac());
		}

		TEST_METHOD(Mul)
		{
			Frac f1(1, 2);
			Frac f2(2, 3);
			Frac f3 = f1 * f2;
			string str = "1/3";
			Assert::AreEqual(str, f3.getFrac());
		}

		TEST_METHOD(Div)
		{
			Frac f1(1, 2);
			Frac f2(2, 3);
			Frac f3 = f1 / f2;
			string str = "3/4";
			Assert::AreEqual(str, f3.getFrac());
		}

		TEST_METHOD(UnarMinus)
		{
			Frac f1(1, 2);
			f1 = -f1;
			string str = "-1/2";
			Assert::AreEqual(str, f1.getFrac());
		}

		TEST_METHOD(Square)
		{
			Frac f1(2, 3);
			f1 = f1.square();
			string str = "4/9";
			Assert::AreEqual(str, f1.getFrac());
		}

		TEST_METHOD(Reverse)
		{
			Frac f1(2, 3);
			f1 = f1.reverse();
			string str = "3/2";
			Assert::AreEqual(str, f1.getFrac());
		}

		TEST_METHOD(MoreThan)
		{
			Frac f(3, 2);
			Frac t(2, 3);
			Assert::IsFalse(t > f);
		}

		TEST_METHOD(Equality)
		{
			Frac f1(2, 3);
			Frac f2(1, 2);
			Assert::IsFalse(f1 == f2);
		}

		TEST_METHOD(GetNumer)
		{
			Frac f1(4,5);
			Assert::AreEqual(4, f1.getNumer());
		}

		TEST_METHOD(GetDenom)
		{
			Frac f1(4, 5);
			Assert::AreEqual(5, f1.getDenom());
		}

		TEST_METHOD(GetStringNumer)
		{
			Frac f1(4, 5);
			string str = "4";
			Assert::AreEqual(str, f1.getStringNumer());
		}

		TEST_METHOD(GetStringDenom)
		{
			Frac f1(4, 5);
			string str = "5";
			Assert::AreEqual(str, f1.getStringDenom());
		}

		TEST_METHOD(GetFrac)
		{
			Frac f1(4, 5);
			string str = "4/5";
			Assert::AreEqual(str, f1.getFrac());
		}

	};
}