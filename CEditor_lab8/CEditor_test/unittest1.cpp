#include "stdafx.h"
#include "CppUnitTest.h"
#include "../CEditor/CEditor.h"
#include "../CEditor/CEditor.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CEditor_test
{		
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(Construct)
		{
			CEditor c("10+i*2");
			Assert::AreEqual(string("10+i*2"), c.getStore());
		}
		TEST_METHOD(AddSign)
		{
			CEditor c("2+i*3");
			c.SetMode(LEFT);
			c.AddSign();
			Assert::AreEqual(string("-2+i*3"), c.getStore());
			CEditor c1("2+i*3");
			c1.SetMode(RIGHT);
			c1.AddSign();
			Assert::AreEqual(string("2-i*3"), c1.getStore());
		}
		TEST_METHOD(NumberIsNull)
		{
			CEditor c("0+i*0");
			CEditor c1("1+i*2");
			Assert::IsTrue(c.IsNull());
			Assert::IsFalse(c1.IsNull());
		}
		TEST_METHOD(AddCNumber)
		{
			CEditor c("5+i*6");
			c.SetMode(LEFT);
			c.AddComplexNumber(3);
			Assert::AreEqual(string("53+i*6"), c.getStore());
			c.AddComplexNumber(2);
			Assert::AreEqual(string("532+i*6"), c.getStore());
			c.SetMode(RIGHT);
			c.AddComplexNumber(2);
			Assert::AreEqual(string("532+i*62"), c.getStore());
			c.AddComplexNumber(1);
			Assert::AreEqual(string("532+i*621"), c.getStore());
		}
		TEST_METHOD(BackSpace)
		{
			CEditor c("10-i*23");
			c.SetMode(LEFT);
			c.BackSpace();
			Assert::AreEqual(string("1-i*23"), c.getStore());
			c.BackSpace();
			Assert::AreEqual(string("-i*23"), c.getStore());
			c.SetMode(RIGHT);
			c.BackSpace();
			Assert::AreEqual(string("-i*2"), c.getStore());
			c.BackSpace();
			Assert::AreEqual(string("-i*"), c.getStore());
		}
		TEST_METHOD(AddNull)
		{
			CEditor c("5+i*3");
			c.SetMode(LEFT);
			c.AddNull();
			Assert::AreEqual(string("50+i*3"), c.getStore());
			c.SetMode(RIGHT);
			c.AddNull();
			Assert::AreEqual(string("50+i*30"), c.getStore());
		}
		TEST_METHOD(Clear)
		{
			CEditor c("3+i*5");
			c.Clear();
			Assert::AreEqual(string("0+i*0"), c.getStore());
		}
		TEST_METHOD(Edit)
		{
			CEditor c;
			c.SetMode(LEFT);
			c.Edit(c.Erase);
			Assert::AreEqual(string("+i*0"), c.getStore());
			c.SetMode(RIGHT);
			c.Edit(c.Erase);
			Assert::AreEqual(string("+i*"), c.getStore());
			c.SetMode(LEFT);
			c.Edit(3);
			Assert::AreEqual(string("3+i*"), c.getStore());
			c.SetMode(RIGHT);
			c.Edit(0);
			Assert::AreEqual(string("3+i*0"), c.getStore());
			c.Edit(6);
			Assert::AreEqual(string("3+i*6"), c.getStore());
			c.SetMode(LEFT);
			c.Edit(c.Sign);
			Assert::AreEqual(string("-3+i*6"), c.getStore());
			c.SetMode(RIGHT);
			c.Edit(c.Sign);
			Assert::AreEqual(string("-3-i*6"), c.getStore());
			c.Edit(c.RemoveAll);
			Assert::AreEqual(string("0+i*0"), c.getStore());
		}
		TEST_METHOD(SetStore)
		{
			CEditor c;
			c.setStore("1+i*3");
			Assert::AreEqual(string("1+i*3"), c.getStore());
			c.setStore("-1-i*4");
			Assert::AreEqual(string("-1-i*4"), c.getStore());
			c.setStore("Z");
			Assert::AreEqual(string("0+i*0"), c.getStore());
		}
	};
}