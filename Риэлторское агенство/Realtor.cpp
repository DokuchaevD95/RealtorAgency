#include "Realtor.h"


int Realtor::id = 1;
char Realtor::_fileName[] = "_realtor_base.txt";


/*
	Конструктор без параметров
*/
Realtor::Realtor()
{
	this->_myId = Realtor::id++;
	this->_name = Human();
	this->_percent = 0;
}

/*
	Конструктор копирования
*/
Realtor::Realtor(const Realtor& obj)
{
	this->_myId = obj._myId;
	this->_name = obj._name;
	this->_percent = obj._percent;
}

/*
	Конструктор с параметрами
*/
Realtor::Realtor(Human& name, float percent, int myId)
{
	if (myId <= 0)
		this->_myId = Realtor::id++;
	else
		this->_myId = myId;
	this->_name = name;
	this->_percent = percent;
}

/*
	Статический метод, создающий новый экземпляр класса риэлтор
*/
Realtor Realtor::create()
{
	Human name = Human::create();

	float percent;
	cout << "Введите процентную ставку: ";
	cin >> percent;
	cin.ignore();

	return Realtor(name, percent);
}

/*
	Перегруженный оператор сравнения
*/
bool Realtor::operator<(Realtor& obj)
{
	if (this->_percent < obj._percent)
		return true;
	else 
		return false;
}

/*
	Перегруженный оператор вывода в поток
*/
ostream& operator<<(ostream& out, Realtor& obj)
{
	out << "-----------------Риэлтор----------------" << endl << endl;
	out << "ФИО: " << obj._name << endl;
	out << "Процентная ставка: " << obj._percent << endl;
	out << endl << "----------------------------------------" << endl;

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
	Деструктор
*/
Realtor::~Realtor()
{
	
}
