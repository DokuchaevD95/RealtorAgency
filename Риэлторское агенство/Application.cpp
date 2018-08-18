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
		cout << left << setw(35) << "---> ������� �� ������" << 1 << endl;
		cout << left << setw(35) << "---> ��������" << 2 << endl;
		cout << left << setw(35) << "---> �������������" << 3 << endl;
		cout << left << setw(35) << "---> ��������� ��������" << 4 << endl;
		cout << left << setw(35) << "---> ����� �������� � ���������" << 5 << endl;
		cout << left << setw(35) << "---> ������� �������� �� �����" << 6 << endl;
		cout << left << setw(35) << "---> �����" << 0 << endl;
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
	ifstream apartment_file(Apartment::getFileName(), ios::in | ios::binary);
	ifstream deal_file(Deal::getFileName(), ios::binary | ios::in);
	ifstream realtor_file(Realtor::getFileName(), ios::binary | ios::in);

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
		cout << left << setw(20) << "---> ��������" << 1 << endl;
		cout << left << setw(20) << "---> ������" << 2 << endl;
		cout << left << setw(20) << "---> ���������" << 3 << endl;
		cout << left << setw(20) << "<--- �����" << 0 << endl;
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
	����������
*/
Application::~Application()
{
}
