#pragma once

#include <iostream>

#include "Date.h"
#include "Apartment.h"

using namespace std;


class Deal
{
private:
	static int id;
	static char _fileName[];

	int _myId;
	Date _date;
	DealType _type;
	double _summ;
	int _apartmentId;
	int _realtorId;
public:
	Deal();
	Deal(const Deal& obj);
	Deal(Date& date, DealType type, double summ, int apartmentId, int realtorId, int myId = 0);
	static Deal create();
	bool operator<(Deal& obj);
	friend ostream& operator<<(ostream& out, Deal& obj);
	int getId();
	void exportToFile();
	static Deal importFromFile();
	~Deal();
};

