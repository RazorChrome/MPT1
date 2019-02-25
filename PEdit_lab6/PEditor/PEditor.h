#pragma once
#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;

string const Nul = "0";

class PEditor
{
private:
	string PEdit; // строка
	string const separator = ",";


public:
	enum
	{
		Sign = 20,
		Erase = 21,
		RemoveAll = 22,
		Dot = 23

	}; // ???
	bool  NumberIsNull(); 
	string AddSign(); 
	string AddPNumber(int a); 
	string AddNull(); 
	string BackSpace(); 
	string Clear(); 
	PEditor(string Cr = Nul); 
	string GetStore(); 
	void SetStore(string a); 
	string Edit(int a); 
	string AddDot();

};
string toString(int a) { // ???  some shit  how fix?
	string str = to_string(a);
	return str;
}




