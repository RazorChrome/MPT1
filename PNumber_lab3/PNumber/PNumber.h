#pragma once
#include <string>
#include <iomanip>
#include <cmath>
#include <vector>
#include <sstream>

using namespace std;

class Pnumber {
public:
	double a;
	int b, c;

	Pnumber();
	Pnumber(double x, int y, int z);
	Pnumber(string sa, string sb, string sc);



	Pnumber operator + (const Pnumber &p2);

	Pnumber operator * (const Pnumber &p2);

	Pnumber operator - (const Pnumber &p2);

	Pnumber operator / (const Pnumber &p2);
	Pnumber reverse();

	Pnumber square();

	double getA();

	string getAstring();


	int getB();

	string getBstring();

	int getC();

	string getCstring();
	void setB(int x);

	void setBstring(string str);

	void setC(int y);

	void setCstring(string str);

};

