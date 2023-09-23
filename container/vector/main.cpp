
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <bits/stdc++.h>
#include <string>

#include "vector.h"

template class Vector<int>;
template class Vector<double>;
template class Vector<float>;

template <typename T>
Vector<T>::Vector() : m_size(0), m_capacity(0), next(0) {};
template <typename T>
Vector<T>::~Vector() {
	delete[] m_ptr;
}
template <typename T>
Vector<T>::Vector(const Vector<T>& obj) {
	m_size = obj.m_size;
	m_ptr = new T[m_size];
	for (int i = 0; i < m_size; i++) {
		m_ptr[i] = obj.m_ptr[i];
	}
}
template <typename T>
Vector<T>::Vector(Vector<T>&& obj) {
	std::cout << "Vector move con-tor" << std::endl;
	m_size = obj.m_size;
	m_ptr = obj.m_ptr;
	obj.m_ptr = nullptr;
	obj.m_size = 0;
}
template <typename T>
Vector<T>& Vector<T>::operator = (const Vector<T>& obj) {
	if (this != &obj) {
		delete[] m_ptr;
		m_ptr = nullptr;
		m_size = obj.m_size;
		m_ptr = new T[m_size];
		for (int i = 0; i < m_size; i++) {
			m_ptr[i] = obj.m_ptr[i];
		}
	}
	return *this;
}
template <typename T>
Vector<T>& Vector<T>::operator = (Vector<T>&& obj) {
	std::cout << "Vector op. move assign." << std::endl;
	if (this != &obj) {
		delete[] m_ptr;
		m_ptr = nullptr;
		m_size = obj.m_size;
		m_ptr = obj.m_ptr;
		obj.m_ptr = nullptr;
		obj.m_size = 0;
	}
	return *this;
}
template <typename T>
T& Vector<T>::operator[] (int i) {
	if (i >= m_size || i < 0) {
		std::cout << "The number is out of range" << std::endl << std::endl;
		exit(0);
	}
	else {
		return m_ptr[i];
	}
}
template <typename T>
T& Vector<T>::at(int i) {
	if (i >= m_size || i < 0) {
		throw "Error";
	}
	else {
		return m_ptr[i];
	}

}
template <typename T>
int Vector<T>::size() {
	return m_size;
}
template <typename T>
T Vector<T>::gen_element(int x) {
	if (x >= m_size || x < 0) {
		std::cout << "The index is out of range" << std::endl << std::endl;
		exit(0);
	}
	else {
		return m_ptr[x];
	}
}
template <typename T>
void Vector<T>::push_back(const T& item) {
	m_size++;
	if (m_size - 1 == m_capacity) {
		m_capacity = m_size * 2;
		T* temp = m_ptr;
		m_ptr = new T[m_capacity];
		for (int i = 0; i < m_size - 1; i++) {
			m_ptr[i] = temp[i];
		}
		delete[] temp;
		temp = nullptr;

	}
	m_ptr[m_size - 1] = item;
}
template <typename T>
void Vector<T>::insert(int index, const T& item) {
	if (index == m_size) {
		push_back(item);
	}
	else if (index < m_size&& index >= 0) {
		m_size++;
		if (m_size - 1 == m_capacity) {
			m_capacity = m_size * 2;
			T* temp = m_ptr;
			m_ptr = new T[m_capacity];
			for (int i = 0; i < index; i++) {
				m_ptr[i] = temp[i];
			}
			for (int i = m_size - 1; i > index; i--) {
				m_ptr[i] = temp[i - 1];
			}
			m_ptr[index] = item;
			delete[] temp;
			temp = nullptr;

		}
		else {
			for (int i = m_size - 1; i > index; i--) {
				m_ptr[i] = m_ptr[i - 1];
			}
			m_ptr[index] = item;
		}
	}
	else {
		std::cout << "Invalid index for insert: " << index << "." << std::endl;
	}
}
template <typename T>
void Vector<T>::pop_back() {
	if (m_size > 0) {
		m_size--;
	}
	else {
		std::cout << "The vector is empty." << std::endl;
	}
}
template <typename T>
void Vector<T>::erase(int index) {
	if (index == m_size - 1) {
		m_size--;
	}
	else if (index < m_size - 1 && index >= 0) {
		for (int i = index; i < m_size; i++) {
			m_ptr[i] = m_ptr[i + 1];
		}
		m_size--;

	}
	else {
		std::cout << "Invalid index for erase: " << index << "." << std::endl;
	}
}
template <typename T>
void Vector<T>::clear() {
	m_size = 0;
}
template <typename T>
void Vector<T>::print() {
	if (m_size > 0) {
		std::cout << "{ ";
		for (int i = 0; i < m_size - 1; i++) {
			std::cout << m_ptr[i] << ", ";
		}
		std::cout << m_ptr[m_size - 1] << " }";
	}
	else {
		std::cout << "The vector is empty." << std::endl;
	}
}
template <typename T>
void Vector<T>::swap(T& a, T& b) {
	int temp = a;
	a = b;
	b = temp;
}
template <typename T>
void Vector<T>::buble_sort() {
	bool sorted = true;
	for (int g = 0; g < m_size - 1; g++) {
		for (int i = 0; i < m_size - 1;) {
			if (m_ptr[i] > m_ptr[i + 1]) {
				swap(m_ptr[i], m_ptr[i + 1]);
				sorted = false;
			}
			else {
				i++;
			}
		}
		if (sorted) {
			break;
		}
		sorted = true;
	}
}

