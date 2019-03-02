#pragma once
#include <set>
#include <algorithm>


template <class T>
class iSet : public set<T>
{
public:
	//clear
	//add = insert
	//del = erase
	//isEmpty == empty
	bool contains(T elem);
	iSet<T> merge(const iSet<T> &otherSet);
	iSet<T> diff(const iSet<T> &otherSet);
	iSet<T> cross(const iSet<T> &otherSet);
	//count = count
	T elem(int elemNumber);
	iSet();
	virtual ~iSet();
};

template<class T>
inline bool iSet<T>::contains(T elem)
{
	return count(elem);
}

template<class T>
inline iSet<T> iSet<T>::merge(const iSet<T>& otherSet)
{
	iSet<T> result = *this;
	for (const T &elem : otherSet)
		result.insert(elem);
	return result;
}

template<class T>
inline iSet<T> iSet<T>::diff(const iSet<T>& otherSet)
{
	iSet<T> result = *this;
	for (const T &elem : otherSet)
		if (result.count(elem))
			result.erase(elem);
	return result;
}

template<class T>
inline iSet<T> iSet<T>::cross(const iSet<T>& otherSet)
{
	iSet<T> result;
	for (const T &elem : otherSet)
		if (count(elem))
			result.insert(elem);
	return result;
}

template<class T>
inline T iSet<T>::elem(int elemNumber)
{
	if (elemNumber < 0 || elemNumber >= size()) {
		return T();
	}
	auto it = begin();
	for (int i = 0; i < elemNumber; ++i) {
		++it;
	}
	return *it;
}

template <class T>
iSet<T>::iSet()
{
}

template <class T>
iSet<T>::~iSet()
{
	clear();
}
