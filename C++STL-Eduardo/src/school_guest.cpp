#include "persona.h"

#include <iostream>
#include <string>

using namespace std;

void school_guest::set_name(const string& in) {
	if (!in.empty())
		name = in;
}
void school_guest::set_gender(const string& in) {
	char i = in.c_str()[0];
	if (i == 'b' || i == 'B' || i == 'm' || i == 'M')
		gender = "Boy";
	else
		gender = "Girl";
}
void school_guest::set_age(int in) {
	if (in >= 1)
		age = in;
}

string school_guest::get_name() const { return name; }
string school_guest::get_gender() const { return gender; }
int school_guest::get_age() const { return age; }
