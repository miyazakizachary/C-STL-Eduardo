#include "stl_operations.h"
#include "persona.h"

#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

/* const promise that the PrintVector function will not modify the vector
** passing vector by reference & is to avoid to copy the whole vector
*/
template <typename T>
void PrintVector(const vector<T>& my_vector) {
	cout << "vector content: { ";
	for (const T& elem : my_vector) {
		/* num is an iterating variable works very much like a function parameter 
		   so we declaring it as a refernce and not an iterator, so no need to pass by reference */
		cout << elem << " ";
	}
	cout << " }" << endl;
}

void PrintVectorPersons(const vector<school_guest>* record) {
	auto it = record->begin();
	cout << " ------ Vector Recorda ------" << endl;
	cout << " ----------------------------" << endl;
	while (it < record->end()) {
		cout << "Name: " << it->get_name() << endl;
		cout << "Gender: " << it->get_gender() << endl;
		cout << "Age: " << it->get_age() << endl;
		it += 1;
	}
	cout << " ---------------------------- " << endl;
}

void VectorOperations() {
	vector<int> numbers;

	int val_1 = 0;
	cout << "Pushing back ..." << endl;
	while (val_1 >= 0) {
		cout << "Enter number: ";
		cin >> val_1;
		if (val_1 >= 0)
			numbers.push_back(val_1);
	}
	PrintVector(numbers);

	val_1 = 0;
	cout << "Pushing front ..." << endl;
	while (val_1 >= 0) {
		cout << "Enter the number: ";
		cin >> val_1;
		if (val_1 >= 0) {
			numbers.insert(numbers.begin(), val_1);
		}
	}
	PrintVector(numbers);

	int index = 0;
	cout << "Inserting by Index..." << endl;
	while (index >= 0) {
		cout << "Enter index: ";
		cin >> index;
		if (index >= 0) {
			cout << "Enter value: ";
			cin >> val_1;
			/* vector support random access 'numbers.begin() + index' and list is not */
			numbers.insert(numbers.begin() + index, val_1);
		}
	}
	PrintVector(numbers);

	index = 0;
	cout << "Modify existing element..." << endl;
	while (index >= 0) {
		cout << "Enter index: ";
		cin >> index;
		if (index >= 0) {
			cout << "Enter the value: ";
			cin >> val_1;
			/* vector support random access and list is not*/
			numbers[index] = val_1;
		}
	}
	PrintVector(numbers);
}

void ReadFileVectorForPersons(vector<school_guest>* record, const char * filename) {
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
		cout << "unable to open file " << filename << endl;
	}
}

void PrintVectorPersonDetailByIndex(const vector<school_guest>* record, unsigned int index) {
	auto it = record->begin();

	if ((index > record->size()) && index > 0) {
		cout << "index: " << index << " is out of range" << endl;
		cout << "vector size is: " << record->size() << endl;
	}
	else {
		cout << "----- Vector Record by Index (" << index << ")-------" << endl;
		it += index;
		if (it < record->end()) {
			cout << "Name: " << it->get_name() << endl;
			cout << "Gender: " << it->get_gender() << endl;
			cout << "Age: " << it->get_age() << endl;
		}
		else {
			cout << "record not found" << endl;
		}
	}
}

void RemoveVectorPersonDetailByIndex(vector<school_guest>* record, unsigned int index) {
	auto it = record->begin();

	if ((index > record->size()) && index > 0) {
		cout << "index: " << index << " is out of range" << endl;
		cout << "vector size is: " << record->size() << endl;
	}
	else {
		it += index;
		if (it < record->end()) {
			record->erase(it);
			PrintVectorPersons(record);
		}
		else {
			cout << "record not found" << endl;
		}
	}
}

float GetPersonAgeAverageByVector(vector<school_guest>& record) {
	// here due to we need to get the value of age without hassle of pointer dereference
	// it is safe to use reference (&) as to avoid array/vector decay to pointer's integer
	float avg = 0.00f;
	for (school_guest g : record) {
		avg += g.get_age();
	}
	avg = avg / record.size();
	return avg;
}