/**
	Implement a Doubly Linked List.
	Required functionality:
		1. Insert a node at the front of the DLL
*/

#include <iostream>		// NULL, cout, endl
#include "DLL.h"

int main() {
	DLL mine = DLL();

	mine.insert_at_tail(4);		// 4
	mine.insert_at_tail(5);		// 4 5
	mine.insert_at_head(3);		// 3 4 5 
	mine.insert_at_head(3);		// 3 3 4 5
	mine.remove_from_head(3);	// 3 4 5 
	mine.insert_at_tail(6);		// 3 4 5 6
	mine.remove_from_head(5);	// 3 4 6 
	mine.print_from_head();

	return 0;
}
