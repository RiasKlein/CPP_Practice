/*
	Linked Lists
	Linked List nodes are created, connected, and then printed out.
	Topics explored include object defintion, creation, and usage.
*/

#include <iostream>
#include "LL.h"

int main() {
	// This is the first node, called Papa
	LLNode Papa = LLNode(4);

	// Let's have a second node called Mama and it's connected to Papa
	// Papa --> Mama
	LLNode Mama = LLNode(5);
	Papa.next = &Mama;

	// Finally Mama has a Son and it's connected after Mama
	// Papa --> Mama --> Son
	LLNode Son = LLNode(9);
	Mama.next = &Son;

	// Let's see the links!
	// reader is a ptr to LLNode objects and we start at the address of Papa
	// We move down the Linked List and print out the data in each object
	LLNode* reader = &Papa;
	while (reader != 0) {
		std::cout << reader -> get_data() << std::endl;
		reader = reader -> next;
	}

	return 0;
}

