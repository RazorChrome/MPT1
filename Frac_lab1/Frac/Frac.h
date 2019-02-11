#pragma once
#include <string>
#include <cmath>
#include <sstream>

using namespace std;

class Frac{
private:
	int numer, denom;
public:
	int gcd(int a, int b)
	{
		if (a < 0) a *= -1;
		if (b < 0) b *= -1;
		while (a != b)
		{
			if (a > b)
			{
				int tmp = a;
				a = b;
				b = tmp;
			}
			b = b - a;
		}
		return a;
	}

	void reduction()
	{
		int k = gcd(numer, denom);
		numer /= k;
		denom /= k;
		if (denom < 0)
		{
			denom *= -1;
			numer *= -1;
		}
	}

	//По заданию
	Frac()
	{
		numer = 0;
		denom = 1;
	}

	Frac(int a, int b)
	{
		if (b == 0 || a == 0)
		{
			numer = 0;
			denom = 1;
		}
		else
		{
			numer = a;
			denom = b;
			reduction();
		}
	}

	Frac(string str)
	{
		stringstream ss{ str };
		(ss >> numer).ignore(numeric_limits<streamsize>::max(), '/') >> denom;
		if (denom == 0)
		{
			numer = 0;
			denom = 1;
		}
		else
		{
			reduction();
		}
	}

	Frac copy()
	{
		return Frac(numer, denom);
	}

	Frac operator+(const Frac &f)
	{
		return Frac(numer * f.denom + f.numer * denom, denom * f.denom);
	}

	Frac operator-(const Frac &f)
	{
		return Frac(numer * f.denom - f.numer * denom, denom * f.denom);
	}

	Frac operator*(const Frac &f)
	{
		return Frac(numer * f.numer, denom * f.denom);
	}

	Frac operator/(const Frac &f)
	{
		return Frac(numer * f.denom, denom * f.numer);
	}

	Frac square()
	{
		return Frac(numer*numer, denom*denom);
	}

	Frac reverse()
	{
		return Frac(denom, numer);
	}

	Frac operator-()
	{
		return Frac(numer*-1, denom);
	}

	const bool operator>(const Frac &f)
	{
		double f1 = numer / denom;
		double f2 = f.numer / f.denom;

		return f1 > f2;
	}

	const bool operator==(const Frac &f)
	{
		if (numer == f.numer && denom == f.denom) return true;
		return false;
	}

	int getNumer() { return numer; }

	int getDenom() { return denom; }

	string getStringNumer()
	{
		stringstream ss;
		ss << numer;
		return ss.str();
	}

	string getStringDenom()
	{
		stringstream ss;
		ss << denom;
		return ss.str();
	}

	string getFrac()
	{
		stringstream ss;
		ss << numer << "/" << denom;
		return ss.str();
	}
};