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
	Apartment a = Apartment::importFromFile();
	cout << a;
	cout << "end";
	system("pause");
}