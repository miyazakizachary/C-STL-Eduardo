#include "stl_operations.h"

#include <fstream>
#include <iostream>
#include <list>

using namespace std;

void PrintList(const list<int>& mylist) {
	cout << "list content: { ";
	for (const int& num : mylist) {
		cout << num << " ";
	}
	cout << " }" << endl;
}	

void ListOperations() {

	list<int> numbers;
	int value = 0;

	cout << "Pushing back..." << endl;
	while (value >= 0) {
		cout << "Enter the value: ";
		cin >> value;
		if (value >= 0) {
			numbers.push_back(value);
		}
	}
	PrintList(numbers);

	value = 0;
	cout << "Pushing front..." << endl;
	while (value >= 0) {
		cout << "Enter the value: ";
		cin >> value;
		if (value >= 0) {
			/* vector does not support push_front but list have*/
			// numbers.insert(numbers.begin(), value); // also work
			numbers.push_front(value);
		}
	}
	PrintList(numbers);

	/* List does not support random access and plus operator is not supported *
	/* vector support random access 'numbers.begin() + index' and list is not */ 
	/* insertion and update of values by random access is not supported */
}

void PrintListPersons(list<school_guest>* record) {
	auto it = record->begin();
	cout << " ------List Record------- " << endl;
	cout << " ------------------------ " << endl;
	while (it != record->end()) { 
		// list do not support random access
		// operator "<" is the implication of random access, so use != operator
		cout << "Name: " << it->get_name() << endl;
		cout << "Gender: " << it->get_gender() << endl;
		cout << "Age: " << it->get_age() << endl;
		it++; //ok sequential
		// cannot use radom access like this. it must be sequential. 
		// random access can be like it += 1 or it + 5;
	}
	cout << " ------------------------ " << endl;
}

void ReadFileListForPersons(list<school_guest>* record, const char* filename) {
	string in_str;
	ifstream in_file(filename);

	if (in_file.is_open()) {
		school_guest temp;
		while (getline(in_file, in_str)) {
			temp.set_name(in_str);
			getline(in_file, in_str);
			temp.set_gender(in_str);
			getline(in_file, in_str);
			temp.set_age(stoi(in_str));
			record->push_back(temp);
		}
		in_file.close();
	}
	else {
		cout << "failed to read file: " << filename << endl;
	}
}

void PrintListPersonDetailByIndex(const list<school_guest>* record, unsigned int index) {
	auto it = record->begin();

	if (index > record->size()) {
		cout << "index: " << index << " is out of range" << endl;
		cout << "LIST size is: " << record->size() << endl;
	}
	else {
		cout << "----- LIST Record by Index (" << index << ")-------" << endl;
		int it_indicator = 0;
		while (!(index > record->size())) {
			if (it_indicator == index) {
				break;
			}
			it++;
			it_indicator++;
		}
		if (it != record->end()) {
			cout << "Name: " << it->get_name() << endl;
			cout << "Gender: " << it->get_gender() << endl;
			cout << "Age: " << it->get_age() << endl;
		}
		else {
			cout << "record not found" << endl;
		}
	}
}

void RemoveListPersonDetailByIndex(list<school_guest>* record, unsigned int index) {
	auto it = record->begin();

	if (index > record->size()) {
		cout << "index: " << index << " is out of range. Cannot print!" << endl;
		cout << "LIST size is: " << record->size() << endl;
	}
	else {
		int it_indicator = 0;
		while (!(index > record->size())) {
			it_indicator++;
			it++;
			if (it_indicator == index) {
				break;
			}
		}

		if (it != record->end()) {
			record->erase(it);
			PrintListPersons(record);
		}
		else {
			cout << "record not found" << endl;
		}
	}
}

float GetPersonAgeAverageByList(list<school_guest>& record) {
	// here due to we need to get the value of age without hassle of pointer dereference
	// it is safe to use reference (&) as to avoid array/vector decay to pointer's integer
	float avg = 0.00f;
	for (school_guest g : record) {
		avg += g.get_age();
	}
	avg = avg / record.size();
	return avg;
}