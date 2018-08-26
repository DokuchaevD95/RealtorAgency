#pragma once
#include <iostream>


using namespace std;


class Date
{
private:
	int _day;
	int _month;
	int _year;
public:
	Date();
	Date(int year, int month, int day);
	Date(const Date& obj);
	static Date create();
	friend ostream& operator<<(ostream& out, Date& obj);
	bool equalMonthAndYear(int year, int month);
	~Date();
};

