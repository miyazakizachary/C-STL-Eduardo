#pragma once
#include "persona.h"

#include <string>
#include <vector>
#include <list>

using namespace std;

void VectorOperations();
void ListOperations();

void ReadFileVectorForPersons(vector<school_guest> * record, const char * filename);
void PrintVectorPersons(const vector<school_guest>* record);

void ReadFileListForPersons(list<school_guest>* record, const char* filename);
void PrintListPersons(list<school_guest>* record);

void PrintVectorPersonDetailByIndex(const vector<school_guest>* record, unsigned int index = 0);
void RemoveVectorPersonDetailByIndex(vector<school_guest>* record, unsigned int index);
float GetPersonAgeAverageByVector(vector<school_guest>& record);

void PrintListPersonDetailByIndex(const list<school_guest>* record, unsigned int index);
void RemoveListPersonDetailByIndex(list<school_guest>* record, unsigned int index);
float GetPersonAgeAverageByList(list<school_guest>& record);