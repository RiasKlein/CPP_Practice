#pragma once

/*
	Class: LLNode
	The data is private and requires a get function to retrieve the data
	The data is set at initialization
*/
class LLNode {
private:
	int data;

public:
	LLNode* next = 0;

	int get_data() {
		return data;
	}

	LLNode(int a) : data(a) {}

	LLNode(int a, LLNode* ptr) : data(a), next(ptr) {}
};
