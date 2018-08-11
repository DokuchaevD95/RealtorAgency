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
	friend ostream& operator<<(ostream& out, Date& obj);
	bool equalMonthAndYear(int, int);
	~Date();
};

