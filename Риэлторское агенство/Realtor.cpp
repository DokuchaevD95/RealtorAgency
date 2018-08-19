#include <iostream>
#include <fstream>

#include "Realtor.h"

using namespace std;


int Realtor::id = 1;
char Realtor::_fileName[] = "realtor_base.txt";


/*
	Конструктор без параметров
*/
Realtor::Realtor()
{
	this->_myId = 0;
	this->_name = Human();
	this->_salePercent = 0;
	this->_leasePercent = 0;
}

/*
	Конструктор копирования
*/
Realtor::Realtor(const Realtor& obj)
{
	this->_myId = obj._myId;
	this->_name = obj._name;
	this->_salePercent = obj._salePercent;
	this->_leasePercent = obj._leasePercent;
}

/*
	Конструктор с параметрами
*/
Realtor::Realtor(Human& name, float salePercent, float leasePercent, int myId)
{
	if (myId <= 0)
		this->_myId = Realtor::id++;
	else
	{
		this->_myId = myId;
		if (myId >= Realtor::id)
			Realtor::id = myId + 1;
	}
	this->_name = name;
	this->_salePercent = salePercent;
	this->_leasePercent = leasePercent;
}

/*
	Статический метод, создающий новый экземпляр класса риэлтор
*/
Realtor* Realtor::create()
{
	Human name = Human::create();

	float salePercent, leasePercent;

	cout << "Введите процентную ставку для продаж: ";
	cin >> salePercent;
	cin.ignore();

	cout << endl << "Введите процентную ставку для аренды от ежемесячного платежа: ";
	cin >> leasePercent;

	return new Realtor(name, salePercent, leasePercent);
}

/*
	Перегруженный оператор сравнения
*/
bool Realtor::operator<(Realtor& obj)
{
	if (this->_salePercent < obj._salePercent)
		return true;
	else if (this->_salePercent == obj._salePercent)
	{
		if (this->_leasePercent < obj._leasePercent)
			return true;
		else return false;
	}
	else 
		return false;
}

/*
	Перегруженный оператор вывода в поток
*/
ostream& operator<<(ostream& out, Realtor& obj)
{
	out << endl;
	out << "ID: " << obj._myId << endl;
	out << "ФИО: " << obj._name << endl;
	out << "Процентная ставка для продажи: " << obj._salePercent << endl;
	out << "Процентная ставка для аренды: " << obj._leasePercent << endl;
	out << endl;

	return out;
}

/*
	Гетер ID
*/
int Realtor::getId()
{
	return this->_myId;
}

/*
	Записывает экземпляр класса в файл
*/
void Realtor::exportToFile()
{
	ofstream file(Realtor::_fileName, ios::binary | ios::out | ios::app);
	file.write((char*)this, sizeof(Realtor));
	file.close();
}

/*
	Считывает и возвращает экземпляр класса с файла
*/
Realtor* Realtor::importFromFile(ifstream& file)
{
	if (!file.eof())
	{
		Realtor* result = new Realtor();
		if (!file.read((char*)result, sizeof(Realtor)))
			return nullptr;
		if (result->_myId > Realtor::id)
			Realtor::id = result->_myId + 1;
		return result;
	}
	else
		return nullptr;
}

/*
	Возвращает процент для продажи реэлтора
*/
float Realtor::getSalePercent()
{
	return this->_salePercent;
}

/*
	Возвращает процент для аренды реэлтора
*/
float Realtor::getLeasePercent()
{
	return this->_leasePercent;
}

/*
Возвращает имя файла, в котором лежат экземпляры классаs
*/
char* Realtor::getFileName()
{
	return Realtor::_fileName;
}

/*
	Возвращает указатель на следующий элемент
*/
Realtor* Realtor::next()
{
	return (Realtor*)this->_next;
}

/*
	Возвращает указатель на предыдущий элемент
*/
Realtor* Realtor::prev()
{
	return (Realtor*)this->_prev;
}

/*
	Деструктор
*/
Realtor::~Realtor()
{	
}
