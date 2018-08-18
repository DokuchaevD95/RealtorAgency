#pragma once
#include <iostream>

using namespace std;

class Human
{
private:
	char _firstName[50];
	char _secondName[50];
	char _lastName[50];
public:
	Human();
	Human(const Human& obj);
	static Human create();
	Human(char firstName[], char secondName[], char lastName[]);
	friend ostream& operator<<(ostream& out, Human& obj);
	~Human();
};

