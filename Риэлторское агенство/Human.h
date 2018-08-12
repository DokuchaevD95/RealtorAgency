#pragma once
#include <iostream>

using namespace std;

class Human
{
private:
	char* _first_name;
	char* _second_name;
	char* _last_name;
public:
	Human();
	Human(const Human& obj);
	static Human create();
	Human(char*, char*, char*);
	friend ostream& operator<<(ostream& out, Human& obj);
	~Human();
};

