#include "PNumber.h"

Pnumber::Pnumber() {
	a = 0;
	b = 10;
	c = 0;
}

Pnumber::Pnumber(double x, int y, int z) {
	b = y;
	if (b > 1 && b < 17) {
		a = x;
		c = z;
	}
	else {
		a = 0;
		b = 10;
		c = 0;
	}
}

Pnumber::Pnumber(string sa, string sb, string sc) {
	istringstream(sb) >> b;
	istringstream(sc) >> c;
	a = 0;
	int sign = 1, top = 0, bot = 0;

	if (sa.find('.') >= 1)
	{
		top = sa.find('.');
		bot = sa.size() - top;
	}
	else
	{
		top = sa.size() - 1;
	}

	for (int i = top; i > -bot; --i)
	{
		char tmp = sa.at(top - i);
		if (b > 10)
		{
			if (tmp > 54 + b)
			{
				a = 0;
				b = 10;
				c = 0;
				return;
			}
		}
		else
		{
			if (tmp > 47 + b)
			{
				a = 0;
				b = 10;
				c = 0;
				return;
			}
		}
		switch (tmp)
		{
		case '-':
			sign *= -1;
			break;
		case '1':
			if (i > 0)
				a += 1 * pow(b, i - 1);
			else
				a += 1 * pow(b, i);
			break;
		case '2':
			if (i > 0)
				a += 2 * pow(b, i - 1);
			else
				a += 2 * pow(b, i);
			break;
		case '3':
			if (i > 0)
				a += 3 * pow(b, i - 1);
			else
				a += 3 * pow(b, i);
			break;
		case '4':
			if (i > 0)
				a += 4 * pow(b, i - 1);
			else
				a += 4 * pow(b, i);
			break;
		case '5':
			if (i > 0)
				a += 5 * pow(b, i - 1);
			else
				a += 5 * pow(b, i);
			break;
		case '6':
			if (i > 0)
				a += 6 * pow(b, i - 1);
			else
				a += 6 * pow(b, i);
			break;
		case '7':
			if (i > 0)
				a += 7 * pow(b, i - 1);
			else
				a += 7 * pow(b, i);
			break;
		case '8':
			if (i > 0)
				a += 8 * pow(b, i - 1);
			else
				a += 8 * pow(b, i);
			break;
		case '9':
			if (i > 0)
				a += 9 * pow(b, i - 1);
			else
				a += 9 * pow(b, i);
			break;
		case 'A':
			if (i > 0)
				a += 10 * pow(b, i - 1);
			else
				a += 10 * pow(b, i);
			break;
		case 'B':
			if (i > 0)
				a += 11 * pow(b, i - 1);
			else
				a += 11 * pow(b, i);
			break;
		case 'C':
			if (i > 0)
				a += 12 * pow(b, i - 1);
			else
				a += 12 * pow(b, i);
			break;
		case 'D':
			if (i > 0)
				a += 13 * pow(b, i - 1);
			else
				a += 13 * pow(b, i);
			break;
		case 'E':
			if (i > 0)
				a += 14 * pow(b, i - 1);
			else
				a += 14 * pow(b, i);
			break;
		case 'F':
			if (i > 0)
				a += 15 * pow(b, i - 1);
			else
				a += 15 * pow(b, i);
			break;
		}
	}
	a *= sign;
};


Pnumber Pnumber::operator + (const Pnumber &p2) {
	if (b == p2.b && c == p2.c)
		return Pnumber(a + p2.a, b, c);
	else
		return Pnumber(0, 10, 0);
};

Pnumber Pnumber::operator * (const Pnumber &p2) {
	return Pnumber(a * p2.a, b, c);
};

Pnumber Pnumber::operator - (const Pnumber &p2) {
	return Pnumber(a - p2.a, b, c);
};

Pnumber Pnumber::operator / (const Pnumber &p2) {
	return Pnumber(a / p2.a, b, c);
};

Pnumber Pnumber::reverse() {
	return Pnumber(1 / a, b, c);
};

Pnumber Pnumber::square() {
	return Pnumber(a * a, b, c);
};

double Pnumber::getA() {
	return a;
}

string Pnumber::getAstring() {
	stringstream ss;
	if (a == 0) ss << "0";
	else if (b == 10)
	{
		ss << fixed << setprecision(c) << a;
	}
	else
	{
		double top = 0, bot = 0;
		double ua = a;
		bool sign = false;
		if (a < 0)
		{
			sign = true;
			ua *= -1;
		}

		string res = "";
		bot = modf(ua, &top);
		int itop = top;
		do
		{
			int tmp = itop % b;
			itop /= b;
			switch (tmp)
			{
			case 0:
				res.insert(0, "0");
				break;
			case 1:
				res.insert(0, "1");
				break;
			case 2:
				res.insert(0, "2");
				break;
			case 3:
				res.insert(0, "3");
				break;
			case 4:
				res.insert(0, "4");
				break;
			case 5:
				res.insert(0, "5");
				break;
			case 6:
				res.insert(0, "6");
				break;
			case 7:
				res.insert(0, "7");
				break;
			case 8:
				res.insert(0, "8");
				break;
			case 9:
				res.insert(0, "9");
				break;
			case 10:
				res.insert(0, "A");
				break;
			case 11:
				res.insert(0, "B");
				break;
			case 12:
				res.insert(0, "C");
				break;
			case 13:
				res.insert(0, "D");
				break;
			case 14:
				res.insert(0, "E");
				break;
			case 15:
				res.insert(0, "F");
				break;
			}
		} while (itop > 0);

		if (c > 0)
		{
			res += '.';
			double tmp1 = 0;
			for (int i = 0; i < c; ++i)
			{
				bot *= b;

				bot = modf(bot, &tmp1);
				int itmp = tmp1;
				switch (itmp)
				{
				case 0:
					res += '0';
					break;
				case 1:
					res += '1';
					break;
				case 2:
					res += '2';
					break;
				case 3:
					res += '3';
					break;
				case 4:
					res += '4';
					break;
				case 5:
					res += '5';
					break;
				case 6:
					res += '6';
					break;
				case 7:
					res += '7';
					break;
				case 8:
					res += '8';
					break;
				case 9:
					res += '9';
					break;
				case 10:
					res += 'A';
					break;
				case 11:
					res += 'B';
					break;
				case 12:
					res += 'C';
					break;
				case 13:
					res += 'D';
					break;
				case 14:
					res += 'E';
					break;
				case 15:
					res += 'F';
					break;
				}

			}
		}
		if (sign) res.insert(0, "-");
		ss << res;
	}
	return ss.str();
}

int Pnumber::getB() {
	return b;
}

string Pnumber::getBstring() {
	stringstream ss;
	ss << b;
	return ss.str();
}

int Pnumber::getC() {
	return c;
}

string Pnumber::getCstring() {
	stringstream ss;
	ss << c;
	return ss.str();
}
void Pnumber::setB(int x) {
	if (x > 1 && x < 17)
		b = x;
}

void Pnumber::setBstring(string str) {
	stringstream ss{ str };
	int b_tmp;
	ss >> b_tmp;
	if (b_tmp > 1 && b_tmp < 17) b = b_tmp;
}

void Pnumber::setC(int y) {
	c = y;
}

void Pnumber::setCstring(string str) {
	stringstream ss{ str };
	ss >> c;
}