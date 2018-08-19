#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <Windows.h>

#include "Apartment.h"

using namespace std;


char Apartment::_fileName[] = "apartment_base.txt";
int Apartment::id = 1;

/*
	����������� ��� ����������
*/
Apartment::Apartment()
{
	this->_myId = 0;
	strcpy((char*)this->_address, "");
	this->_type = DealType::sale;
	this->_roomCount = 0;
	this->_area = 0;
	this->_cost = 0;
}

/*
	����������� � �����������
*/
Apartment::Apartment(Human& owner, char address[], DealType type, int roomCount, int area, double cost, int myId)
{
	if (myId <= 0)
		this->_myId = Apartment::id++;
	else
	{
		this->_myId = myId;
		if (myId >= Apartment::id)
			Apartment::id = myId + 1;
	}
	this->_owner = owner;
	strcpy(this->_address, address);
	this->_type = type;
	this->_roomCount = roomCount;
	this->_area = area;
	this->_cost = cost;
}

/*
	����������� �����������
*/
Apartment::Apartment(const Apartment& obj)
{
	this->_myId = obj._myId;
	this->_owner = obj._owner;
	strcpy((char*)this->_address, (char*)obj._address);
	this->_type = obj._type;
	this->_roomCount = obj._roomCount;
	this->_area = obj._area;
	this->_cost = obj._cost;
}

/*
	����������� ����� ��� �������� ������� ��������
*/
Apartment* Apartment::create()
{
	Human owner = Human::create();

	char address[50];
	cout << "������� �����: ";
	cin.getline((char*)address, 50);
	OemToCharA((char*)address, (char*)address);

	int roomCount = 0;
	cout << "������� ���������� ������: ";
	cin >> roomCount;
	cin.ignore();

	int area = 0;
	cout << "������� �������: ";
	cin >> area;
	cin.ignore();

	cout << "���������� �� ������� (0) ��� � ������ (1)?: ";
	int type;
	DealType _type;
	do 
	{
		cin >> type;
		cin.ignore();
		if (type == 0)
			_type = DealType::sale;
		else if (type == 1)
			_type = DealType::lease;
		else
			cout << "������ �������� �������� ��� ������. ��������� �������: ";
	} while (type < 0 || type > 1);

	double cost = 0;
	cout << "������� ���������: ";
	cin >> cost;
	cin.ignore();

	return new Apartment(owner, address, _type, roomCount, area, cost);
}

/*
	������������ �������� ��� ���������
*/
bool Apartment::operator<(Apartment& obj)
{
	if (this->_type == DealType::sale && obj._type == DealType::sale)
	{
		if (obj._roomCount > this->_roomCount)
			return true;
		else return false;
	}
	else if (this->_type == DealType::sale && obj._type == DealType::lease)
	{
		return false;
	}
	else if (this->_type == DealType::lease && obj._type == DealType::sale)
	{
		return true;
	}
	else
	{
		if (obj._roomCount > this->_roomCount)
			return true;
		else return false;
	}
}

/*
	������������� �������� ��� ������
*/
ostream& operator<<(ostream& out, Apartment& obj)
{
	cout << endl;
	cout << "ID: " << obj._myId << endl;
	cout << "��������: " << obj._owner << endl;
	cout << "�����: " << obj._address << endl;
	cout << "���������� ������: " << obj._roomCount << endl;
	cout << "�������: " << obj._area << endl;
	cout << "��� ������: ";
	if (obj._type == DealType::sale)
		cout << "�������" << endl;
	else
		cout << "������" << endl;
	cout << "���������: " << obj._cost << endl;
	cout << endl;
	return out;
}

/*
	����� ID
 */
int Apartment::getId()
{
	return this->_myId;
}

/*
	���������� ��������� ������ � ����
*/
void Apartment::exportToFile()
{
	ofstream file(Apartment::_fileName, ios::binary | ios::out | ios::app);
	file.write((char*)this, sizeof(Apartment));
	file.close();
}

/*
	��������� � ���������� ��������� ������
*/
Apartment* Apartment::importFromFile(ifstream& file)
{
	if (!file.eof())
	{
		Apartment* result = new Apartment();
		if (!file.read((char*)result, sizeof(Apartment)))
			return nullptr;

		if (result->_myId > Apartment::id)
			Apartment::id = result->_myId + 1;

		return result;
	}
	else
		return nullptr;
}

/*
	���������� ��� �����, � ������� ����� ���������� ������
*/
char* Apartment::getFileName()
{
	return Apartment::_fileName;
}

/*
	����� ���������� ��� ������ ��� ��������
*/
DealType Apartment::getType()
{
	return this->_type;
}

/*
	����� ���������� ��������� ��������
*/
double Apartment::getCost()
{
	return this->_cost;
}

/*
	���������� ��������� �� ��������� �������
*/
Apartment* Apartment::next()
{
	return (Apartment*)this->_next;
}

/*
	���������� ��������� �� ���������� �������
*/
Apartment* Apartment::prev()
{
	return (Apartment*)this->_prev;
}

/*
	����������
*/
Apartment::~Apartment()
{
}
