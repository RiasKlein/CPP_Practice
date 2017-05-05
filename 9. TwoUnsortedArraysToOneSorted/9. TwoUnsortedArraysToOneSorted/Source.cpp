/*
	Create a program in which two unsorted int arrays are merged into a single sorted int array.
*/

#include <iostream>		// cout, endl
#include <algorithm>	// sort
#include <vector>		// vector

using namespace std;

int main() {
	int arr1[] = { 5, 3, 7, 1 };
	int arr2[] = { 6, 2, 4, 9 };

	// Convert int arrays above into vectors
	vector<int> temp;

	// Push both unsorted arrays into the temp vector
	for (int i : arr1) {
		temp.push_back(i);
	}

	for (int i : arr2) {
		temp.push_back(i);
	}

	// Sort the temp vector
	sort(temp.begin(), temp.end());

	// Extract the vector data into an int array
	int* sorted_array = temp.data();
	
	// Output the int array to verify functionality
	for (int i = 0; i < 8; i++) {
		cout << sorted_array[i] << endl;
	}

	return 0;
}