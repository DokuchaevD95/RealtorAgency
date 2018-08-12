#include "dequeInstance.h"

/*
	����������� ���������� ��������������� �������.
	"��������" ��������� �� ���������� � ��������� ���������� �������.
*/
dequeInstance::dequeInstance()
{
	this->_prev = this->_next = nullptr;
}

/*
	����������� �����������
*/
dequeInstance::dequeInstance(const dequeInstance& obj)
{
	this->_prev = obj._prev;
	this->_next = obj._next;
}

/*
	����������� ��������� �� ���������� � ����������� ���������� �������
*/
void dequeInstance::initPrevAndNext(dequeInstance* prev, dequeInstance* next)
{
	this->_prev = prev;
	this->_next = next;
}

/*
	���������� ��������� �� ���������� �������� �������
*/
void dequeInstance::setPrev(dequeInstance* prev)
{
	this->_prev = prev;
}

/*
	����������� ��������� �� ����������� ��������� �������
*/
void dequeInstance::setNext(dequeInstance* next)
{
	this->_next = next;
}

/*
	���������� ������ ��������� ������� �����.
	���� ��������� ����������, ���������� true.
*/
bool dequeInstance::up()
{
	dequeInstance* myPrev = this->_prev;
	if (myPrev)
	{
		if (this->_next)
			this->_next->_prev = myPrev;
		if (myPrev->_prev)
			myPrev->_prev->_next = this;

		myPrev->_next = this->_next;
		this->_next = myPrev;

		this->_prev = myPrev->_prev;
		myPrev->_prev = this;

		return true;
	}
	else return false;
}

/*
	���������� �������� ���������� ������� ����.
	���� ����������� ����������, ���������� true.
*/
bool dequeInstance::down()
{
	dequeInstance* myNext = this->_next;
	if (myNext)
	{
		if (myNext->_next)
			myNext->_next->_prev = this;
		if (this->_prev)
			this->_prev->_next = myNext;

		myNext->_prev = this->_prev;
		this->_prev = myNext;

		this->_next = myNext->_next;
		myNext->_next = this;

		return true;
	}
	else return false;
}

/*
	���������� true, ���� ��������� ��������������� ������� - ������ �������
*/
bool dequeInstance::is_begin()
{
	if (!this->_prev)
		return true;
	else return false;
}

/*
	���������� true, ���� ��������� ��������������� ������� - ����� �������
*/
bool dequeInstance::is_end()
{
	if (!this->_next)
		return true;
	else return false;
}

/*
	���������� ��������� ����������� ���������� ������������ ��������
*/
dequeInstance* dequeInstance::prev()
{
	return this->_prev;
}


/*
	���������� ��������� ���������� ���������� ������� ������������ ��������
*/
dequeInstance* dequeInstance::next()
{
	return this->_next;
}

/*
	���������� ���������� �������, ������� ������� ������ � ������������� �����
*/
dequeInstance::~dequeInstance()
{
	if (this->_prev)
		this->_prev->_next = this->_next;
	if (this->_next)
		this->_next->_prev = this->_prev;
}