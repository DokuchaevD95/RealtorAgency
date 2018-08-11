#include "Date.h"
#include <cstring>
#include <iostream>

using namespace std;


Date::Date()
{
	bool error = false;
	do 
	{
		cout << "Год: ";
		cin >> _year;
		cin.ignore();
		if (_year > 2018 || _year < 1920)
		{
			error = true;
			continue;
		}

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
			continue;
		}
		if (_month < 7)
		{
			if (_month == 2)
			{
				if (_year % 4 == 0)
				{

				}
			}
			else
			{

			}
		}
		else
		{
			if (_month % 2 == 0)
				
		}
	}
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