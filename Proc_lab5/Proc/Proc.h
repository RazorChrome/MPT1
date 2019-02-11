#pragma once
#include <cmath>

template<class C>
class Proc
{
private:
	C Lop_Res, Rop;
	int Operation;
public:
	enum {
		None = 0,
		Add = 1,
		Sub = 2,
		Mul = 3,
		Dvd = 4,
		Rev = 5,
		Sqr = 6
	};

	Proc<C>::Proc()
	{
		Lop_Res = C();
		Rop = C();
		Operation = None;
	}


	void Proc<C>::reset()
	{
		Lop_Res = C();
		Rop = C();
		Operation = None;
	}

	void Proc<C>::OptnClear()
	{
		Operation = None;
	}

	void Proc<C>::OptnRun()
	{
		switch (Operation)
		{
		case Add: {
			Lop_Res = Lop_Res + Rop;
			break;
		}
		case Sub: {
			Lop_Res = Lop_Res - Rop;
			break;
		}
		case Mul: {
			Lop_Res = Lop_Res * Rop;
			break;
		}
		case Dvd: {
			Lop_Res = Lop_Res / Rop;
			break;
		}
		default:
			break;
		}
	}
	void Proc<C>::FuncRun()
	{
		switch (Operation)
		{
		case Rev: {
			Rop = Rop.reverse();
			break;
		}
		case Sqr: {
			Rop = sqrt(Rop);
			break;
		}
		default:
			break;
		}
	}
	C Proc<C>::getLeft()
	{
		return Lop_Res;
	}

	void Proc<C>::setLeft(C Operand)
	{
		Lop_Res = Operand;
	}

	C Proc<C>::getRight()
	{
		return Rop;
	}
	void Proc<C>::setRight(C Operand)
	{
		Rop = Operand;
	}

	int Proc<C>::getOptn()
	{
		return Operation;
	}

	void Proc<C>::setOptn(int Oprtn)
	{
		Operation = Oprtn;
	}
};

