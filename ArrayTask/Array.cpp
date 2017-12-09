#include "Array.h"

int amount = 0;

Array::Array(const Array &mas) { 
	this->size = mas.size; // =
	this->mas = new int[size];
	if (this->mas == NULL)
		throw "OverflowMemoryException";
	for (int i = 0; i < this->size; i++) {
		this[i] = mas[i];
	}
}

Array::Array(int size, int *mas) {
	if (size < 0)
		throw "ArraySizeException";
	this->mas = new int[size];
	if (this->mas == NULL)
		throw "OverflowMemoryException";
	this->size = size;
	for (int i = 0; i < this->size; i++) {
		(this->mas)[i] = mas[i];
	}
}

Array::Array(int size) {
	if (size < 0)
		throw "ArraySizeException";
	this->mas = new int[size];
	if (this->mas == NULL)
		throw "OverflowMemoryException";
	for (int i = 0; i < size; i++) {
		mas[i] = 0;
	}
	this->size = size;
}


Array::~Array()
{
	delete[]mas;
	cout << "Array was deleted." << endl;
}

void Array::print() { 
	cout << "[";
	for (int i = 0; i < this->size - 1; i++) {
		cout << mas[i] << ", ";
	}
	cout << mas[this->size - 1] << "]";
	cout << endl;
}

ostream& operator<<( ostream &stream,const Array &arr) {
	stream << "[";
	for (int i = 0; i < arr.size - 1; i++) {
		stream << arr[i] << ", ";
	}
	stream << arr[arr.size - 1] <<"]";
	stream << endl;
	return stream;
}

int& Array::operator[](int i) const{	
	if (i > size || i < 0)
		throw "ArrayIndexOutOfBoundsException";
	return mas[i];
}

Array& Array::operator=(const Array &arr) {
	// this != &arr
	this->size = arr.size;
	delete[]this->mas; //
	this->mas = new int[size];
	if (this->mas == NULL)
		throw "OverflowMemoryException";
	for (int i = 0; i < this->size; i++) {
		mas[i] = arr[i];
	}
	return *this;
}

bool Array::operator<(const Array &arr) {
	return this->size < arr.size;
}

bool Array::operator>(const Array &arr) {
	return this->size > arr.size;
}

bool Array::operator==(const Array &arr) {
	if (arr.size != this->size)
		return false;
	for (int i = 0; i < this->size; i++) {
		if (arr[i] != (*this)[i])
			return false;
	}
	return true;
}

Array& Array::operator+(int c) const{
	Array *temp = new Array(this->size);
	for (int i = 0; i < this->size; i++) {
		(*temp)[i] = (*this)[i] + c;
	}
	return *temp;
}

Array& Array::operator-(int c) const {
	return (*this) + -c;
}



Array& Array::operator+(const Array &arr) const{
	Array *temp = new Array(this->size + arr.size);
	for (int i = 0; i < this->size; i++) {
		(*temp)[i] = (*this)[i];
	}
	for (int i = this->size; i < (this->size + arr.size); i++) {
		(*temp)[i] = arr[i - this->size];
	}
	return *temp;
}


