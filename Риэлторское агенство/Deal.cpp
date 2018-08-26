#include <iostream>
#include <fstream>

#include "Deal.h"
#include "Realtor.h"

using namespace std;


int Deal::id = 1;
char Deal::_fileName[] = "deal_base.txt";


/*
	����������� ��� ����������
*/
Deal::Deal()
{
	this->_myId = 0;
	this->_date = Date();
	this->_type = DealType::sale;
	this->_summ = 0;
	this->_apartment_cost = 0;
	this->_apartmentId = this->_realtorId = 0;
}

/*
	����������� �����������
*/
Deal::Deal(const Deal& obj)
{
	this->_myId = obj._myId;
	this->_date = obj._date;
	this->_type = obj._type;
	this->_summ = obj._summ;
	this->_apartment_cost = obj._apartment_cost;
	this->_apartmentId = obj._apartmentId;
	this->_realtorId = obj._realtorId;
}

/*
	����������� � �����������
*/
Deal::Deal(Date& date, DealType type, double summ, double apartment_cost, int apartmentId, int realtorId, int myId)
{
	if (myId <= 0)
		this->_myId = Deal::id++;
	else
	{
		this->_myId = myId;
		if (myId >= Deal::id)
			Deal::id = myId + 1;
	}
	this->_date = date;
	this->_type = type;
	this->_summ = summ;
	this->_apartment_cost = apartment_cost;
	this->_apartmentId = apartmentId;
	this->_realtorId = realtorId;
}

/*
	�����, ��������� ����� ��������� ������ ������
*/
Deal* Deal::create(Apartment& apartment, Realtor& realtor)
{
	int apartmentId = apartment.getId();
	int realtorId = realtor.getId();
	float percent = 0;
	double summ = 0, apartment_cost = 0;
	Date date;
	DealType type = apartment.getType();

	if (type == DealType::sale)
		percent = realtor.getSalePercent();
	else
		percent = realtor.getLeasePercent();

	apartment_cost = apartment.getCost();
	summ = apartment.getCost() + apartment.getCost()  / 100. * percent;
	
	cout << "������� ���� ������" << endl;
	date = Date::create();

	return new Deal(date, type, summ, apartment_cost, apartmentId, realtorId);
}

/*
	������������� ����� ���������
*/
bool Deal::operator<(Deal& obj)
{
	if (this->_summ < obj._summ)
		return true;
	else return false;
}

/*
	������������� ����� ������ � �����
*/
ostream& operator<<(ostream& out, Deal& obj)
{
	out << endl;
	out << "ID: " << obj._myId << endl;
	out << "����: " << obj._date << endl;
	out << "��������� ��������: " << obj._apartment_cost << endl;
	out << "����� ������: " << obj._summ << endl;
	out << "��� ������: ";
	if (obj._type == DealType::sale)
		out << "�������" << endl;
	else
		out << "������" << endl;
	out << "ID ��������: " << obj._apartmentId << endl;
	out << "ID ��������: " << obj._realtorId << endl;
	out << endl;
	
	return out;
}

/*
	����� ID
*/
int Deal::getId()
{
	return this->_myId;
}

/*
	���������� �������� ������ � ����
*/
void Deal::exportToFile()
{
	ofstream file(Deal::_fileName, ios::binary | ios::out |  ios::app);
	file.write((char*)this, sizeof(*this));
	file.close();
}

/*
	���������� ������������� ��������� ��������
*/
int Deal::getApartmentId()
{
	return this->_apartmentId;
}

/*
	��������� � ���������� ��������� ������
*/
Deal* Deal::importFromFile(ifstream& file)
{
	if (!file.eof())
	{
		Deal* result = new Deal();
		if (!file.read((char*)result, sizeof(Deal)))
			return nullptr;
		if (result->_myId > Deal::id)
			Deal::id = result->_myId + 1;

		return result;
	}
	else
		return nullptr;
}

/*
	���������� ��� �����, � ������� ����� ���������� ������
*/
char* Deal::getFileName()
{
	return Deal::_fileName;
}

/*
	���������� ��������� �� ��������� �������
*/
Deal* Deal::next()
{
	return (Deal*)this->_next;
}

/*
	���������� ��������� �� ���������� �������
*/
Deal* Deal::prev()
{
	return (Deal*)this->_prev;
}

/*
	�����, ������������ ID ��������
*/
int Deal::getRealtorId()
{
	return this->_realtorId;
}

/*
	����� ������������ ���� ������
*/
Date Deal::getDate()
{
	return this->_date;
}

/*
	���������� �����, ������� ��������� ������� � ���� ������
*/
double Deal::getRealtorProfit()
{
	return (double)(this->_summ - this->_apartment_cost);
}

/*
	����������
*/
Deal::~Deal()
{
}
