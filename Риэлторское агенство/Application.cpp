#include <iostream>
#include <iomanip>

#include "Application.h"

using namespace std;


/*
	����������� ��� ����������
*/
Application::Application()
{
}

/*
	����� ���������� ������ ���������� (�������� ����)
*/
void Application::start()
{
	this->init();
	int menu_var;
	do
	{
		cout << endl;
		cout << left << setw(35) << " ---> ������� �� ������" << 1 << endl;
		cout << left << setw(35) << " ---> ��������" << 2 << endl;
		cout << left << setw(35) << " ---> �������������" << 3 << endl;
		cout << left << setw(35) << " ---> ��������� ��������" << 4 << endl;
		cout << left << setw(35) << " ---> ����� �������� � ���������" << 5 << endl;
		cout << left << setw(35) << " ---> ������� �������� �� �����" << 6 << endl;
		cout << left << setw(35) << " <--- �����" << 0 << endl;
		cin >> menu_var;
		cin.ignore();

		switch (menu_var)
		{
			// �����
			case 0:
				break;

			// �����
			case 1:
				this->print();
				break;

			// ����
			case 2:
				this->insert();
				break;

			// ��������� �� ���������
			default:
				cout << "��� ������ ������ ����, ���������� �����!" << endl;
				break;
		}
	} while (menu_var);
}

/*
	���������, ���� �� ������� ������ ��������.
	���� �������� ���� �������, ��� �� ����������� � ��������� �� �����
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
	�����, ������� �������������� ����������� �������, �������� ������ �� ������
*/
void Application::init()
{
	ifstream apartment_file(Apartment::getFileName(), ios::binary);
	ifstream deal_file(Deal::getFileName(), ios::binary);
	ifstream realtor_file(Realtor::getFileName(), ios::binary);

	// ���������� ������ �� �����
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

	// ���������� ��������� �� �����
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

	// ���������� ������� �� �����
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
	����� ���������� ��� ������
*/
void Application::print()
{
	int menu_var;
	do
	{
		cout << endl;
		cout << left << setw(20) << " -----> ��������" << 1 << endl;
		cout << left << setw(20) << " -----> ������" << 2 << endl;
		cout << left << setw(20) << " -----> ���������" << 3 << endl;
		cout << left << setw(20) << " <----- �����" << 0 << endl;
		cin >> menu_var;
		cin.ignore();

		switch (menu_var)
		{
			// �����
			case 0:
				break;

			// ��������
			case 1:
				cout << this->_apartments;
				break;
			
			// ������
			case 2:
				cout << this->_deals;
				break;

			// ��������
			case 3:
				cout << this->_realtors;;
				break;

			// ��������� �� ������ ��������
			default:
				cout << "������� �������� ��������!!!" << endl;
				break;
		}
	} while (menu_var);
}

/*
	����� ��������� �� ���������� ����� ����������� ���������
*/
void Application::insert()
{
	int menu_var;
	do
	{
		cout << endl;
		cout << left << setw(20) << " -----> ��������" << 1 << endl;
		cout << left << setw(20) << " -----> ��������" << 2 << endl;
		cout << left << setw(20) << " -----> ������" << 3 << endl;
		cout << left << setw(20) << " <----- �����" << 0 << endl;
		cin >> menu_var;
		cin.ignore();

		switch (menu_var)
		{
			// ��������
			case 1:
				this->insertApartment();
				break;

			// ��������
			case 2:
				this->InsertReltor();
				break;

			// ������
			case 3:
				this->insertDeal();
				break;

			// �����
			case 0:
				break;

			default:
				cout << "������� �������� ��������!!!" << endl;
				break;
		}
	} while (menu_var);
}

/*
	�����, ����������� ����� �������� � ���������
	� ������������ ��� �������� � ����
*/
void Application::insertApartment()
{
	Apartment* apartment_ptr = Apartment::create();
	apartment_ptr->exportToFile();
	this->_apartments.pushBack(*apartment_ptr);
}

/*
	�����, ����������� ����� ������ � ���������
	� ������������ ��� ������ � ����
*/
void Application::insertDeal()
{
	if (this->_realtors.count() && this->_apartments.count())
	{
		Realtor* realtor_ptr;
		Apartment* apartment_ptr;
		int id;
		cout << endl;
		cout << this->_realtors;
		do
		{
			cout << "������� ID ������ �� ���������: ";
			cin >> id;
			cin.ignore();
			realtor_ptr = this->_realtors.getElementById(id);
			if (!realtor_ptr)
				cout << "������ ����� ID, ���������� �����!" << endl;
		} while (!realtor_ptr);

		id = 0;
		cout << this->_apartments;
		do
		{
			cout << "������� ID ����� �� �������: ";
			cin >> id;
			cin.ignore();
			apartment_ptr = this->_apartments.getElementById(id);
			if (!apartment_ptr)
				cout << "������ ����� ID, ���������� �����!" << endl;

		} while (!apartment_ptr);

		Deal* deal_ptr = Deal::create(*apartment_ptr, *realtor_ptr);
		this->_deals.pushBack(*deal_ptr);;

		this->_apartments.pop(*apartment_ptr);
	}
	else
		cout << "��� ������ � ��������� ���� ���������!" << endl;
}

/*
	�����, ����������� ������ �������� � ���������
	� ������������ ����� �������� � ����
*/
void Application::InsertReltor()
{
	Realtor* realtor_ptr = Realtor::create();
	realtor_ptr->exportToFile();
	this->_realtors.pushBack(*realtor_ptr);
}

/*
	����������
*/
Application::~Application()
{
}
