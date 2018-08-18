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
	this->_myId = Realtor::id++;
	this->_name = Human();
	this->_percent = 0;
}

/*
	����������� �����������
*/
Realtor::Realtor(const Realtor& obj)
{
	this->_myId = obj._myId;
	this->_name = obj._name;
	this->_percent = obj._percent;
}

/*
	����������� � �����������
*/
Realtor::Realtor(Human& name, float percent, int myId)
{
	if (myId <= 0)
		this->_myId = Realtor::id++;
	else
		this->_myId = myId;
	this->_name = name;
	this->_percent = percent;
}

/*
	����������� �����, ��������� ����� ��������� ������ �������
*/
Realtor Realtor::create()
{
	Human name = Human::create();

	float percent;
	cout << "������� ���������� ������: ";
	cin >> percent;
	cin.ignore();

	return Realtor(name, percent);
}

/*
	������������� �������� ���������
*/
bool Realtor::operator<(Realtor& obj)
{
	if (this->_percent < obj._percent)
		return true;
	else 
		return false;
}

/*
	������������� �������� ������ � �����
*/
ostream& operator<<(ostream& out, Realtor& obj)
{
	out << "-----------------�������----------------" << endl << endl;
	out << "���: " << obj._name << endl;
	out << "���������� ������: " << obj._percent << endl;
	out << endl << "----------------------------------------" << endl;

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
Realtor Realtor::importFromFile()
{
	ifstream file(Realtor::_fileName, ios::binary | ios::in);
	Realtor result;
	file.read((char*)&result, sizeof(Realtor));
	file.close();

	return result;
}

/*
	����������
*/
Realtor::~Realtor()
{	
}
