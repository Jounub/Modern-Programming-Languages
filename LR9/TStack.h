#pragma once
#include <iostream>
#include <cstddef>

template <class T>
class Tstack {
	public:
		T* st;
		int size;
		int numItem;
		T* item;
		Tstack(size_t s = 10)
		{
			size = static_cast<int>(s);
			numItem = 0;
			item = new T[size];
			st = item;
		}
		~Tstack()
		{
			delete[] item;
		}
		void push (T t);
		T pop();
		T top();
		bool empty();
		bool full();
		T peek();
		void print();

};

template <class T>
void Tstack <T>::push(T t)
{
	if (numItem >= size) {
		// expand capacity
		int newSize = (size > 0) ? size * 2 : 1;
		T* newItem = new T[newSize];
		for (int i = 0; i < numItem; ++i) newItem[i] = item[i];
		delete[] item;
		item = newItem;
		st = item;
		size = newSize;
	}
	item[numItem++] = t;
}
template <class T>
T Tstack <T>::pop()
{
	if (!empty()) {
		return item[--numItem];
	}
	else {
		std::cout << "Stack is empty!" << std::endl;
		return T();
	}
}

template <class T>
T Tstack <T>::top()
{
	if (!empty()) {
		return item[numItem - 1];
	}
	std::cout << "Stack is empty!" << std::endl;
	return T();
}

template <class T>
bool Tstack <T>::empty()
{
	return numItem == 0;
}

template <class T>
bool Tstack <T>::full()
{
	return numItem >= size;
}

template <class T>
T Tstack <T>::peek()
{
	if (!empty()) {
		return st[numItem - 1];
	}
	else {
		std::cout << "Stack is empty!" << std::endl;
		return T();
	}
}

template <class T>
void Tstack <T>::print()
{
	if (empty()) {
		std::cout << "Stack is empty" << std::endl;
		return;
	}

	std::cout << "Stack (top to bottom): ";
	for (int i = numItem - 1; i >= 0; i--) {
		std::cout << st[i] << " ";
	}
	std::cout << std::endl;
}
