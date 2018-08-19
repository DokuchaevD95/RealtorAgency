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
	bool apartmentWasSaled(Apartment& obj);
	void realtorProfit();
	void apartmentsInRange();
	void insert();
	void insertApartment();
	void insertDeal();
	void InsertReltor();
	void print();
	void sort();
public:
	Application();
	void start();
	~Application();
};

