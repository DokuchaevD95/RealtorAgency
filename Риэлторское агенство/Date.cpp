#include <cstring>
#include <iostream>

#include "Date.h"

using namespace std;


/*
	Конструктор без параметров
*/
Date::Date()
{
	this ->_year = 1970;
	this->_month = this->_day = 1;
}		

/*
	Конструктор с параметрами
*/
Date::Date(int year, int month, int day)
{
	this->_year = year;
	this->_month = month;
	this->_day = day;
}

/*
	Конструктор копирования
*/
Date::Date(const Date& obj)
{
	this->_year = obj._year;
	this->_month = obj._month;
	this->_day = obj._day;
}

/*
	Метод для создания нового элемента
*/
Date Date::create()
{
	int year, month, day;
	bool error;
	cout << "Дата ГГГГ/ММ/ДД" << endl << endl;
	do
	{
		error = false;
		// Заполнение года
		cout << "Год: ";
		cin >> year;
		cin.ignore();
		if (year > 2020 || year < 1920)
		{
			error = true;
		}
		// Заполнение месяца
		cout << "Месяц: ";
		cin >> month;
		cin.ignore();
		if (month < 1 || month > 12)
		{
			error = true;
		}


		cout << "День: ";
		cin >> day;
		cin.ignore();
		if (day < 1)
		{
			error = true;
		}
		if (month < 7)
		{
			// Проверка февраля
			if (month == 2)
			{
				// Проверка на високосный год
				if (year % 4 == 0)
				{
					if (day > 29)
						error = true;
				}
				else
				{
					if (day > 28)
						error = true;
				}
			}
			// Проверка других месяцев, до агуста включительно
			else
			{
				if (month % 2 == 1)
				{
					if (day > 31)
						error = true;
				}
				else
					if (day > 30)
						error = true;
			}
		}
		// Проверка месяцев после августа
		else
		{
			if (month % 2 == 0)
			{
				if (day > 31)
					error = true;
			}
			else
				if (day > 30)
					error = true;
		}

		if (error)
			cout << "Допущена ошибка в заполнении одного из полей даты!" << endl << endl;
	} while (error);

	return Date(year, month, day);
}

/*
	Перегруженный оператор вывода данных в поток
	теперь можно объекты класса Date распечатывать как обычые переменные
*/
ostream& operator<<(ostream& out, Date& obj)
{
	out << obj._year << "/" << obj._month << "/" << obj._day;
	return out;
}

/*
	Если текущая дата равна по месяцу и году, вернет true иначе false
*/
bool Date::equalMonthAndYear(int year, int month)
{
	if (this->_month == month && this->_year == year)
		return true;
	else
		return false;
}

/*
	Деструктор
*/
Date::~Date()
{
}
