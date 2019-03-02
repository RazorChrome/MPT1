#pragma once
#include <set>
#include <algorithm>
using namespace std;

template <class T>
class Set{
private:
	set<T> container;
public:
	Set();
	~Set();

	void clear();
	void add(T newElem);
	void del(T toDelElem);
	bool isEmpty();
	bool contains(T elem);
	Set<T> merge(const Set<T> &otherSet);
	Set<T> diff(const Set<T> &otherSet);
	Set<T> cross(const Set<T> &otherSet);
	int count();
	T elem(int elemNumber);
};