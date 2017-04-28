/*	Source.cpp
	Create a program that explores splitting a 8-bit integer into 2 4-bit integers
	Note: 4-bit integers are not supported in C++
*/

#include <cstdint>
#include <iostream>
#include <cmath>

// Globals
int8_t ori = 19;

// Prototypes
int8_t upper_4(int8_t ori);
int8_t lower_4(int8_t ori);
char* dec_to_binary(int8_t ori);

int main() {
	// Decimals Forms
	std::cout << "Decimal Form:" << std::endl;
	std::cout << "Upper Half: " << int(upper_4(ori)) << std::endl;
	std::cout << "Lower Half: " << int(lower_4(ori)) << std::endl;

	// Aesthetics Line Break
	std::cout << std::endl;

	// Binary Forms
	std::cout << "Binary Forms:" << std::endl;
	std::cout << "Upper Half: " << dec_to_binary(upper_4(ori)) << std::endl;
	std::cout << "Lower Half: " << dec_to_binary(lower_4(ori)) << std::endl;

	return 0;
}

/*
	upper_4
	Returns the int that is stored in the upper 4 bits of the input parameter
*/
int8_t upper_4(int8_t ori) {
	return (ori >> 4);
}

/*
	lower_4
	Returns the int that is stored in the lower 4 bits of the input parameter
*/
int8_t lower_4(int8_t ori) {
	return (ori & 15);
}

/*
	dec_to_binary
	Returns the binary form of the input parameter 
*/
char* dec_to_binary(int8_t ori) {
	char* binary = (char*) malloc (sizeof (char) * 5);

	// Note: double pow (double base, double exponent) -> therefore, we used an int cast
	// Note: bit wise 'AND' is &
	for (int i = 3; i >= 0; i--) {
		if (ori & int (pow (2, i))) {
			binary[3 - i] = '1';
		}
		else {
			binary[3 - i] = '0';
		}
	}

	binary[4] = 0; // In C++, NULL terminator is simply a 0 in the place of a char
	return binary;
}
