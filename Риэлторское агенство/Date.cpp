#include "Date.h"
#include <cstring>
#include <iostream>

using namespace std;


// ����������� ��� ����������
Date::Date()
{
	bool error;
	cout << "���� ����/��/��" << endl << endl;
	do 
	{
		error = false;
		// ���������� ����
		cout << "���: ";
		cin >> _year;
		cin.ignore();
		if (_year > 2018 || _year < 1920)
		{
			error = true;
		}
		// ���������� ������
		cout << "�����: ";
		cin >> _month;
		cin.ignore();
		if (_month < 1 || _month > 12)
		{
			error = true;
		}


		cout << "����: ";
		cin >> _day;
		cin.ignore();
		if (_day < 1)
		{
			error = true;
		}
		if (_month < 7)
		{
			// �������� �������
			if (_month == 2)
			{
				// �������� �� ���������� ���
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
			// �������� ������ �������, �� ������ ������������
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
		// �������� ������� ����� �������
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
			cout << "�������� ������ � ���������� ������ �� ����� ����!" << endl << endl;
	} while (error);
}		


// ������������� �������� ������ ������ � �����
// ������ ����� ������� ������ Date ������������� ��� ������ ����������
ostream& operator<<(ostream& out, Date& obj)
{
	out << obj._year << "/" << obj._month << "/" << obj._day << endl;
	return out;
}


// ���� ������� ���� ����� �� ������ � ����, ������ true ����� false
bool Date::equalMonthAndYear(int year, int month)
{
	if (this->_month == month && this->_year == year)
		return true;
	else
		return false;
}


// ����������
Date::~Date()
{
}
