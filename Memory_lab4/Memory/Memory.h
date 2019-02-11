#pragma once
#include <string>

using namespace std;

template <class T>
class Memory
{
private:
	T Fnumber;
	bool Fstate;
public:
	Memory<T>::Memory()
	{
		Fnumber = *(new T);
		Fstate = false;
	}

	void Memory<T>::write(T n)
	{
		Fnumber = n;
		Fstate = true;
	}

	T Memory<T>::get()
	{
		return Fnumber;
	}

	void Memory<T>::add(T n)
	{
		Fnumber = Fnumber + n;
		Fstate = true;
	}

	void Memory<T>::clear()
	{
		Fnumber = *(new T);
		Fstate = false;
	}

	string Memory<T>::getState()
	{
		if (Fstate) return string("_On");
		return string("_Off");
	}
};
