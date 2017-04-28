/*	Hello World Program
	The goal of this program is to explore how to output a string via standard output.
*/

// iostream includs cout / printf - which are used to 'print' outputs
#include <iostream>

// This is the main method
int main() {
	// We are passing the string "Hello World" into standard output
	// Then we are passing in a new line and flushing std. out by using endl
	std::cout << "Hello World" << std::endl;
	
	// Using printf instead of std::cout / std::endl
	printf("Hello World\n");

	return 0;
}