#include <algorithm>	// next_permutation, sort
#include <iostream>		// cout, endl
#include <vector>		// vector

/**
	Given an integer, find the next largest integer using ONLY the digits from the given integer
	For example, if you're given 1234, the expected output is 1243.
*/

// Function Prototypes
void printDigits(std::vector<int> digits);
int intVectorToInt(std::vector<int> digits);
std::vector<int> intToIntVector(int input);
int next_largest_permutation(int input);

int main() {
	int input = 19000;
	std::cout << next_largest_permutation(input) << std::endl;

	return 0;
}

/**
	Returns the next largest int permutation for the given input if possible
	@param input int to get the next largest permutation for
	@return The next largest permutation if there is one, otherwise the original input is returned
*/
int next_largest_permutation(int input) {
	std::vector<int> permutations;
	std::vector<int> digits = intToIntVector(input);

	// Sort the digits vector to prepare for permutation generation
	std::sort(digits.begin(), digits.end());

	// Generate all permutationns of the given int and store them
	do {
		permutations.push_back(intVectorToInt(digits));
	} while (std::next_permutation(digits.begin(), digits.end()));

	// Sort all the permutations
	std::sort(permutations.begin(), permutations.end());

	for (int i = 0; i < permutations.size() - 1; i++) {
		if (permutations[i] == input) {
			return permutations[i + 1];
		}
	}

	return input;
}

/**
	Converts int to a vector of digits
	@param input int to conert into digits
	@return vector of digits
*/
std::vector<int> intToIntVector(int input) {
	std::vector<int> digits;
	while (input > 0) {
		digits.push_back(input % 10);
		input /= 10;
	}
	std::reverse(digits.begin(), digits.end());
	return digits;
}

/**
	Converts given int vector of digits into an int
	@param digits ints representing digits in the vector
	@return the recreated int containing the given digits
*/
int intVectorToInt(std::vector<int> digits) {
	int ret = 0;
	int multiplier = 1;
	for (int i = digits.size() - 1; i >= 0; i--) {
		ret += digits[i] * multiplier;
		multiplier *= 10;
	}
	return ret;
}

/**
	Outputs all elements of given int vector to stdout
	@param digits ints that are stored in the vector
*/
void printDigits(std::vector<int> digits) {
	for (int i = 0; i < digits.size(); i++) {
		std::cout << digits[i];
	}
	std::cout << std::endl;
}