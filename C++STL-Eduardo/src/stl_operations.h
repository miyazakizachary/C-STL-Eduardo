#pragma once
#include "persona.h"

#include <string>
#include <vector>
#include <list>

using namespace std;

void VectorOperations();
void ListOperations();

// vector
void ReadFileVectorForPersons(vector<school_guest> * record, const char * filename);
void PrintVectorPersons(const vector<school_guest>* record);

void PrintVectorPersonDetailByIndex(const vector<school_guest>* record, unsigned int index = 0);
void RemoveVectorPersonDetailByIndex(vector<school_guest>* record, unsigned int index);
float GetPersonAgeAverageByVector(vector<school_guest>& record);

// list
void ReadFileListForPersons(list<school_guest>* record, const char* filename);
void PrintListPersons(list<school_guest>* record);

void PrintListPersonDetailByIndex(const list<school_guest>* record, unsigned int index);
void RemoveListPersonDetailByIndex(list<school_guest>* record, unsigned int index);
float GetPersonAgeAverageByList(list<school_guest>& record);

// deque
void DequeBasicOperations();
//stack
void StackBasicOperations();
//queue
void QueueBasicOperations();
//priority queue
void PriorityQueueBasicOperations();
//simulating browser back button
void BrowserBackButtonSimulation();

//set
void SetOperations();
//multiset
void MultiSetOperations();
//unordered set
void UnorderedSetOperations();
//unordered multiset
void UnorderedMultiSetOperations();

//map
void MapOperations();
//multimap
void MultiMapOperations();