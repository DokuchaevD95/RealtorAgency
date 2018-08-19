#include <iostream>
#include <fstream>

#include "Realtor.h"

using namespace std;


int Realtor::id = 1;
char Realtor::_fileName[] = "realtor_base.txt";


/*
	����������� ��� ����������
*/
Realtor::Realtor()
{
	this->_myId = 0;
	this->_name = Human();
	this->_salePercent = 0;
	this->_leasePercent = 0;
}

/*
	����������� �����������
*/
Realtor::Realtor(const Realtor& obj)
{
	this->_myId = obj._myId;
	this->_name = obj._name;
	this->_salePercent = obj._salePercent;
	this->_leasePercent = obj._leasePercent;
}

/*
	����������� � �����������
*/
Realtor::Realtor(Human& name, float salePercent, float leasePercent, int myId)
{
	if (myId <= 0)
		this->_myId = Realtor::id++;
	else
	{
		this->_myId = myId;
		if (myId >= Realtor::id)
			Realtor::id = myId + 1;
	}
	this->_name = name;
	this->_salePercent = salePercent;
	this->_leasePercent = leasePercent;
}

/*
	����������� �����, ��������� ����� ��������� ������ �������
*/
Realtor* Realtor::create()
{
	Human name = Human::create();

	float salePercent, leasePercent;

	cout << "������� ���������� ������ ��� ������: ";
	cin >> salePercent;
	cin.ignore();

	cout << endl << "������� ���������� ������ ��� ������ �� ������������ �������: ";
	cin >> leasePercent;

	return new Realtor(name, salePercent, leasePercent);
}

/*
	������������� �������� ���������
*/
bool Realtor::operator<(Realtor& obj)
{
	if (this->_salePercent < obj._salePercent)
		return true;
	else if (this->_salePercent == obj._salePercent)
	{
		if (this->_leasePercent < obj._leasePercent)
			return true;
		else return false;
	}
	else 
		return false;
}

/*
	������������� �������� ������ � �����
*/
ostream& operator<<(ostream& out, Realtor& obj)
{
	out << endl;
	out << "ID: " << obj._myId << endl;
	out << "���: " << obj._name << endl;
	out << "���������� ������ ��� �������: " << obj._salePercent << endl;
	out << "���������� ������ ��� ������: " << obj._leasePercent << endl;
	out << endl;

	return out;
}

/*
	����� ID
*/
int Realtor::getId()
{
	return this->_myId;
}

/*
	���������� ��������� ������ � ����
*/
void Realtor::exportToFile()
{
	ofstream file(Realtor::_fileName, ios::binary | ios::out | ios::app);
	file.write((char*)this, sizeof(Realtor));
	file.close();
}

/*
	��������� � ���������� ��������� ������ � �����
*/
Realtor* Realtor::importFromFile(ifstream& file)
{
	if (!file.eof())
	{
		Realtor* result = new Realtor();
		if (!file.read((char*)result, sizeof(Realtor)))
			return nullptr;
		if (result->_myId > Realtor::id)
			Realtor::id = result->_myId + 1;
		return result;
	}
	else
		return nullptr;
}

/*
	���������� ������� ��� ������� ��������
*/
float Realtor::getSalePercent()
{
	return this->_salePercent;
}

/*
	���������� ������� ��� ������ ��������
*/
float Realtor::getLeasePercent()
{
	return this->_leasePercent;
}

/*
���������� ��� �����, � ������� ����� ���������� ������s
*/
char* Realtor::getFileName()
{
	return Realtor::_fileName;
}

/*
	���������� ��������� �� ��������� �������
*/
Realtor* Realtor::next()
{
	return (Realtor*)this->_next;
}

/*
	���������� ��������� �� ���������� �������
*/
Realtor* Realtor::prev()
{
	return (Realtor*)this->_prev;
}

/*
	����������
*/
Realtor::~Realtor()
{	
}
