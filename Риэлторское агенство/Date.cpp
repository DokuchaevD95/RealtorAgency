#include "Date.h"
#include <cstring>
#include <iostream>

using namespace std;


Date::Date()
{
	bool error = false;
	do 
	{
		// Заполнение года
		cout << "Год: ";
		cin >> _year;
		cin.ignore();
		if (_year > 2018 || _year < 1920)
		{
			error = true;
			continue;
		}
		// Заполнение месяца
		cout << "Месяц: ";
		cin >> _month;
		cin.ignore();
		if (_month < 1 || _month > 12)
		{
			error = true;
		}

		// Заполнения дня
		cout << "День: ";
		cin >> _day;
		cin.ignore();
		if (_day < 1)
		{
			error = true;
			continue;
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
			cout << "Допущена ошибка в одном из полей!" << endl;
	} while (error);
}		


Date::~Date()
{
}


/*
// Функция, разбивающая строку на строки, используя символы разделители
// переданные в параметре delimeter
char** split(char *str, char *delimeter)
{
	if (strlen(delimeter) == 0)
	{

	}
	int start = 0, end = strlen(str);
	// Вычисление начала строки, чтобы 
	// избавить от символов разделителей в начале строки
	for (auto i = 0; i < end; i++)
	{
		bool fl = false;
		for (int j = 0; j < strlen(delimeter); j++)
		{
			if (str[i] == delimeter[j])
			{
				fl = true;
				break;
			}
		}

		if (fl)
			start++;
		else
			break;
	}

	if (start == end)
		return nullptr;

	// Вычисление конца строки, чтобы 
	// избавить от символов разделителей в начале строки
	for (auto i = end - 1; i >= start; i--)
	{
		bool fl = false;
		for (auto j = 0; j < strlen(delimeter); j++)
		{
			if (str[i] == delimeter[j])
			{
				fl = true;
				break;
			}
		}

		if (fl)
			end--;
		else
		{
			end = i + 1;
			break;
		}
	}

	int max_lenght = 0, count = 0, word_lenght = 0, word_start_from = start;
	for (auto i = start; i < end; i++)
	{
		bool fl = false;
		for (auto j = 0; j < strlen(delimeter); j++)
			if (str[i] == str[j])
			{
				fl = true;
				break;
			}

		if (fl)
		{

		}

	}
}
*/