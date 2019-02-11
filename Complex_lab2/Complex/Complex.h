#pragma once
#include <string>
#include <cmath>
#include <sstream>

#define PI 3.141592653589

using namespace std;

class Complex
{
private:
	double Re, Im;
public:
	Complex();
	Complex(double a, double b);
	Complex(string str);
	Complex copy();
	Complex operator + (const Complex &c);
	Complex operator * (const Complex &c);
	Complex square();
	Complex reverse();
	Complex operator - (const Complex &c);
	Complex operator / (const Complex &c);
	Complex operator - ();
	double module();
	double rad();
	double degree();
	Complex cPow(int n);
	Complex cSqrt(int n, int i);
	const bool operator == (const Complex &c);
	const bool operator != (const Complex &c);
	double getRe();
	double getIm();
	string getStringRe();
	string getStringIm();
	string getComplex();

};
