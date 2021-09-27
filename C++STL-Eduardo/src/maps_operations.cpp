#include "stl_operations.h"

#include <ctype.h>
#include <iostream>
#include <map>
#include <unordered_map>

using namespace std;

void MapOperations() {
	map<int, string> str_map;
	pair<int, string> m_pair;
	string str_input;
	int temp = 0;


	cout << "Map operation: insert pair..." << endl;
	while (temp >= 0) {
		start:
		cout << "Enter the key in number (duplicate key will be ignored): ";
		getline(cin, str_input);
		//https://stackoverflow.com/questions/4654636/how-to-determine-if-a-string-is-a-number-with-c/16575025#16575025
		char check = str_input.at(0);
		if (check == '-')
			break;
		if (!isdigit(check)) {
			cout << "please enter the number" << endl;
			goto start;
		}
		temp = stoi(str_input);
		// DON'T USE cin >> with getline(cin, string)
		// cin always leave '\n' in the memory
		// https://mathbits.com/MathBits/CompSci/APstrings/APgetline.htm
		// https://stackoverflow.com/questions/5739937/using-getlinecin-s-after-cin
		//cin >> temp; cin.clear();
		if (temp >= 0) {
			m_pair.first = temp;
			cout << "Enter the name: ";
			getline(cin, str_input);
			m_pair.second = str_input;
			str_map.insert(m_pair);
		}
	}

	//display using range loop
	cout << "ordered map: { " << endl;
	for (auto p : str_map) {
		cout << " " << p.first << "->" << p.second << endl;
	}
	cout << "}";

	temp = 0;
	cout << endl << endl;
	cout << "Removal..." << endl;
	while (temp >= 0) {
	remove:
		cout << "Enter the key to remove: ";
		getline(cin, str_input);
		char check = str_input.at(0);
		if (check == '-')
			break;
		if (!isdigit(check)) {
			cout << "please enter the number" << endl;
			goto remove;
		}
		temp = stoi(str_input);
		if (temp >= 0) {
			str_map.erase(temp);
		}
	}

	//display using iterator
	cout << "{ " << endl;
	for (auto it = str_map.begin(); it != str_map.end(); it++) {
		cout << " " << it->first << "->" << it->second << endl;
	}
	cout << "} ";
}
void MultiMapOperations() {
	multimap<int, string> str_map;
	pair<int, string> m_pair;
	string str_input;
	int temp = 0;

	cout << "Map operation: insert pair..." << endl;
	while (temp >= 0) {
		start:
		cout << "Enter the key in number (allow duplicate key): ";
		getline(cin, str_input);
		//https://stackoverflow.com/questions/4654636/how-to-determine-if-a-string-is-a-number-with-c/16575025#16575025
		char check = str_input.at(0);
		if (check == '-')
			break;
		if (!isdigit(check)) {
			cout << "please enter the number" << endl;
			goto start;
		}
		temp = stoi(str_input);
		// DON'T USE cin >> with getline(cin, string)
		// cin always leave '\n' in the memory
		// https://mathbits.com/MathBits/CompSci/APstrings/APgetline.htm
		// https://stackoverflow.com/questions/5739937/using-getlinecin-s-after-cin
		//cin >> temp; cin.clear();
		if (temp >= 0) {
			m_pair.first = temp;
			cout << "Enter the name: ";
			getline(cin, str_input);
			m_pair.second = str_input;
			str_map.insert(m_pair);
		}
	}

	//display using range loop
	cout << "{ " << endl;
	for (auto p : str_map) {
		cout << " " << p.first << "->" << p.second << endl;
	}
	cout << "}";

	temp = 0;
	cout << endl << endl;
	cout << "Removal..." << endl;
	while (temp >= 0) {
	remove:
		cout << "Enter the key to remove: ";
		getline(cin, str_input);
		char check = str_input.at(0);
		if (check == '-')
			break;
		if (!isdigit(check)) {
			cout << "please enter the number" << endl;
			goto remove;
		}
		temp = stoi(str_input);
		if (temp >= 0) {
			str_map.erase(temp);
		}
	}

	//display using iterator
	cout << "{ " << endl;
	for (auto it = str_map.begin(); it != str_map.end(); it++) {
		cout << " " << it->first << "->" << it->second << endl;
	}
	cout << "} ";
}