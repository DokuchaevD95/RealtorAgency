#pragma once
class Date
{
private:
	int _day;
	int _month;
	int _year;
public:
	Date();
	char* shortDate();
	char* fullDate();
	~Date();
};

