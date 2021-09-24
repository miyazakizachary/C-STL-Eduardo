#pragma once

#include <string>
using namespace std;

template <typename T>
class person {
public:
	static int objectCount;
	person() {
		objectCount++;
	}
	person(T& name, T& gender, int age) {}
	~person() {}

	virtual void set_name(const T& in) = 0;
	virtual void set_gender(const T& in) = 0;
	virtual void set_age(int in) = 0;
	virtual T get_name() const = 0;
	virtual T get_gender() const = 0;
	virtual int get_age() const = 0;

	static int getObjectCount() {
		return objectCount;
	}
protected:
	T name;
	T gender;
	int age;
};


template <typename T>
int person<T>::objectCount = 0;

class school_guest : public person<string> {
public:
	school_guest() {}
	~school_guest() {}
	school_guest(string& name, string& gender, int age) : person(name, gender, age) {}
	void set_name(const string& in) override;
	void set_gender(const string& in) final; //set gender is only specific to this class. stop inheritance
	void set_age(int in) override;
	string get_name() const override;
	string get_gender() const override;
	int get_age() const override;
};
