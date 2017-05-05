#pragma once
#include "DLL_Node.h"

class DLL {
private:
	DLL_Node* head = NULL;
	DLL_Node* tail = NULL;
public:
	/**
		Creates and inserts DLL_Node at the head of DLL.
		@param val The value to store in the data field of the new node.
	*/
	void insert_at_head(int val);

	/**
		Creates and inserts DLL_Node at the tail of DLL.
		@param val The value to store in the data field of the new node.
	*/
	void insert_at_tail(int val);

	/**
		Removes a node with the given data value from DLL. 
		Nothing happens if there is no node with the given value.
		@param val The data value in the node to remove
	*/
	void remove_from_head(int val);

	/**
		Outputs the data values of the DLL in order from head to tail.
	*/
	void print_from_head();
};
