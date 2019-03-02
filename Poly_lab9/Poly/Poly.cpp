#include "Poly.h"


Poly::Poly()
{
	vec.push_back(Member());
}

Poly::Poly(int c, int n)
{
	vec.push_back(Member(c, n));
}

Poly::Poly(vector<Member> v)
{
	if (v.size() > 0)
		vec = v;
	else
		vec.push_back(Member());
}

Poly::Poly(const Poly & q)
{
	vec = q.vec;
}

Poly::~Poly()
{
}

int Poly::deg()
{
	int n = 0;
	if (vec.size()) {
		for (int i = 0; i < vec.size(); ++i) {
			n = max(n, vec[i].getDeg());
		}
	}
	return n;
}

int Poly::coef(int n)
{
	int c = 0;
	if (vec.size()) {
		for (int i = 0; i < vec.size(); ++i) {
			if (n == vec[i].getDeg()) {
				c = vec[i].getCoef();
				break;
			}
		}
	}
	return c;
}

void Poly::clear()
{
	vec.clear();
	vec.push_back(Member());
}

Poly Poly::operator+(const Poly & q)
{
	vector<Member> v;
	vector<Member> r = q.vec;

	for (int i = 0; i < vec.size(); ++i) {
		bool i_sum = false;
		for (int j = 0; j < r.size(); ++j) {
			Member tmp = vec[i] + r[j];
			if (!tmp.isNull()) {
				vector<Member>::iterator it = r.begin() + j--;
				r.erase(it);
				v.push_back(tmp);
				i_sum = true;
				break;
			}
		}
		if (!i_sum) {
			v.push_back(vec[i]);
		}
	}
	for (int j = 0; j < r.size(); ++j) {
		v.push_back(r[j]);
	}
	return Poly(v);
}

Poly Poly::operator-(const Poly & q)
{
	vector<Member> v;
	vector<Member> r = q.vec;

	for (int i = 0; i < vec.size(); ++i) {
		bool i_sum = false;
		for (int j = 0; j < q.vec.size(); ++j) {
			Member tmp = vec[i] - q.vec[j];
			if (!tmp.isNull()) {
				vector<Member>::iterator it = r.begin() + j--;
				r.erase(it);
				v.push_back(tmp);
				i_sum = true;
				break;
			}
		}
		if (!i_sum) {
			v.push_back(vec[i]);
		}
	}
	for (int j = 0; j < r.size(); ++j) {
		v.push_back(r[j]);
	}
	return Poly(v);
}

Poly Poly::operator*(const Poly & q)
{
	vector<Member> v;

	for (int i = 0; i < vec.size(); ++i) {
		for (int j = 0; j < q.vec.size(); ++j) {
			Member tmp = vec[i] * q.vec[j];
			if (!tmp.isNull()) {
				v.push_back(tmp);
			}
		}
	}
	return Poly(v);
}

Poly Poly::operator-()
{
	vector<Member> v;

	for (int i = 0; i < vec.size(); ++i) {
		v.push_back(-vec[i]);
	}
	return Poly(v);
}

bool Poly::operator==(const Poly & q)
{
	if (vec.size() == q.vec.size()) {
		for (int i = 0; i < vec.size(); ++i) {
			if (vec[i] != q.vec[i]) return false;
		}
	}
	return true;
}

Poly Poly::diff()
{
	vector<Member> v;

	for (int i = 0; i < vec.size(); ++i) {
		v.push_back(vec[i].diff());
	}
	return Poly(v);
}

double Poly::calculate(int x)
{
	double res = 0.0;

	for (int i = 0; i < vec.size(); ++i) {
		res += vec[i].calculate(x);
	}
	return res;
}

Member Poly::at(int i)
{
	if (i >= 0 && i < vec.size()) {
		return vec.at(i);
	}
	return Member();
}

string Poly::toString()
{
	stringstream ss;
	for (int i = 0; i < vec.size(); ++i) {
		if (!vec[i].isNegative() && i > 0)
			ss << '+';
		ss << vec[i].toString();
	}
	return ss.str();
}