#include "collection.h"
#include "Apartment.h"
#include "Deal.h"
#include "Realtor.h"


#pragma once


class Application
{
private:
	collection<Apartment> _apartments;
	collection<Deal> _deals;
	collection<Realtor> _realtors;

	void init();
	bool aprtmentWasSaled(Apartment& obj);
	void print();
public:
	Application();
	void start();
	~Application();
};

