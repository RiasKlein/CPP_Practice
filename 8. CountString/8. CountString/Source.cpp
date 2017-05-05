/*
	Write a program to count the number of occurrences of a letter in a string.
*/
#include <iostream>		// cout, endl
#include <string>		// string
#include <algorithm>	// count

using namespace std;

int count_string_for_char(string str, char target);
int count_string_for_char_v2(string str, char target);
int count_string_for_char_v3(string str, char target);

int main() {
	string str = "Hello";
	char target = 'l';

	cout << count_string_for_char_v3(str, target) << endl;

	return 0;
}

/*
	Returns the number of times the target char occurs in the given string.
	This requires the algorithm library: #include <algorithm>
	@param str The string to check for the target char
	@param target The char to look for in the given string
	@return The number of times the target char occurs in the given string
*/
int count_string_for_char_v3(string str, char target) {
	return count(str.begin(), str.end(), target);
}

/*
	Returns the number of times the target char occurs in the given string.
	@param str The string to check for the target char
	@param target The char to look for in the given string
	@return The number of times the target char occurs in the given string
*/
int count_string_for_char_v2(string str, char target) {
	int count = 0;

	for (char a : str) {
		if (a == target) {
			count++;
		}
	}
	return count;
}

/*
	Returns the number of times the target char occurs in the given string.
	@param str The string to check for the target char
	@param target The char to look for in the given string
	@return The number of times the target char occurs in the given string
*/
int count_string_for_char(string str, char target) {
	int count = 0;

	for (int i = 0; i < str.length(); i++) {
		char cur = str[i];
		if (cur == target) {
			count++;
		}
	}
	return count;
}