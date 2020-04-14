#ifndef VECTOR_CPP
#define VECTOR_CPP
#include<iostream>
#include<assert.h>
#include "Vector.h"

#define NO_FREE_MEM_ERR "Error: No free memory!"

template<typename T>
Vector<T>::~Vector() {
	this->deleteInternals();
};

template<typename T>
T& Vector<T>::operator[](const unsigned int& index) {
	assert(index >= 0 && index < this->size);

	return this->data[index];
}

template<typename T>
const T& Vector<T>::operator[](const unsigned int& index) const {
	assert(index >= 0 && index < this->size);

	return this->data[index];
}

template<typename T>
unsigned int Vector<T>::getSize() const {
	return this->size;
}

template<typename T>
unsigned int Vector<T>::getCapacity() const {
	return this->capacity;
}

template<typename T>
void Vector<T>::reserve() {
	this->capacity = this->capacity == 0 ? 1 : this->capacity * 2;

	this->copy(*this);
}

template<typename T>
Vector<T>::Vector(const unsigned int& capacity) : size(0), capacity(capacity), data(nullptr) {
	assert(capacity > 0);

	this->size = 0;
	this->capacity = capacity;
	this->reserve();
}

template<typename T>
void Vector<T>::copy(const Vector<T>& other) {
	this->size = other.size;
	this->capacity = other.capacity;

	T* newArr = new (std::nothrow) T[this->capacity];
	if (newArr == nullptr) {
		throw NO_FREE_MEM_ERR;
	}

	for (unsigned int i = 0; i < other.size; i++)
	{
		newArr[i] = other.data[i];
	}

	this->deleteInternals();
	this->data = newArr;
}



template<typename T>
Vector<T>::Vector(const Vector<T>& other) : size(0), capacity(0), data(nullptr) {
	if (this != &other) {
		this->copy(other);
	}
}

template<typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other) {
	if (this != &other) {
		this->copy(other);
	}

	return *this;
}

template<typename T>
Vector<T>::Vector(std::initializer_list<T> list) : size(0), capacity(0), data(nullptr) {
	for (const T* it = begin(list); it != end(list); ++it) {
		this->pushBack(*it);
	}
}

template<typename T>
bool Vector<T>::isFull() const {
	return this->getSize() == this->getCapacity();
}

template<typename T>
bool Vector<T>::isEmpty() const {
	return this->getSize() == 0;
}

template<typename T>
bool Vector<T>::pushBack(const T& value) {
	if (this->isFull()) {
		this->reserve();
	}
	this->data[this->size++] = value;

	return true;
}

template<typename T>
bool Vector<T>::popBack() {
	if (this->isEmpty()) {
		return false;
	}
	this->size--;
	return true;
}

template<typename T>
int Vector<T>::indexOf(const T& item) const {
	for (unsigned int i = 0; i < this->size; i++)
	{
		if (this->data[i] == item) {
			return i;
		}
	}
	return -1;
}

template<typename T>
void Vector<T>::print() const {
	std::cout << "[";
	for (unsigned int i = 0; i < this->size; i++)
	{
		if (i == this->size - 1) {
			std::cout << this->data[this->size - 1];
			continue;
		}

		std::cout << this->data[i] << ",";
	}
	std::cout << "]" << std::endl;
}

template<typename T>
void Vector<T>::deleteInternals() {
	delete[] this->data;
}

#endif