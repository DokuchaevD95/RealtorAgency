#include <iostream>
#include <iomanip>

#include "Human.h"


Human::Human(char* first_name, char* second_name, char* last_name)
{
	this->_first_name = first_name;
	this->_second_name = second_name;
	this->_last_name = last_name;
}

ostream& operator<<(ostream& out, Human& obj)
{
	out << left << setw(20) << "Имя" << obj._first_name << endl;
	out << left << setw(20) << "Фамилия" << obj._second_name << endl;
	out << left << setw(20) << "Отчество" << obj._last_name << endl;
	return out;
}

Human::~Human()
{
	delete[] _first_name;
	delete[] _second_name;
	delete[] _last_name;
}
