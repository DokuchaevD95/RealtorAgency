#pragma once
#include <iostream>

#include "dequeInstance.h"

using namespace std;

class Apartment: public dequeInstance
{
public:
	Apartment();
	Apartment(Apartment& obj);
	bool operator<(dequeInstance& obj);
	friend ostream& operator<<(ostream& out, Apartment& obj);
	~Apartment();
};

