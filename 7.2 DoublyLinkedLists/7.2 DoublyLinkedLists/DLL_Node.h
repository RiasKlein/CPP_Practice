#pragma once
#include <stddef.h>

class DLL_Node {
public:
	DLL_Node* prev = NULL;		// A ptr to the previous node
	DLL_Node* next = NULL;		// A ptr to the next node
	int data;					// Data stored in node

	/** 
		Constructor for DLL_Node.
		@param int Value to store in the data field of the created node
	*/
	DLL_Node(int);
};
