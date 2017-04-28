#include <algorithm>
#include <iostream>
#include <string>

/**
	Given an integer, find the next largest integer using ONLY the digits from the given integer
	For example, if you're given 1234, the expected output is 1243.
*/

// Function Prototype
int getNextLargestPermutation(int input);

int main() {
	int input[] = { 1234, 1243, 234765, 19000 };

	for (int i = 0; i < 4; i++) {
		std::cout << getNextLargestPermutation(input[i]) << std::endl;
	}

	return 0;
}

/**
	Returns the next largest permutation of the given int
	@param input int to get the next largest permutation for
	@return the next largest permutation of the given int if possible, otherwise input is returned
*/
int getNextLargestPermutation(int input) {
	std::string s = std::to_string(input);
	bool store = std::next_permutation(std::begin(s), std::end(s));
	return ((store == 0) ? input : std::stoi(s));
}