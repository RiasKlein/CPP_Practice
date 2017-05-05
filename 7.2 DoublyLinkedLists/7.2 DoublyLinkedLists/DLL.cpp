#include "DLL.h" 
#include <iostream>
using namespace std;

/**
	Outputs data fields of nodes from head to tail
*/
void DLL::print_from_head() {
	// Start our iterator with the DLL's head
	DLL_Node* iter = this->head;

	while (iter != NULL) {
		cout << iter->data << endl;
		iter = iter->next;
	}
}

/*
	Creates and inserts a new node at the head of the doubly linked list
	@param val The data to store in the new node
*/
void DLL::insert_at_head(int val) {
	// Create the new node
	DLL_Node* new_node = new DLL_Node(val);

	// Check if our DLL head is currently NULL to determine insertion method
	if (this->head == NULL) {
		// Our current head is NULL, just set our new node as the head
		this->head = new_node;
		this->tail = new_node;
	}
	else {
		// Set the new node's next ptr to our current head
		new_node->next = this->head;
		// Set our current head's previous ptr to new_node
		this->head->prev = new_node;
		// Update the DLL's ptr to head
		this->head = new_node;
	}
}

/*
	Creates and inserts a new node at the tail of the doubly linked list
	@param val The data to store in the new node
*/
void DLL::insert_at_tail(int val) {
	// Create the new node
	DLL_Node* new_node = new DLL_Node(val);

	// Check if our current DLL's tail is NULL to determine insertion method
	if (this->tail == NULL) {
		// Our current tail is NULL, just set our new node as the tail
		this->head = new_node;
		this->tail = new_node;
	}
	else {
		// Set our current tail's next to new_node
		this->tail->next = new_node;
		// Set new_node's previous to the current tail
		new_node->prev = this->tail;
		// Update the DLL's ptr to tail
		this->tail = new_node;
	}
}

/*
	Removes node with the given value that is closest to head
	@param val Data value to identify node to remove
*/
void DLL::remove_from_head(int val) {
	// Iterator starts at the head of the DLL
	DLL_Node* iter = this->head;

	while (iter != NULL) {
		if (iter->data == val) {
			// We found the desired node, now we just need to remove it
			// Update left side
			if (iter->prev == NULL) {
				// This is the head
				this->head = iter->next;
			}
			else {
				iter->prev->next = iter->next;
			}
			// Update right side
			if (iter->next == NULL) {
				// This is the tail
				this->tail = iter->prev;
			}
			else {
				iter->next->prev = iter->prev;
			}
			// Delete the target node
			delete iter;
			return;
		}
		iter = iter->next;
	}
}
