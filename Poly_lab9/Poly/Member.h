#pragma once
#include <cmath>
#include <string>
#include <sstream>

using namespace std;

class Member
{
private:
	int FCoef, FDegree;
public:
	Member();
	Member(int c, int n);
	~Member();

	int getDeg();
	void setDeg(int n);

	int getCoef();
	void setCoef(int c);

	bool operator == (const Member &q);

	Member diff();

	double calculate(int x);

	string toString();

	Member operator + (const Member &q);
	Member operator - (const Member &q);
	Member operator * (const Member &q);

	Member operator - ();

	bool isNull();
	bool operator != (const Member &q);
	bool isNegative();
};

