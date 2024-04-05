#include <iostream>
#include "queue.h"
#include <vector>
#include "functions.h"
using namespace std;

int main() {

	//Initialize int queue and push 10 integers.

	Queue<int> numbers;
	
	for (int i = 0; i < 10; i++) {
		numbers.push(i);
	}
	
	//Demonstrates the intial queue contents, and then shows it after using "move to rear" function

	cout << "Numbers in queue: " << endl;
	numbers.print();
	cout << endl;
	cout << "The queue using the 'move to rear' function:";
	numbers.move_to_rear();
	cout << endl;
	numbers.print();

	//Demonstrates the linear search function, the number 1 being the target.

	cout << endl;
	cout << "Vector that will be used for linear search (finds last instance of target): " << endl;
	cout << "{1, 3, 3, 6, 3, 2, 1, 2}" << endl;
	cout << "Target number is 1. Function results:" << endl;
	vector<int> lSearchExample = { 1, 3, 3, 6, 3, 2, 1, 2 };
	int target = 1;

	int result_int = linear_search(lSearchExample, target, lSearchExample.size() - 1); 
	if (result_int != -1) {
		cout << "Last instance of target found at index: " << result_int << endl;
	}

	//Shows the linear sort example.

	vector<int> sortExample = {5, 4, 3, 2, 1};

	cout << endl;
	cout << "Vector that will be used for insertion sort:" << endl;
	cout << "{5, 4, 3, 2, 1}" << endl;
	cout << "Function results (sorted vector):" << endl;
	insertion_sort(sortExample);

	for (int i = 0; i < sortExample.size(); i++) {
		cout << sortExample[i] << " ";
	}
	cout << endl;

	


}