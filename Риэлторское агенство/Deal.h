#pragma once

#include <iostream>

#include "Date.h"
#include "Realtor.h"
#include "dequeInstance.h"
#include "Apartment.h"

using namespace std;


class Deal: public dequeInstance
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
	static Deal* create(Apartment& apartment, Realtor& realtor);
	bool operator<(Deal& obj);
	friend ostream& operator<<(ostream& out, Deal& obj);
	int getId();
	int getApartmentId();
	void exportToFile();
	static char* getFileName();
	static Deal* importFromFile(ifstream& file);
	Deal* next();
	Deal* prev();
	~Deal();
};

