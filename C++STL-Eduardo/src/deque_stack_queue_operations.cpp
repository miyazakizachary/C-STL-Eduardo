#include "stl_operations.h"

#include <iostream>
#include <deque>
#include <stack>
#include <queue>

using namespace std;

void DequeBasicOperations() {
	deque<int> numbers;
	int num = 0;

	cout << "Deque: Push back..." << endl;
	while (num >= 0) {
		cout << "Enter the number: ";
		cin >> num;
		if (num >= 0) {
			numbers.push_back(num);
		}
	}

	deque<int>::iterator it;
	cout << "{ ";
	for (it = numbers.begin(); it != numbers.end(); it++) {
		cout << *it << " ";
	}
	cout << " }";


	num = 0;
	cout << endl;
	cout << "Push front..." << endl;
	while (num >= 0) {
		cout << "Enter the number: ";
		cin >> num;
		if (num >= 0) {
			numbers.push_front(num);
		}
	}


	cout << "{ ";
	for (it = numbers.begin(); it != numbers.end(); it++) {
		cout << *it << " ";
	}
	cout << " }";
	cout << endl;
	cout << "the size of deque is: " << numbers.size() << endl << endl;
}

void StackBasicOperations() {
	stack<int> numbers;
	int num = 0;

	cout << "Stack: Push into the stack..." << endl;
	while (num >= 0) {
		cout << "Enter the number: ";
		cin >> num;
		if (num >= 0) {
			numbers.push(num); // push from the front
		}
	}

	cout << endl;
	cout << "{ ";
	while (numbers.size() > 0) {
		cout << numbers.top();	//display the top of stack (actually the front)
		numbers.pop();			//reduce the stack and now the 2nd top becomes the top
		cout << " ";
	}
	cout << " }";
	cout << endl;
	cout << "the size of stack is: " << numbers.size() << endl << endl;

}

void QueueBasicOperations() {
	queue<int> numbers;
	int num = 0;

	cout << "Queue: Push front for queue..." << endl;
	while (num >= 0) {
		cout << "Enter the number: ";
		cin >> num;
		if (num >= 0) {
			numbers.push(num); //push from the back unlike stack which push from the front
		}
	}
	cout << endl;

	cout << "{ ";
	while (numbers.size() > 0) {
		cout << numbers.front();	// unlike stack, it is FIFO, so it will display the front and not the back
		numbers.pop(); // reduce the front so the 2nd front will become the front
		cout << " ";
	}
	cout << " }";
	cout << endl;
	cout << "the size of queue is: " << numbers.size() << endl << endl;
}

void PriorityQueueBasicOperations() {
	priority_queue<int> numbers;
	int num = 0;

	cout << "Priority Queue:  using the same library as Queue, pushing the back..." << endl;
	cout << "behave like heap ds (binary tree) that always sorted in descending order (max at the top)" << endl;
	while (num >= 0) {
		cout <<	"Enter the number: ";
		cin >> num;
		if (num >= 0) {
			numbers.push(num);	//push from the back
		}
	}
	cout << endl;

	cout << "{ ";
	while (numbers.size() > 0) {
		cout << numbers.top(); // first element is the max (ordered descending)
		numbers.pop();
		cout << " ";
	}
	cout << " }";
	cout << endl;
	cout << "the size of priority queue is: " << numbers.size() << endl << endl;
}

void BrowserBackButtonSimulation() {
	stack<string> back_button;
	stack<string> forward_button;
	string console_action;
	string history = "";

	cout << "Simulating browser history of URLs visited..." << endl;
	do {

	start:
		cout << "Enter number for: " << endl;
		cout << "[1] Visit Url" << endl;
		cout << "[2] Back Previous History" << endl;
		cout << "[3] Forward Next History" << endl;
		cout << "[exit] Exit the Application" << endl;
		cout << "Your Selection: ";
		cin >> console_action;
			
		if (console_action == "exit")
			break;
		if (console_action == "1") {
			cout << endl;
			cout << "Enter the url: ";
			cin >> history;
			back_button.push(history);
			//empty forward
			forward_button = stack<string>(); //calling stack constructor
		}
		else if (console_action == "2") {

			if (back_button.empty() || back_button.size() == 1) {
				cout << "No back history" << endl << endl;
				if (back_button.size() == 1) {
					cout << "current URL: " << back_button.top() << endl << endl;
					goto start;
				}
				else {
					goto start;
				}
			} else {
				cout << "Going backward.." << endl << endl;
				forward_button.push(back_button.top());
				back_button.pop();
			}
			
		}
		else if (console_action == "3") {
			cout << endl;
			if (forward_button.empty()) {
				cout << "No next history" << endl << endl;
				if (back_button.size() > 0) {
					cout << "current URL: " << back_button.top() << endl << endl;
					goto start;
				}
				else {
					goto start;
				}
			}
			else {
				cout << "Going forward..";
				back_button.push(forward_button.top());
				forward_button.pop();
			}

		}

		// this if statement must be outside the else-if statement because the break cannot be enclosed in 
		// 2 level-deep of if statement
		cout << endl;
		cout << "current URL: " << back_button.top() << endl << endl;
	} while (!back_button.empty());
}