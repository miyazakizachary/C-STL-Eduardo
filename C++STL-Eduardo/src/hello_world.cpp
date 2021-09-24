#include "stl_operations.h"
#include "persona.h"

#include <iostream>
#include <vector>
#include <list>

using namespace std;

template <typename T>
int size_in_bits(const T& a) {
	return sizeof(a) * 8;
}

int main() {
	cout << "Hello World!" << endl;
	cout << size_in_bits(21) << endl;
	cout << size_in_bits(2.45f) << endl;
	cout << size_in_bits('F') << endl;
	cout << size_in_bits(32.80) << endl;

	/* vector and list */
	cout << "Vector Operations...." << endl;
	cout << "---------------------" << endl;
	//VectorOperations();

	cout << "List Operations..." << endl;
	cout << "------------------" << endl;
	//ListOperations();
	
	vector<school_guest> * record = new vector<school_guest>;
	list<school_guest> * record_list = new list<school_guest>;

	const char* filename = "E:\\Training\\C++\\C++STL-Eduardo\\C++STL-Eduardo\\C++STL-Eduardo\\out\\record.txt";
	ReadFileVectorForPersons(record, filename);
	PrintVectorPersons(record);
	ReadFileListForPersons(record_list, filename);
	PrintListPersons(record_list);

	cout << endl << endl << endl;
	cout << "print VECTOR detail by index" << endl;
	cout << "--------------------------------------------------------" << endl;
	PrintVectorPersonDetailByIndex(record, 2);

	cout << "print VECTOR after removal of a record" << endl;
	RemoveVectorPersonDetailByIndex(record, 2);

	//auto average = GetPersonAgeAverageByVector(*record); //reference vector pointer to get the exact vector name
	cout << "get the average of VECTOR records" << endl;
	cout << "average of age in record: " << GetPersonAgeAverageByVector(*record) << endl;


	cout << endl << endl << endl;
	cout << "print LIST detail by index" << endl;
	cout << "--------------------------------------------------------" << endl;
	PrintListPersonDetailByIndex(record_list, 2);

	cout << "print LIST after removal of a record" << endl;
	RemoveListPersonDetailByIndex(record_list, 2);

	cout << "get the average of LIST records" << endl;
	cout << "average of age in record: " << GetPersonAgeAverageByVector(*record) << endl;

	cin.get();
}