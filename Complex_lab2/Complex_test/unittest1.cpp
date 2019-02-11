#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Complex/Complex.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Complex_test
{		
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(Construct1)
		{
			Complex c;
			Assert::AreEqual(0.0, c.getRe());
			Assert::AreEqual(0.0, c.getIm());
		}
		
		TEST_METHOD(Construct2)
		{
			Complex c(1.3, 12.9);
			Assert::AreEqual(1.3, c.getRe());
			Assert::AreEqual(12.9, c.getIm());
		}

		TEST_METHOD(Construct3)
		{
			string str("0.78+i*3.8");
			Complex c(str);
			Assert::AreEqual(0.78, c.getRe());
			Assert::AreEqual(3.8, c.getIm());
		}

		TEST_METHOD(Copy)
		{
			Complex c(1.0, 2.0);
			Complex c1 = c.copy();
			Assert::AreEqual(1.0, c1.getRe());
			Assert::AreEqual(2.0, c1.getIm());
		}

		TEST_METHOD(Sum)
		{
			Complex c1(10.5, 3.3);
			Complex c2(0.5, 0.7);
			Complex c = c1 + c2;
			Assert::AreEqual(11.0, c.getRe());
			Assert::AreEqual(4.0, c.getIm());
		}

		TEST_METHOD(Mul)
		{
			Complex c1(1.2, 3.3);
			Complex c2(0.5, 0.0);
			Complex c = c1 * c2;
			Assert::AreEqual(0.6, c.getRe());
			Assert::AreEqual(1.65, c.getIm());
		}

		TEST_METHOD(Square)
		{
			Complex c1(3.0,5.0);
			Complex c = c1.square();
			Assert::AreEqual(-16.0, c.getRe());
			Assert::AreEqual(30.0, c.getIm());
		}

		TEST_METHOD(Reverse)
		{
			Complex c1(2.0, 2.0);
			Complex c = c1.reverse();
			Assert::AreEqual(0.25, c.getRe());
			Assert::AreEqual(0.25, c.getIm());
		}

		TEST_METHOD(Minus)
		{
			Complex c1(10.5, 3.3);
			Complex c2(0.5, 0.3);
			Complex c = c1 - c2;
			Assert::AreEqual(10.0, c.getRe());
			Assert::AreEqual(3.0, c.getIm());
		}

		TEST_METHOD(Div)
		{
			Complex c1(1.5, 1.0);
			Complex c2(2.0, 2.0);
			Complex c = c1 / c2;
			Assert::AreEqual(0.625, c.getRe());
			Assert::AreEqual(-0.125, c.getIm());
		}

		TEST_METHOD(UnarMinus)
		{
			Complex c1(5.5, 2.3);
			Complex c = -c1;
			Assert::AreEqual(-5.5, c.getRe());
			Assert::AreEqual(-2.3, c.getIm());
		}

		TEST_METHOD(CModule)
		{
			Complex c(3.0, 3.0);
			double res = c.module();
			Assert::AreEqual(sqrt(18.0), res);
		}

		TEST_METHOD(Rad)
		{
			Complex c(1.0, 2.0);
			double res = c.rad();
			Assert::AreEqual(atan(2.0), res);

			c = Complex(0.0, 2.0);
			res = c.rad();
			Assert::AreEqual(PI / 2, res);

			c = Complex(-1.0, 2.0);
			res = c.rad();
			Assert::AreEqual(atan(-2.0) + PI, res);

			c = Complex(0.0, 0.0);
			res = c.rad();
			Assert::AreEqual(-PI / 2, res);
		}

		TEST_METHOD(CDegree)
		{
			Complex c(0.0, 2.0);
			double res = c.degree();
			Assert::AreEqual((PI / 2) * 180 / PI, res);
		}

		TEST_METHOD(CPow)
		{
			Complex c1(1.5, 2.5);
			Complex c = c1.cPow(2);
			Assert::AreEqual(-4.0, c.getRe());
			Assert::AreEqual(7.5, c.getIm());
		}

		TEST_METHOD(CSqrt)
		{
			Complex c1(0.0, 2.0);
			Complex c = c1.cSqrt(2, 1);
			double Re = sqrt(2) * (cos((PI / 2 + 2 * 1 * PI) / 2));
			double Im = sqrt(2) * (sin((PI / 2 + 2 * 1 * PI) / 2));
			Assert::AreEqual(Re, c.getRe());
			Assert::AreEqual(Im, c.getIm());
		}

		TEST_METHOD(Equality)
		{
			Complex c1(12.3, 3.6);
			Complex c2(3.6, 12.3);
			Assert::IsFalse(c1 == c2);
		}

		TEST_METHOD(TestNotEquality)
		{
			Complex c1(12.3, 3.6);
			Complex c2(12.3, 3.6);
			Assert::IsFalse(c1 != c2);
		}

		TEST_METHOD(CGetRe)
		{
			Complex c(1.5, 2.5);
			Assert::AreEqual(1.5, c.getRe());
		}

		TEST_METHOD(CGetIm)
		{
			Complex c(1.5, 2.5);
			Assert::AreEqual(2.5, c.getIm());
		}

		TEST_METHOD(CGetStringRe)
		{
			Complex c(1.5, 2.5);
			string str("1.5");
			Assert::AreEqual(str, c.getStringRe());
		}

		TEST_METHOD(CGetStringIm)
		{
			Complex c(1.5, 2.5);
			string str("2.5");
			Assert::AreEqual(str, c.getStringIm());
		}
		
		TEST_METHOD(CgetComplex)
		{
			Complex c(1.5, 2.5);
			string str("1.5+i*2.5");
			Assert::AreEqual(str, c.getComplex());
		}

	};
}