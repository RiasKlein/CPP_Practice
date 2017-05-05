/**
	Doubly Linked Lists
	This implementation is incomplete and only contains functions to insert elements.
	A weakness of using only nodes is that we do not have an easy way to access
		the front and back of the linked list. If we could, that can make certain
		functions more efficient. 
	Look at the other Doubly Linked List implementation instead.
*/

#include <iostream>

using namespace std;

/**
	A node in a doubly linked list which stores int values.
*/
class DLL_Node {
public:
	int data;
	DLL_Node* next = NULL;
	DLL_Node* prev = NULL;

	DLL_Node(int);

	void insert_at_end(int value);
	DLL_Node* insert_at_head(int value, DLL_Node* head);
	void print_DLL();
};

/*
	Constructor. 
	@param a The int to set this instance's data
*/
DLL_Node::DLL_Node(int a) : data(a) {}

/*
	Creates a new DLL_Node and adds it at the end of the Linked List
	@param value Value to store in data field of Linked List node
*/
void DLL_Node::insert_at_end(int value) {
	// Create a new DLL node for the given value
	DLL_Node* new_node = new DLL_Node(value);

	DLL_Node* iter;		// Iterator to traverse DLL
	if (this -> next != NULL) {
		iter = this -> next;
		while (iter->next != NULL) {
			iter = iter->next;
		}
		new_node->prev = iter;
		iter->next = new_node;
	}
	else {
		new_node->prev = this;
		this->next = new_node;
	}
}

/*
	Creates a new DLL_Node and makes it the new head of the Linked List
	@param value The value to store in the data of the node
	@param head A pointer to the current DLL_Node at the front of the LL
	@return A pointer to the new head of the DLL
*/
DLL_Node* DLL_Node::insert_at_head(int value, DLL_Node* head) {
	// Create a new DLL node for the given value
	DLL_Node* new_node = new DLL_Node(value);
	
	new_node->next = head;
	head->prev = new_node;

	return new_node;
}

/*
	Prints out data values of all DLL nodes starting from head
*/
void DLL_Node::print_DLL() {
	// The iterator is initialized to our current DLL_Node
	DLL_Node* iter = this;

	// Until the iterator is NULL, we output the data  
	// and move the iterator to the next node
	while (iter != NULL) {
		cout << iter -> data << endl;
		iter = iter->next;
	}
}

int main() {
	DLL_Node* head = new DLL_Node(4);
	head->insert_at_end(5);
	head->insert_at_end(6);
	head = head->insert_at_head(3, head);
	head->print_DLL();
	return 0;
}