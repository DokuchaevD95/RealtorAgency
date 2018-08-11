#include "Date.h"
#include <cstring>
#include <iostream>

using namespace std;


// Конструктор без параметров
Date::Date()
{
	bool error;
	cout << "Дата ГГГГ/ММ/ДД" << endl << endl;
	do 
	{
		error = false;
		// Заполнение года
		cout << "Год: ";
		cin >> _year;
		cin.ignore();
		if (_year > 2018 || _year < 1920)
		{
			error = true;
		}
		// Заполнение месяца
		cout << "Месяц: ";
		cin >> _month;
		cin.ignore();
		if (_month < 1 || _month > 12)
		{
			error = true;
		}


		cout << "День: ";
		cin >> _day;
		cin.ignore();
		if (_day < 1)
		{
			error = true;
		}
		if (_month < 7)
		{
			// Проверка февраля
			if (_month == 2)
			{
				// Проверка на високосный год
				if (_year % 4 == 0)
				{
					if (_day > 29)
						error = true;
				}
				else
				{
					if (_day > 28)
						error = true;
				}
			}
			// Проверка других месяцев, до агуста включительно
			else
			{
				if (_month % 2 == 1)
				{
					if (_day > 31)
						error = true;
				}
				else
					if (_day > 30)
						error = true;
			}
		}
		// Проверка месяцев после августа
		else
		{
			if (_month % 2 == 0)
			{
				if (_day > 31)
					error = true;
			}
			else
				if (_day > 30)
					error = true;
		}

		if (error)
			cout << "Допущена ошибка в паполнении одного из полей даты!" << endl << endl;
	} while (error);
}		


// Перегруженный оператор вывода данных в поток
// теперь можно объекты класса Date распечатывать как обычые переменные
ostream& operator<<(ostream& out, Date& obj)
{
	out << obj._year << "/" << obj._month << "/" << obj._day << endl;
	return out;
}


// Если текущая дата равна по месяцу и году, вернет true иначе false
bool Date::equalMonthAndYear(int year, int month)
{
	if (this->_month == month && this->_year == year)
		return true;
	else
		return false;
}


// Деструктор
Date::~Date()
{
}
