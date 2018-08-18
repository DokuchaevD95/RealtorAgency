#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <iomanip>
#include <Windows.h>

#include "Human.h"

/*
	����������� ��� ����������
*/
Human::Human()
{
	strcpy((char*)this->_firstName, "");
	strcpy((char*)this->_secondName, "");
	strcpy((char*)this->_lastName, "");
}

/*
	����������� �����������
*/
Human::Human(const Human& obj)
{
	strcpy((char*)this->_firstName, (char*)obj._firstName);
	strcpy((char*)this->_secondName, (char*)obj._secondName);
	strcpy((char*)this->_lastName, (char*)obj._lastName);
}

/*
	����������� � �����������
*/
Human::Human(char firstName[], char secondName[], char lastName[])
{
	strcpy(this->_firstName, firstName);
	strcpy(this->_secondName, secondName);
	strcpy(this->_lastName, lastName);
}

/*
����������� ����� ��� �������� ������ ���������� ������
*/
Human Human::create()
{
	char firstName[50];
	char secondName[50];
	char lastName[50];

	cout << "������� �������: ";
	cin.getline((char*)lastName, 50);
	OemToCharA((char*)lastName, (char*)lastName);

	cout << "������� ���: ";
	cin.getline((char*)firstName, 50);
	OemToCharA((char*)firstName, (char*)firstName);

	cout << "������� ��������: ";
	cin.getline((char*)secondName, 50);
	OemToCharA((char*)secondName, (char*)secondName);

	return Human(firstName, secondName, lastName);
}

/*
	������������� �������� ������
*/
ostream& operator<<(ostream& out, Human& obj)
{
	out << obj._lastName << " " << obj._firstName << " " << obj._secondName;
	return out;
}


/*
	����������
*/
Human::~Human()
{
}
