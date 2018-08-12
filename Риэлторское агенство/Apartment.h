#pragma once
#include <iostream>

#include "dequeInstance.h"
#include "Human.h"


using namespace std;


enum DealType
{
	// Аренда
	lease,

	// Продажа
	sale
};


class Apartment: public dequeInstance
{
private:
	static int id;
	static char _fileName[];

	int _myId;
	Human _owner;
	char* _address;
	DealType _type;
	int _roomCount;
	int _area;
	double _cost;
public:
	Apartment();
	Apartment(Human& owner, char* address, DealType type, int roomCount, int area, double cost, int myId=0);
	Apartment(const Apartment& obj);
	static Apartment create();
	bool operator<(Apartment& obj);
	friend ostream& operator<<(ostream& out, Apartment& obj);
	int getId();
	~Apartment();
};