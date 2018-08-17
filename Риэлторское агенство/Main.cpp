#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

#include "collection.h"
#include "Apartment.h"
#include "Date.h"


using namespace std;


void main()
{
	setlocale(0, "");
	Apartment *a = new Apartment();
	cout << *a;
	
	collection<Apartment> coll;
	coll.pushBack(*a);
	coll.sort();
	cout << "end";
	system("pause");
}