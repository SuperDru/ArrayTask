#include <iostream>
#include "Header.h"
#include <string>

using namespace std;

int main() {
	try {
		string arr[6] = { "fg", "fg3", "he", "Best" ,"", "gdsg" };
		string arr2[3] = { "Ha", " I, ", "Am" };
		string arr3[3] = { " ", " I, ", "Am" };
		Array<string> mas1(3, arr3);
		Array<string> mas2(3, arr2);
		cout << (mas1 < mas2) << endl;
		cout << (mas1 > mas2) << endl;
		cout << (mas1 == mas2) << endl;
		mas1 = mas1 + mas2 + mas1;
		cout << mas1;
		cout << mas2;
	}
	catch (char* e) {
		cout << e;
	}

	_getch();
	return 0;
}