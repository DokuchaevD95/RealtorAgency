#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <Windows.h>

#include "Apartment.h"

using namespace std;


char Apartment::_fileName[] = "apartment_base.txt";
int Apartment::id = 1;

/*
	Конструктор без параметров
*/
Apartment::Apartment()
{
	this->_myId = 0;
	strcpy((char*)this->_address, "");
	this->_type = DealType::sale;
	this->_roomCount = 0;
	this->_area = 0;
	this->_cost = 0;
}

/*
	Конструктор с параметрами
*/
Apartment::Apartment(Human& owner, char address[], DealType type, int roomCount, int area, double cost, int myId)
{
	if (myId <= 0)
		this->_myId = Apartment::id++;
	else
	{
		this->_myId = myId;
		if (myId >= Apartment::id)
			Apartment::id = myId + 1;
	}
	this->_owner = owner;
	strcpy(this->_address, address);
	this->_type = type;
	this->_roomCount = roomCount;
	this->_area = area;
	this->_cost = cost;
}

/*
	Конструктор копирования
*/
Apartment::Apartment(const Apartment& obj)
{
	this->_myId = obj._myId;
	this->_owner = obj._owner;
	strcpy((char*)this->_address, (char*)obj._address);
	this->_type = obj._type;
	this->_roomCount = obj._roomCount;
	this->_area = obj._area;
	this->_cost = obj._cost;
}

/*
	Статический метод для создания объекта квартира
*/
Apartment* Apartment::create()
{
	Human owner = Human::create();

	char address[50];
	cout << "Введите адрес: ";
	cin.getline((char*)address, 50);
	OemToCharA((char*)address, (char*)address);

	int roomCount = 0;
	cout << "Введите количество комнат: ";
	cin >> roomCount;
	cin.ignore();

	int area = 0;
	cout << "Введите площадь: ";
	cin >> area;
	cin.ignore();

	cout << "Выставлена на продажу (0) или в аренду (1)?: ";
	int type;
	DealType _type;
	do 
	{
		cin >> type;
		cin.ignore();
		if (type == 0)
			_type = DealType::sale;
		else if (type == 1)
			_type = DealType::lease;
		else
			cout << "Введен неверный желаемый тип сделки. Повторите попытку: ";
	} while (type < 0 || type > 1);

	double cost = 0;
	cout << "Введите стоимость: ";
	cin >> cost;
	cin.ignore();

	return new Apartment(owner, address, _type, roomCount, area, cost);
}

/*
	Перегруженая операция для сравнения
*/
bool Apartment::operator<(Apartment& obj)
{
	if (this->_type == DealType::sale && obj._type == DealType::sale)
	{
		if (obj._roomCount > this->_roomCount)
			return true;
		else return false;
	}
	else if (this->_type == DealType::sale && obj._type == DealType::lease)
	{
		return false;
	}
	else if (this->_type == DealType::lease && obj._type == DealType::sale)
	{
		return true;
	}
	else
	{
		if (obj._roomCount > this->_roomCount)
			return true;
		else return false;
	}
}

/*
	Перегруженный оператор для вывода
*/
ostream& operator<<(ostream& out, Apartment& obj)
{
	cout << endl;
	cout << "ID: " << obj._myId << endl;
	cout << "Владелец: " << obj._owner << endl;
	cout << "Адрес: " << obj._address << endl;
	cout << "Количество комнат: " << obj._roomCount << endl;
	cout << "Площадь: " << obj._area << endl;
	cout << "Тип сделки: ";
	if (obj._type == DealType::sale)
		cout << "продажа" << endl;
	else
		cout << "аренда" << endl;
	cout << "Стоимость: " << obj._cost << endl;
	cout << endl;
	return out;
}

/*
	Гетер ID
 */
int Apartment::getId()
{
	return this->_myId;
}

/*
	Отправляет экземпляр класса в файл
*/
void Apartment::exportToFile()
{
	ofstream file(Apartment::_fileName, ios::binary | ios::out | ios::app);
	file.write((char*)this, sizeof(Apartment));
	file.close();
}

/*
	Считывает и возвращает экземпляр класса
*/
Apartment* Apartment::importFromFile(ifstream& file)
{
	if (!file.eof())
	{
		Apartment* result = new Apartment();
		if (!file.read((char*)result, sizeof(Apartment)))
			return nullptr;

		if (result->_myId > Apartment::id)
			Apartment::id = result->_myId + 1;

		return result;
	}
	else
		return nullptr;
}

/*
	Возвращает имя файла, в котором лежат экземпляры класса
*/
char* Apartment::getFileName()
{
	return Apartment::_fileName;
}

/*
	Метод возвращает тип сделки для квартиры
*/
DealType Apartment::getType()
{
	return this->_type;
}

/*
	Метод возвращает стоимость квартиры
*/
double Apartment::getCost()
{
	return this->_cost;
}

/*
	Возвращает указатель на следующий элемент
*/
Apartment* Apartment::next()
{
	return (Apartment*)this->_next;
}

/*
	Возвращает указатель на предыдущий элемент
*/
Apartment* Apartment::prev()
{
	return (Apartment*)this->_prev;
}

/*
	Деструктор
*/
Apartment::~Apartment()
{
}
