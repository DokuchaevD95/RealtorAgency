#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <iomanip>
#include <Windows.h>

#include "Human.h"

/*
	Конструктор без параметров
*/
Human::Human()
{
	this->_first_name = new char[50];
	this->_second_name = new char[50];
	this->_last_name = new char[50];

	strcpy(this->_first_name, "");
	strcpy(this->_second_name, "");
	strcpy(this->_last_name, "");
}

/*
	Конструктор копирования
*/
Human::Human(const Human& obj)
{
	this->_first_name = new char[50];
	this->_second_name = new char[50];
	this->_last_name = new char[50];

	strcpy(this->_first_name, obj._first_name);
	strcpy(this->_second_name, obj._second_name);
	strcpy(this->_last_name, obj._last_name);
}

/*
	Конструктор с параметрами
*/
Human::Human(char* first_name, char* second_name, char* last_name)
{
	this->_first_name = first_name;
	this->_second_name = second_name;
	this->_last_name = last_name;
}

/*
Статический метод для создания нового экземпляра класса
*/
Human Human::create()
{
	char* firstName = new char[50];
	char* secondName = new char[50];
	char* lastName = new char[50];

	cout << "Введите фамилию: ";
	cin.getline(lastName, 50);
	OemToCharA(lastName, lastName);

	cout << "Введите имя: ";
	cin.getline(firstName, 50);
	OemToCharA(firstName, firstName);

	cout << "Введите отчество: ";
	cin.getline(secondName, 50);
	OemToCharA(secondName, secondName);

	return Human(firstName, secondName, lastName);
}

/*
	Перегруженный оператор вывода
*/
ostream& operator<<(ostream& out, Human& obj)
{
	out << obj._last_name << " " << obj._first_name << " " << obj._second_name;
	return out;
}


/*
	Деструктор
*/
Human::~Human()
{
	delete[] _first_name;
	delete[] _second_name;
	delete[] _last_name;
}
