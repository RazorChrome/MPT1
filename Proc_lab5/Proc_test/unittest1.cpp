#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Proc/Proc.h"
#include "../../Frac_lab1/Frac/Frac.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Process_Test
{
	TEST_CLASS(UnitTestProcess)
	{
	public:

		TEST_METHOD(Constructor)
		{
			Proc<Frac> f;
			Assert::AreEqual(string("0/1"), f.getLeft().getFrac());
			Assert::AreEqual(string("0/1"), f.getRight().getFrac());
			Assert::AreEqual((int)f.None, f.getOptn());
		}
		TEST_METHOD(ProcReset)
		{
			Proc<int> p;
			p.setLeft(10);
			p.setRight(25);
			p.reset();
			Assert::AreEqual((int)p.None, p.getOptn());

		}
		TEST_METHOD(OptnClear)
		{
			Proc<int> p;
			p.setOptn(p.Mul);
			p.OptnClear();
			Assert::AreEqual((int)p.None, p.getOptn());
		}
		TEST_METHOD(OptnRun)
		{
			Proc<int> p;
			p.setLeft(5);
			p.setRight(10);
			p.setOptn(p.Add);
			p.OptnRun();
			Assert::AreEqual(15, p.getLeft());
		}

		TEST_METHOD(FuncRun)
		{
			Proc<Frac> f;
			f.setRight(string("1/2"));
			f.setOptn(f.Rev);
			f.FuncRun();
			Assert::AreEqual(string("2/1"), f.getRight().getFrac());
		}
	};
}