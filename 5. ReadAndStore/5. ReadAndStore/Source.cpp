#include <iostream>		// cout, endl, cin
#include <string>		// string, getline
#include <vector>		// vector

// Global variables
std::string input("Default");		// String to store inputs from stdin
std::vector<std::string> storage;	// Vector to store inputs read from stdin

// Function Prototypes
void getData();
void printData();

int main() {
	std::cout << "We will store all input you give us except an empty one." << std::endl;
	std::cout << "An empty string will terminate the reading and storing process." << std::endl;

	getData();
	printData();

	return 0;
}

/**
	Reads from stdin and stores nonempty strings into variables input and storage
	Terminates when an empty string is read from stdin
*/
void getData() {
	while (input.compare("") != 0) {		
		std::getline(std::cin, input);		// Store contents of stdin into input
		if (input.compare("") == 0) {		// Break if input was empty string
			break;
		}
		storage.push_back(input);			// Store input into storage
	}
}

/**
	Outputs the elements of storage via stdout
*/
void printData() {
	for (int i = 0; i < storage.size(); i++) {
		std::cout << "Element " << i << ": " << storage[i] << std::endl;
	}
}