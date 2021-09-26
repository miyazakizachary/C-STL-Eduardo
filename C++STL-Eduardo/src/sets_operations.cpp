#include "stl_operations.h"

#include <iostream>
#include <set>
#include <unordered_set>

using namespace std;

void SetOperations() {
	set<int> set_numbers;
	int num = 0;

	cout << "Set operation: Push back (duplicates will be unaffected)..." << endl;
	while (num >= 0) {
		cout << "Enter the number: ";
		cin >> num;
		if (num >= 0) {
			set_numbers.insert(num);
		}
	}

	cout << "Set before removal (automatically ordered): { ";
	for (auto it = set_numbers.begin(); it != set_numbers.end(); it++) {
		cout << *it << " ";
	}
	cout << " }" << endl;

	num = 0;
	while (num >= 0) {
		cout << "Remove the content: ";
		cin >> num;
		if (num >= 0) {
			set_numbers.erase(num);
		}
	}

	cout << "Set after removal (automatically ordered): { ";
	for (auto n : set_numbers) {
		cout << n << " ";
	}
	cout << " }" << endl;
}

void MultiSetOperations() {
	multiset<int> set_numbers;
	int num = 0;

	cout << "Multi Set operation: Push back(duplicates will unaffected)..." << endl;
	while (num >= 0) {
		cout << "Enter the number: ";
		cin >> num;
		if (num >= 0) {
			set_numbers.insert(num);
		}
	}

	cout << "Multi Set before removal (automatically ordered): { ";
	for (auto it = set_numbers.begin(); it != set_numbers.end(); it++) {
		cout << *it << " ";
	}
	cout << " }" << endl;

	num = 0;
	while (num >= 0) {
		cout << "Remove the content: ";
		cin >> num;
		if (num >= 0) {
			set_numbers.erase(num);
		}
	}

	cout << "Multi Set after removal (automatically ordered): { ";
	for (auto n : set_numbers) {
		cout << n << " ";
	}
	cout << " }" << endl;
}

void UnorderedSetOperations() {
	unordered_set<int> set_numbers;
	int num = 0;

	cout << "Unordered Set operation: Push back (duplicates will be unaffected)..." << endl;
	while (num >= 0) {
		cout << "Enter the number: ";
		cin >> num;
		if (num >= 0) {
			set_numbers.insert(num);
		}
	}

	cout << "Unordered Set before removal (unordered): { ";
	for (auto it = set_numbers.begin(); it != set_numbers.end(); it++) {
		cout << *it << " ";
	}
	cout << " }" << endl;

	num = 0;
	while (num >= 0) {
		cout << "Remove the content: ";
		cin >> num;
		if (num >= 0) {
			set_numbers.erase(num);
		}
	}

	cout << "Unordered Set after removal (unordered): { ";
	for (auto n : set_numbers) {
		cout << n << " ";
	}
	cout << " }" << endl;
}

void UnorderedMultiSetOperations() {
	unordered_multiset<int> set_numbers;
	int num = 0;

	cout << "Unordered Multi Set operation: Push back(duplicates will unaffected)..." << endl;
	while (num >= 0) {
		cout << "Enter the number: ";
		cin >> num;
		if (num >= 0) {
			set_numbers.insert(num);
		}
	}

	cout << "Unordered Multi Set before removal (unordered): { ";
	for (auto it = set_numbers.begin(); it != set_numbers.end(); it++) {
		cout << *it << " ";
	}
	cout << " }" << endl;

	num = 0;
	while (num >= 0) {
		cout << "Remove the content: ";
		cin >> num;
		if (num >= 0) {
			set_numbers.erase(num);
		}
	}

	cout << "Unordered Multi Set after removal (unordered): { ";
	for (auto n : set_numbers) {
		cout << n << " ";
	}
	cout << " }" << endl;
}
