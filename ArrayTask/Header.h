#pragma once
#include <iostream>
#include <conio.h>

using namespace std;

template <class T>
class Array {
private:
	int size;
	T *mas;
public:
	Array(const Array &mas) {
		this->size = mas.size;
		this->mas = new T[size];
		if (this->mas == NULL)
			throw "OverflowMemoryException";
		for (int i = 0; i < this->size; i++) {
			this[i] = mas[i];
		}
	}

	Array(int size, T *mas) {
		if (size < 0)
			throw "ArraySizeException";
		this->mas = new T[size];
		if (this->mas == NULL)
			throw "OverflowMemoryException";
		this->size = size;
		for (int i = 0; i < this->size; i++) {
			(this->mas)[i] = mas[i];
		}
	}

	Array(int size) {
		void* temp;
		if (size < 0)
			throw "ArraySizeException";
		this->mas = new T[size];
		if (this->mas == NULL)
			throw "OverflowMemoryException";
		this->size = size;
	}

	~Array()
	{
		delete[]mas;
		cout << "Array was deleted." << endl;
	}

	void print() {
		cout << "[";
		for (int i = 0; i < this->size - 1; i++) {
			cout << mas[i] << ", ";
		}
		cout << mas[this->size - 1] << "]";
		cout << endl;
	}

	friend ostream& operator<<(ostream &stream, const Array<T> &arr) {
		stream << "[";
		for (int i = 0; i < arr.size - 1; i++) {
			stream << arr[i] << ", ";
		}
		stream << arr[arr.size - 1] << "]";
		stream << endl;
		return stream;
	}

	T& operator[](int i) const {
		if (i > size || i < 0)
			throw "ArrayIndexOutOfBoundsException";
		return mas[i];
	}

	Array<T>& operator=(const Array &arr) {
		this->size = arr.size;
		delete[]this->mas;
		this->mas = new T[size];
		if (this->mas == NULL)
			throw "OverflowMemoryException";
		for (int i = 0; i < this->size; i++) {
			mas[i] = arr[i];
		}
		return *this;
	}

	bool operator<(const Array &arr) {
		return this->size < arr.size;
	}

	bool operator>(const Array &arr) {
		return this->size > arr.size;
	}

	bool operator==(const Array &arr) {
		if (arr.size != this->size)
			return false;
		for (int i = 0; i < this->size; i++) {
			if (arr[i] != (*this)[i])
				return false;
		}
		return true;
	}

	//Array<T>& operator+(T c) const {
	//	Array *temp = new Array(this->size);
	//	for (int i = 0; i < this->size; i++) {
	//		(*temp)[i] = (*this)[i] + c;
	//	}
	//	return *temp;
	//}

	//Array<T>& operator-(T c) const {
	//	return (*this) + -c;
	//}

	Array<T>& operator+(const Array<T> &arr) const {
		Array *temp = new Array(this->size + arr.size);
		for (int i = 0; i < this->size; i++) {
			(*temp)[i] = (*this)[i];
		}
		for (int i = this->size; i < (this->size + arr.size); i++) {
			(*temp)[i] = arr[i - this->size];
		}
		return *temp;
	}
};
