#include "Member.h"


Member::Member()
{
	FCoef = 0;
	FDegree = 0;
}

Member::Member(int c, int n)
{
	FCoef = c;
	FDegree = n;
}

Member::~Member()
{
}

int Member::getDeg()
{
	return FDegree;
}

void Member::setDeg(int n)
{
	FDegree = n;
}

int Member::getCoef()
{
	return FCoef;
}

void Member::setCoef(int c)
{
	FCoef = c;
}

bool Member::operator==(const Member & q)
{
	return (FCoef == q.FCoef && FDegree == q.FDegree);
}

Member Member::diff()
{
	int c = FCoef, d = FDegree;
	if (c != 0 && d != 0) {
		c *= d;
		--d;
		return Member(c, d);
	}
	return Member();
}

double Member::calculate(int x)
{
	if (FCoef == 0) {
		return 0.0;
	}
	else {
		if (FDegree == 0) {
			return FCoef;
		}
		else {
			return FCoef * pow(x, FDegree);
		}
	}
}

string Member::toString()
{
	stringstream ss;
	if (FCoef == 0) {
		ss << 0;
	}
	else {
		if (FCoef == -1 || FCoef == 1) {
			if (FDegree == 0)
				ss << FCoef;
			else if (FCoef == -1)
				ss << '-';
		}
		else {
			ss << FCoef;
		}

		if (FDegree != 0) {
			ss << 'x';
			if (FDegree > 1 || FDegree < 0) {
				ss << '^' << FDegree;
			}
		}
	}
	return ss.str();
}

Member Member::operator+(const Member & q)
{
	if (FDegree == q.FDegree) {
		return Member(FCoef + q.FCoef, FDegree);
	}
	return Member();
}

Member Member::operator-(const Member & q)
{
	if (FDegree == q.FDegree) {
		return Member(FCoef - q.FCoef, FDegree);
	}
	return Member();
}

Member Member::operator*(const Member & q)
{
	return Member(FCoef * q.FCoef, FDegree + q.FDegree);
}

Member Member::operator-()
{
	return Member(-FCoef, FDegree);
}

bool Member::isNull()
{
	return (FCoef == 0);
}

bool Member::operator!=(const Member & q)
{
	return !(*this == q);
}

bool Member::isNegative()
{
	return FCoef < 0;
}