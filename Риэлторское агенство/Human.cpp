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
	strcpy((char*)this->_firstName, "");
	strcpy((char*)this->_secondName, "");
	strcpy((char*)this->_lastName, "");
}

/*
	Конструктор копирования
*/
Human::Human(const Human& obj)
{
	strcpy((char*)this->_firstName, (char*)obj._firstName);
	strcpy((char*)this->_secondName, (char*)obj._secondName);
	strcpy((char*)this->_lastName, (char*)obj._lastName);
}

/*
	Конструктор с параметрами
*/
Human::Human(char firstName[], char secondName[], char lastName[])
{
	strcpy(this->_firstName, firstName);
	strcpy(this->_secondName, secondName);
	strcpy(this->_lastName, lastName);
}

/*
Статический метод для создания нового экземпляра класса
*/
Human Human::create()
{
	char firstName[50];
	char secondName[50];
	char lastName[50];

	cout << "Введите фамилию: ";
	cin.getline((char*)lastName, 50);
	OemToCharA((char*)lastName, (char*)lastName);

	cout << "Введите имя: ";
	cin.getline((char*)firstName, 50);
	OemToCharA((char*)firstName, (char*)firstName);

	cout << "Введите отчество: ";
	cin.getline((char*)secondName, 50);
	OemToCharA((char*)secondName, (char*)secondName);

	return Human(firstName, secondName, lastName);
}

/*
	Перегруженный оператор вывода
*/
ostream& operator<<(ostream& out, Human& obj)
{
	out << obj._lastName << " " << obj._firstName << " " << obj._secondName;
	return out;
}


/*
	Деструктор
*/
Human::~Human()
{
}
