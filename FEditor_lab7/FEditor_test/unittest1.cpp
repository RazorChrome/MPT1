#include "stdafx.h"
#include "CppUnitTest.h"
#include "../FEditor/FEditor.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace FEditor_test
{
	TEST_CLASS(UnitTest_FEditor)
	{
	public:

		TEST_METHOD(Construct)
		{
			FEditor f("2/3");
			Assert::AreEqual(string("2/3"), f.GetStore());
		}
		TEST_METHOD(AddSign)
		{
			FEditor f("1/6");
			f.AddSign();
			Assert::AreEqual(string("-1/6"), f.GetStore());
			f.AddSign();
			Assert::AreEqual(string("1/6"), f.GetStore());
		}
		TEST_METHOD(NumberisNull)
		{
			FEditor f("0/12345");
			FEditor f2("123/456");
			Assert::IsTrue(f.FracIsNull());
			Assert::IsFalse(f2.FracIsNull());
		}
		TEST_METHOD(AddFracNumber)
		{
			FEditor f("1/1");
			f.AddFracNumber(9);
			Assert::AreEqual(string("1/19"), f.GetStore());
		}
		TEST_METHOD(AddNull)
		{
			FEditor f("6/2");
			f.AddNull();
			Assert::AreEqual(string("6/20"), f.GetStore());
		}
		TEST_METHOD(BackSpace)
		{
			FEditor f(string("12/14"));
			f.Backspace();
			Assert::AreEqual(string("12/1"), f.GetStore());
			f.Backspace();
			Assert::AreEqual(string("12/"), f.GetStore());
			f.Backspace();
			Assert::AreEqual(string("12"), f.GetStore());
			f.Backspace();
			Assert::AreEqual(string("1"), f.GetStore());
			f.Backspace();
			Assert::AreEqual(string("0/1"), f.GetStore());
		}
		TEST_METHOD(Clear)
		{
			FEditor f("2/4");
			f.Clear();
			Assert::AreEqual(string("0/1"), f.GetStore());
		}
		TEST_METHOD(Edit)
		{
			FEditor f;
			Assert::AreEqual(string("0/1"), f.GetStore());
			f.Edit(f.Erase);
			Assert::AreEqual(string("0/"), f.GetStore());
			f.Edit(f.Erase);
			Assert::AreEqual(string("0"), f.GetStore());
			f.Edit(5);
			Assert::AreEqual(string("5"), f.GetStore());
			f.Edit(f.Separator);
			Assert::AreEqual(string("5/"), f.GetStore());
			f.Edit(4);
			Assert::AreEqual(string("5/4"), f.GetStore());
			f.Edit(f.Sign);
			Assert::AreEqual(string("-5/4"), f.GetStore());
			f.Edit(f.RemoveAll);
			Assert::AreEqual(string("0/1"), f.GetStore());
		}
		TEST_METHOD(SetStore)
		{
			FEditor t;
			t.SetStore("1/2");
			Assert::AreEqual(string("1/2"), t.GetStore());
			t.SetStore("-1/4");
			Assert::AreEqual(string("-1/4"), t.GetStore());
			t.SetStore("Z");
			Assert::AreEqual(string("-1/4"), t.GetStore());
			t.SetStore("-0/1");
			Assert::AreEqual(string("-1/4"), t.GetStore());
		}

	};
}