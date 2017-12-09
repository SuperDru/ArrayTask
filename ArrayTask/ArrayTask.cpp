#include <iostream>
#include "Header.h"
#include "Array.h"

using namespace std;

int main() {
	try {
		//Array * P = new Array;
		int arr[6] = { 1, 3, 4, 5 ,-2, 6 };
		int arr2[3] = { 1, 3, 4 };
		Array mas1(6, arr);
		Array mas2(3, arr2);
		cout << (mas1 < mas2) << endl;
		cout << (mas1 > mas2) << endl;
		cout << (mas1 == mas2) << endl;
		mas1 = mas1 + mas2 + mas1;
		cout << mas1;
		cout << (mas1 - 5 + 5);
	}
	catch (char* e) {
		cout << e;
	}

	_getch();
	return 0;
}