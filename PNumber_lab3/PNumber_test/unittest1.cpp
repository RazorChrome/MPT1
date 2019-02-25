#include "stdafx.h"
#include "CppUnitTest.h"
#include "../PNumber/PNumber.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PNumber_test
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(Construct1)
		{
			Pnumber p(1, 2, 3);
			Assert::AreEqual(1.0, p.a);
			Assert::AreEqual(2, p.b);
			Assert::AreEqual(3, p.c);
		}

		TEST_METHOD(ConstructString)
		{
			Pnumber p(string("-C.C"), string("16"), string("1"));
			Assert::AreEqual(-12.75, p.a, 0.001);
			Assert::AreNotEqual(0, p.b);
			Assert::AreNotEqual(0, p.c);

			Pnumber p2(string("10.101"), string("2"), string("3"));
			Assert::AreEqual(2.625, p2.a, 0.001);
			Assert::AreNotEqual(0, p2.b);
			Assert::AreNotEqual(0, p2.c);

			Pnumber oct(string("52.24"), string("8"), string("2"));
			Assert::AreEqual(42.3125, oct.a, 0.00001);
			Assert::AreNotEqual(0, oct.b);
			Assert::AreNotEqual(0, oct.c);
		}

		TEST_METHOD(Plus)
		{
			Pnumber q(1.5, 2, 1);
			Pnumber w(3.5, 2, 1);
			Pnumber p = q + w;
			Assert::AreEqual(5.0, p.a);
			Assert::AreEqual(2, p.b);
			Assert::AreEqual(1, p.c);
		}

		TEST_METHOD(Mul)
		{
			Pnumber q(2, 2, 3);
			Pnumber w(3, 2, 3);
			Pnumber p = q * w;
			Assert::AreEqual(6.0, p.a);
			Assert::AreEqual(2, p.b);
			Assert::AreEqual(3, p.c);
		}

		TEST_METHOD(Minus)
		{
			Pnumber q(5, 2, 3);
			Pnumber w(3, 2, 3);
			Pnumber p = q - w;
			Assert::AreEqual(2.0, p.a);
			Assert::AreEqual(2, p.b);
			Assert::AreEqual(3, p.c);
		}

		TEST_METHOD(Div)
		{
			Pnumber q(6, 2, 3);
			Pnumber w(3, 2, 3);
			Pnumber p = q / w;
			Assert::AreEqual(2.0, p.a);
			Assert::AreEqual(2, p.b);
			Assert::AreEqual(3, p.c);
		}

		TEST_METHOD(Reverse)
		{
			Pnumber q(2, 2, 3);
			Pnumber p = q.reverse();
			Assert::AreEqual(0.5, p.a);
			Assert::AreEqual(2, p.b);
			Assert::AreEqual(3, p.c);
		}

		TEST_METHOD(Square)
		{
			Pnumber q(6, 2, 3);
			Pnumber p = q.square();
			Assert::AreEqual(36.0, p.a);
			Assert::AreEqual(2, p.b);
			Assert::AreEqual(3, p.c);
		}

		TEST_METHOD(GetA)
		{
			Pnumber p(6, 2, 3);
			Assert::AreEqual(6.0, p.getA());
		}

		TEST_METHOD(GetAstring)
		{
			Pnumber p(-150.248, 10, 3);
			string dec("-150.248");
			Assert::AreEqual(dec, p.getAstring());

			p.setB(2);
			string bin("-10010110.001");
			Assert::AreEqual(bin, p.getAstring());

			p.setB(8);
			string oct("-226.176");
			Assert::AreEqual(oct, p.getAstring());

			p.setB(16);
			string hex("-96.3F7");
			Assert::AreEqual(hex, p.getAstring());

			p.setB(4);
			string four("-2112.033");
			Assert::AreEqual(four, p.getAstring());
		}
		TEST_METHOD(GetB)
		{
			Pnumber p(6, 2, 3);
			Assert::AreEqual(2, p.getB());
		}
		TEST_METHOD(GetBString)
		{
			Pnumber p(6, 2, 3);
			string strB("2");
			Assert::AreEqual(strB, p.getBstring());
		}

		TEST_METHOD(GetC)
		{
			Pnumber p(6, 2, 3);
			Assert::AreEqual(3, p.getC());
		}

		TEST_METHOD(GetCString)
		{
			Pnumber p(6, 2, 3);
			string strC("3");
			Assert::AreEqual(strC, p.getCstring());
		}

		TEST_METHOD(SetB)
		{
			Pnumber p(6, 2, 3);
			p.setB(8);
			Assert::AreEqual(8, p.getB());
		}

		TEST_METHOD(SetBstring)
		{
			Pnumber p(6, 2, 3);
			string str("8");
			p.setBstring(str);
			Assert::AreEqual(8, p.getB());
		}

		TEST_METHOD(SetC)
		{
			Pnumber p(6, 2, 3);
			p.setC(4);
			Assert::AreEqual(4, p.getC());
		}

		TEST_METHOD(SetCstring)
		{
			Pnumber p(6, 2, 3);
			string str("4");
			p.setCstring(str);
			Assert::AreEqual(4, p.getC());
		}
	};
}