#pragma once
#include "Header.h"

class Array
{
private:
	int size, 
		*mas;
public:
	Array(const Array &mas);
	Array(int size, int *mas);
	Array(int size);
	~Array();
	void print();
	int& operator[](int i) const;
	Array& operator=(const Array &arr);
	bool operator<(const Array &arr);
	bool operator>(const Array &arr);	
	bool operator==(const Array &arr);
	Array& operator+(const Array &arr) const;
	Array& operator+(int c) const;
	Array& operator-(int c) const;
	friend ostream& operator<<(ostream &stream,const Array &arr);
};

