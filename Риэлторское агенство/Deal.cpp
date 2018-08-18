#include <iostream>
#include <fstream>

#include "Deal.h"

using namespace std;


int Deal::id = 1;
char Deal::_fileName[] = "deal_base.txt";


/*
	Конструктор без параметров
*/
Deal::Deal()
{
	this->_myId = Deal::id++;
	this->_date = Date();
	this->_type = DealType::sale;
	this->_summ = 0;
	this->_apartmentId = this->_realtorId = 0;
}

/*
	Конструктор копирования
*/
Deal::Deal(const Deal& obj)
{
	this->_myId = obj._myId;
	this->_date = obj._date;
	this->_type = obj._type;
	this->_summ = obj._summ;
	this->_apartmentId = obj._apartmentId;
	this->_realtorId = obj._realtorId;
}

/*
	Конструктор с параметрами
*/
Deal::Deal(Date& date, DealType type, double summ, int apartmentId, int realtorId, int myId)
{
	if (myId <= 0)
		this->_myId = Deal::id++;
	else
		this->_myId = myId;
	this->_date = date;
	this->_type = type;
	this->_summ = summ;
	this->_apartmentId = apartmentId;
	this->_realtorId = realtorId;
}

/*
	Метод, создающий новый экземпляр класса сделка
*/
Deal Deal::create()
{
	// TODO: ПРОДУМАТЬ РЕАЛИЗАЦИЮ МЕТОДА, ВОЗМОЖНО ЭТОТ МЕТОД НЕ ПОТРЕБУЕТСЯ
	return Deal();
}

/*
	Перегруженный метод сравнения
*/
bool Deal::operator<(Deal& obj)
{
	if (this->_summ < obj._summ)
		return true;
	else return false;
}

/*
	Перегруженный метод вывода в поток
*/
ostream& operator<<(ostream& out, Deal& obj)
{
	out << "-----------------Сделка----------------" << endl << endl;
	out << "Дата: " << obj._date << endl;
	out << "Сумма сделки: " << obj._summ << endl;
	out << "Тип сделки: ";
	if (obj._type == DealType::sale)
		out << "продажа" << endl;
	else
		out << "аренда" << endl;
	out << "ID квартиры: " << obj._apartmentId << endl;
	out << "ID риэлтора: " << obj._realtorId << endl;
	out << endl << "---------------------------------------" << endl;
	
	return out;
}

/*
	Гетер ID
*/
int Deal::getId()
{
	return this->_myId;
}

/*
	Записывает экзепляр класса в файл
*/
void Deal::exportToFile()
{
	ofstream file(Deal::_fileName, ios::binary | ios::out |  ios::app);
	file.write((char*)this, sizeof(*this));
	file.close();
}

/*
	Считывает и возвращает экземпляр класса
*/
Deal Deal::importFromFile()
{
	ifstream file(Deal::_fileName, ios::binary | ios::in);
	Deal result;
	file.read((char*)&result, sizeof(Deal));
	file.close();

	return result;
}

/*
	Деструктор
*/
Deal::~Deal()
{
}
