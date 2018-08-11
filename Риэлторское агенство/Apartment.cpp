#include <iostream>

#include "Apartment.h"

using namespace std;

Apartment::Apartment()
{
}

Apartment::Apartment(Apartment& obj)
{

}

bool Apartment::operator<(dequeInstance& obj)
{
	obj = dynamic_cast<Apartment&>(obj);
	return true;
}

ostream& operator<<(ostream& out, Apartment& obj)
{
	out << "Apartment obj" << endl;
	return out;
}

Apartment::~Apartment()
{
}
