#include <iostream>
#include <iomanip>

#include "Application.h"

using namespace std;


/*
	Конструктор без параметров
*/
Application::Application()
{
}

/*
	Метод начинающий работу приложения (основное меню)
*/
void Application::start()
{
	this->init();
	int menu_var;
	do
	{
		cout << endl;
		cout << left << setw(35) << "---> Вывести на печать" << 1 << endl;
		cout << left << setw(35) << "---> Добавить" << 2 << endl;
		cout << left << setw(35) << "---> Отсортировать" << 3 << endl;
		cout << left << setw(35) << "---> Интерфейс удаления" << 4 << endl;
		cout << left << setw(35) << "---> Найти квартиры в диапазоне" << 5 << endl;
		cout << left << setw(35) << "---> Прибыль реэлтора за месяц" << 6 << endl;
		cout << left << setw(35) << "---> Выход" << 0 << endl;
		cin >> menu_var;
		cin.ignore();

		switch (menu_var)
		{
			// Выход
			case 0:
				break;

			// Вывод
			case 1:
				this->print();
				break;

			// Сообщение по умлочанию
			default:
				cout << "Нет такого пункта меню, попробуйте снова!" << endl;
				break;
		}
	} while (menu_var);
}

/*
	Проверяет, была ли продана данная квартира.
	Если квартира была продана, она не загружается в программу из файла
*/
bool Application::aprtmentWasSaled(Apartment& obj)
{
	int apartmentId = obj.getId();
	for (int i = 0; i < this->_deals.count(); i++)
	{
		if (this->_deals[i].getApartmentId() == apartmentId)
			return true;
	}
	return false;
}

/*
	Метод, который инициализирует двустронние очереди, считывая данные из файлов
*/
void Application::init()
{
	ifstream apartment_file(Apartment::getFileName(), ios::in | ios::binary);
	ifstream deal_file(Deal::getFileName(), ios::binary | ios::in);
	ifstream realtor_file(Realtor::getFileName(), ios::binary | ios::in);

	// Считывание сделок из файла
	if (deal_file)
	{
		Deal* deal_ptr;
		do
		{
			deal_ptr = Deal::importFromFile(deal_file);
			if (deal_ptr)
				this->_deals.pushBack(*deal_ptr);
		} while (deal_ptr);
	}

	// Считывание реэлторов из файла
	if (realtor_file)
	{
		Realtor* realtor_ptr;
		do
		{
			realtor_ptr = Realtor::importFromFile(realtor_file);
			if (realtor_ptr)
				this->_realtors.pushBack(*realtor_ptr);
		} while (realtor_ptr);
	}

	// Считывание квартир из файла
	if (apartment_file)
	{
		Apartment* apartment_ptr;
		do
		{
			apartment_ptr = Apartment::importFromFile(apartment_file);
			if (apartment_ptr && !this->aprtmentWasSaled(*apartment_ptr))
				this->_apartments.pushBack(*apartment_ptr);
		} while (apartment_ptr);
	}

	apartment_file.close();
	deal_file.close();
	realtor_file.close();
}

/*
	Общий контроллер для печати
*/
void Application::print()
{
	int menu_var;
	do
	{
		cout << endl;
		cout << left << setw(20) << "---> Квартиры" << 1 << endl;
		cout << left << setw(20) << "---> Сделки" << 2 << endl;
		cout << left << setw(20) << "---> Реэлторов" << 3 << endl;
		cout << left << setw(20) << "<--- Назад" << 0 << endl;
		cin >> menu_var;
		cin.ignore();

		switch (menu_var)
		{
			// Выход
			case 0:
				break;

			// Квартиры
			case 1:
				cout << this->_apartments;
				break;
			
			// Сделки
			case 2:
				cout << this->_deals;
				break;

			// Реэлторы
			case 3:
				cout << this->_realtors;;
				break;

			// Сообщение об ошибке значения
			default:
				cout << "Введено неверное значение!!!" << endl;
				break;
		}
	} while (menu_var);
}
/*
	Деструктор
*/
Application::~Application()
{
}
