#include "Complex.h"

Complex::Complex()
{
	Re = 0;
	Im = 0;
}

Complex::Complex(double a, double b)
{
	Re = a;
	Im = b;
}

Complex::Complex(string str)
{
	stringstream ss{ str };
	ss >> Re;
	char t;
	ss >> t >> t >> t;
	ss >> Im;
};

Complex Complex::copy()
{
	return Complex(Re, Im);
}

Complex Complex::operator + (const Complex &c)
{
	return Complex(Re + c.Re, Im + c.Im);
};

Complex Complex::operator * (const Complex &c)
{
	return Complex(Re * c.Re - Im * c.Im, Re * c.Im + Im * c.Re);
};

Complex Complex::square()
{
	return Complex(Re * Re - Im * Im, Re * Im + Re * Im);
}

Complex Complex::reverse()
{
	return Complex(Re / (Re * Re + Im * Im), Im / (Re * Re + Im * Im));
}

Complex Complex::operator - (const Complex &c)
{
	return Complex(Re - c.Re, Im - c.Im);
};

Complex Complex::operator / (const Complex &c)
{
	return Complex((Re * c.Re + Im * c.Im) / (c.Re * c.Re + c.Im * c.Im),
		(c.Re * Im - Re * c.Im) / (c.Re * c.Re + c.Im * c.Im));
};

Complex Complex::operator - ()
{
	return Complex(-Re, -Im);
};

double Complex::module()
{
	return sqrt(Re * Re + Im * Im);
}

double Complex::rad()
{
	if (Re > 0)
	{
		return atan(Im / Re);
	}
	else if (Re == 0 && Im > 0)
	{
		return PI / 2;
	}
	else if (Re < 0) {

		return atan(Im / Re) + PI;
	}
	else
	{
		return -PI / 2;
	}
}

double Complex::degree()
{
	return rad() * 180 / PI;
}

Complex Complex::cPow(int n)
{
	return Complex(pow(module(), n) * cos(n * rad()), pow(module(), n) * sin(n * rad()));
}

Complex Complex::cSqrt(int n, int i)
{
	return Complex(pow(module(), double(1) / double(n)) * (cos((rad() + 2 * i * PI) / n)),
		pow(module(), double(1) / double(n)) * (sin((rad() + 2 * i * PI) / n)));
}

const bool Complex::operator == (const Complex &c)
{
	if ((Re == c.Re) && (Im == c.Im)) return true;
	return false;
}

const bool Complex::operator != (const Complex &c)
{
	return !(*this == c);
}

double Complex::getRe()
{
	return Re;
}

double Complex::getIm()
{
	return Im;
}

string Complex::getStringRe() 
{
	stringstream ss;
	ss << Re;
	return ss.str();
}


string Complex::getStringIm() 
{
	stringstream ss;
	ss << Im;
	return ss.str();
}

string Complex::getComplex() 
{
	stringstream ss;
	ss << Re << "+i*" << Im;
	return ss.str();
}
