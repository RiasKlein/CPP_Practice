/*
	Write a program to reverse an integer using only mathematical operators
*/
#include <iostream>

using namespace std;

int reverse_int(int input);

int main() {
	int original = 621;
	cout << reverse_int(original) << endl;
	return 0;
}

/*
	Reverses a positive int using modulo, addition, multiplication, and division
*/
int reverse_int(int input) {
	int reversed = 0;
	while (input > 0) {
		reversed = ((reversed + (input % 10)) * 10);
		input /= 10;
	}
	return (reversed / 10);
}