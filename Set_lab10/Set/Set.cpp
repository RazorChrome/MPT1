#include "stdafx.h"
#include "Set.h"

template<class T>
Set<T>::Set()
{
}

template<class T>
Set<T>::~Set()
{
	container.clear();
}

template<class T>
void Set<T>::clear() {
	container.clear();
}

template<class T>
inline void Set<T>::add(T newElem) {
	container.insert(newElem);
}

template<class T>
void Set<T>::del(T toDelElem) {
	if (container.count(toDelElem))
		container.erase(toDelElem);
}

template<class T>
bool Set<T>::isEmpty() {
	return container.size() == 0;
}

template<class T>
bool Set<T>::contains(T elem) {
	return container.count(elem);
}

template<class T>
Set<T> Set<T>::merge(const Set<T> &otherSet) {
	Set<T> result = *this;
	for (const T &elem : otherSet.container)
		result.add(elem);
	return result;
}

template<class T>
Set<T> Set<T>::diff(const Set<T> &otherSet) {
	Set<T> result = *this;
	for (const T &elem : otherSet.container)
		if (result.container.count(elem))
			result.del(elem);
	return result;
}

template<class T>
Set<T> Set<T>::cross(const Set<T> &otherSet) {
	Set<T> result;
	for (const T &elem : otherSet.container)
		if (container.count(elem))
			result.add(elem);
	return result;
}

template<class T>
int Set<T>::count() {
	return container.size();
}

template<class T>
T Set<T>::elem(int elemNumber) {
	if (elemNumber < 0 || elemNumber >= container.size()) {
		return T();
	}
	auto it = container.begin();
	for (int i = 0; i < elemNumber; ++i) {
		++it;
	}
	return *it;
}