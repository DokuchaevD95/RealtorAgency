#pragma once
#include <iostream>
/*
	����������� ����� ���������� ��������.
	� ������ ������, ������� ����� �� ���� ������������� ���������� ����������� ���������� ��������� � �������� � ����� ������.
*/
class dequeInstance
{
private:
	dequeInstance *_prev, *_next;
public:
	dequeInstance();
	dequeInstance(const dequeInstance& obj);
	void initPrevAndNext(dequeInstance* prev, dequeInstance* next);
	void setPrev(dequeInstance* prev);
	void setNext(dequeInstance* next);
	bool up();
	bool down();
	bool is_begin();
	bool is_end();
	virtual dequeInstance* prev();
	virtual dequeInstance* next();
	~dequeInstance();
};