template <typename T>
void Vector<T>::merge(int left, int middle, int right) {
	int size_1 = middle - left + 1;
	next++;
	int size_2 = right - middle;
	next++;

	int* vec1 = new int[size_1];
	int* vec2 = new int[size_2];

	for (int i = 0; i < size_1; i++) {
		vec1[i] = m_ptr[left + i];
		next++;
	}

	for (int i = 0; i < size_2; i++) {
		vec2[i] = m_ptr[middle + i + 1];
		next++;

	}

	int i = 0;
	next++;

	int j = 0;
	next++;

	int k = left;
	next++;

	while (i < size_1 && j < size_2) {
		if (vec1[i] <= vec2[j]) {
			m_ptr[k] = vec1[i];
			i++;
		}
		else {
			m_ptr[k] = vec2[j];
			next++;
			j++;
		}
		k++;

	}

	while (i < size_1) {
		m_ptr[k] = vec1[i];
		next++;
		i++;
		k++;
	}

	while (j < size_2) {
		m_ptr[k] = vec2[j];
		next++;
		j++;
		k++;
	}
}

template <typename T>
void Vector<T>::merge_sort() {
	next = 0;
	merge_sort_rec(0, m_size - 1);
}

template <typename T>
void Vector<T>::merge_sort_rec(int left, int right) {
	if (left < right) {
		int middle = left + (right - left) / 2;
		next++;
		merge_sort_rec(left, middle);
		merge_sort_rec(middle + 1, right);
		merge(left, middle, right);
	}
}

void print_unrdered_set(std::unordered_set<int> set_i) {
	for (int item : set_i) {
		std::cout << item << " ";
	}
}

int main() {

	srand(time(NULL));
	Vector<int> vector;
	vector.push_back(47);
	vector.push_back(10);
	vector.push_back(46);
	vector.push_back(45);
	vector.push_back(12);
	vector.push_back(17);
	vector.push_back(57);
	vector.push_back(-1);

	vector.print();
	std::cout << std::endl;

	vector.merge_sort();
	vector.print();
	std::cout << std::endl;

	try {
		std::cout << vector.at(20) << std::endl;
	}
	catch (...) {
		std::cout << "The index is out of range." << std::endl << std::endl;
	}
	return 0;
}


