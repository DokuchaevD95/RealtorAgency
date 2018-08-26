#include <cstring>
#include <iostream>

#include "Date.h"

using namespace std;


/*
	����������� ��� ����������
*/
Date::Date()
{
	this ->_year = 1970;
	this->_month = this->_day = 1;
}		

/*
	����������� � �����������
*/
Date::Date(int year, int month, int day)
{
	this->_year = year;
	this->_month = month;
	this->_day = day;
}

/*
	����������� �����������
*/
Date::Date(const Date& obj)
{
	this->_year = obj._year;
	this->_month = obj._month;
	this->_day = obj._day;
}

/*
	����� ��� �������� ������ ��������
*/
Date Date::create()
{
	int year, month, day;
	bool error;
	cout << "���� ����/��/��" << endl << endl;
	do
	{
		error = false;
		// ���������� ����
		cout << "���: ";
		cin >> year;
		cin.ignore();
		if (year > 2020 || year < 1920)
		{
			error = true;
		}
		// ���������� ������
		cout << "�����: ";
		cin >> month;
		cin.ignore();
		if (month < 1 || month > 12)
		{
			error = true;
		}


		cout << "����: ";
		cin >> day;
		cin.ignore();
		if (day < 1)
		{
			error = true;
		}
		if (month < 7)
		{
			// �������� �������
			if (month == 2)
			{
				// �������� �� ���������� ���
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
			// �������� ������ �������, �� ������ ������������
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
		// �������� ������� ����� �������
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
			cout << "�������� ������ � ���������� ������ �� ����� ����!" << endl << endl;
	} while (error);

	return Date(year, month, day);
}

/*
	������������� �������� ������ ������ � �����
	������ ����� ������� ������ Date ������������� ��� ������ ����������
*/
ostream& operator<<(ostream& out, Date& obj)
{
	out << obj._year << "/" << obj._month << "/" << obj._day;
	return out;
}

/*
	���� ������� ���� ����� �� ������ � ����, ������ true ����� false
*/
bool Date::equalMonthAndYear(int year, int month)
{
	if (this->_month == month && this->_year == year)
		return true;
	else
		return false;
}

/*
	����������
*/
Date::~Date()
{
}
