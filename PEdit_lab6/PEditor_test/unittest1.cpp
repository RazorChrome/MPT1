#include "stdafx.h"
#include "CppUnitTest.h"
#include "../PEditor/PEditor.h"
#include "../PEditor/PEditor.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PEditor_test
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(PEdit_Construct)
		{
			PEditor t;
			string output = "10";
			t.SetStore(output);
			Assert::AreEqual(output, t.GetStore());
		}
		TEST_METHOD(PEdit_AddSign)
		{
			PEditor t;
			string str = "9";
			t.SetStore(str);
			t.AddSign();
			PEditor t1;
			string str1 = "-9";
			t1.SetStore(str1);
			t1.AddSign();

			Assert::AreEqual(str1, t.GetStore());
			Assert::AreEqual(str, t1.GetStore());

		}
		TEST_METHOD(PEdit_NumberisNull)
		{
			PEditor t;
			string str = "0,";
			PEditor t1;
			string str1 = "-0,";
			PEditor t2;
			string str2 = "1";
			t.SetStore(str);
			t1.SetStore(str1);
			t2.SetStore(str2);
			Assert::IsTrue(t.NumberIsNull());
			Assert::IsTrue(t1.NumberIsNull());
			Assert::IsFalse(t2.NumberIsNull());
		}
		TEST_METHOD(PEdit_AddPNumber)
		{
			PEditor t;
			t.AddPNumber(10);

			Assert::AreEqual(string("A"), t.GetStore());
		}
		TEST_METHOD(PEdit_AddNull)
		{
			PEditor t;
			string str = "5";
			t.SetStore(str);
			t.AddNull();
			Assert::AreEqual(string("50"), t.GetStore());
		}
		TEST_METHOD(PEdit_Backspace)
		{
			PEditor t(string("-12,34"));
			t.BackSpace();
			Assert::AreEqual(string("-12,3"), t.GetStore());
			t.BackSpace();
			Assert::AreEqual(string("-12,"), t.GetStore());
			t.BackSpace();
			Assert::AreEqual(string("-12"), t.GetStore());
			t.BackSpace();
			Assert::AreEqual(string("-1"), t.GetStore());
			t.BackSpace();
			Assert::AreEqual(string("0"), t.GetStore());

		}
		TEST_METHOD(PEdit_Clear)
		{
			PEditor t;
			t.SetStore("5");
			t.Clear();
			Assert::AreEqual(string("0"), t.GetStore());
		}
		TEST_METHOD(PEdit_Edit)
		{
			PEditor t;
			t.Edit(10);
			Assert::AreEqual(string("A"), t.GetStore());
			t.Edit(1);
			Assert::AreEqual(string("A1"), t.GetStore());
			t.Edit(t.Erase);
			Assert::AreEqual(string("A"), t.GetStore());
			t.Edit(t.Dot);
			Assert::AreEqual(string("A,"), t.GetStore());
			t.Edit(15);
			Assert::AreEqual(string("A,F"), t.GetStore());
			t.Edit(t.Sign);
			Assert::AreEqual(string("-A,F"), t.GetStore());
			t.Edit(t.Sign);
			Assert::AreEqual(string("A,F"), t.GetStore());
			t.Edit(t.RemoveAll);
			Assert::AreEqual(string("0"), t.GetStore());
		}
		TEST_METHOD(PEdit_SetStore)
		{
			PEditor t;
			t.SetStore("0,C");
			Assert::AreEqual(string("0,C"), t.GetStore());
			t.SetStore("-7,FFC");
			Assert::AreEqual(string("-7,FFC"), t.GetStore());
			t.SetStore("Z");
			Assert::AreEqual(string("-7,FFC"), t.GetStore());

		}
	};
}