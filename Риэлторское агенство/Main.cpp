#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

#include "collection.h"
#include "Apartment.h"


using namespace std;


char** split(char *str, char *delimeter);


void main()
{
	Apartment *a = new Apartment;
	collection<Apartment> coll;
	coll.pushBack(*a);
	cout << coll[0];
	coll.pop(*a);
	
	system("pause");
}