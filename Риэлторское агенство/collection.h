#include <iostream>

using namespace std;

#pragma once
template <class T>
class collection
{
private:
	T *_begin, *_end;
	int _count;
public:
	collection();
	void pushBack(T& obj);
	T* getElementById(int id);
	void pop(T& obj);
	int count();
	T& operator[](int index);
	void sort();
	friend ostream& operator<< <T> (ostream& out, collection<T>& obj);
	~collection();
};

/*
	Конструктор по умолчанию
*/
template<class T>
collection<T>::collection()
{
	this->_begin = nullptr;
	this->_end = nullptr;
	this->_count = 0;
}

/*
	Метод добавления элемента в конец колекции
*/
template<class T>
void collection<T>::pushBack(T& obj) 
{
	if (!this->_begin && !this->_end)
	{
		this->_begin = this->_end = &obj;
		obj.initPrevAndNext(nullptr, nullptr);
		this->_count++;
	}
	else
	{
		this->_end->setNext(&obj);
		obj.initPrevAndNext(this->_end, nullptr);
		this->_end = &obj;
		this->_count++;
	}
}

/*
	Метод извлечения из колекции элемента
*/
template<class T>
void collection<T>::pop(T& obj)
{
	if (!this->_begin && !this->_end)
		throw 0;

	T* tmp = this->_begin;
	while (tmp)
	{
		if (tmp == &obj)
		{
			if (&obj == this->_begin)
				this->_begin = obj.next();
			if (&obj == this->_end)
				this->_end = obj.prev();
			T* obj_pointer = &obj;
			delete obj_pointer;
			this->_count--;

			break;
		}
		tmp = tmp->next();
	}
}

/*
	Метод, который будет позволять обращаться к элементам колекции, используя []
*/
template<class T>
T& collection<T>::operator[](int index)
{
	if (index >= this->_count || index < 0)
		throw 0;

	T* tmp = this->_begin;
	for (auto i = 0; i < index; i++)
	{
		tmp = tmp->next();
	}

	return *tmp;
}

/*
	Деструктор
*/
template<class T>
collection<T>::~collection()
{
	T* obj = this->_begin;
	if (obj)
		while (obj)
		{
			T* next = nullptr;
			if(obj->next())
				T* next = obj->next();
			delete obj;
			obj = next;
		}
}

/*
	Гетер поля _count
*/
template<class T>
int collection<T>::count()
{
	return this->_count;
}

/*
	Возвращает указатель на элемент коллекции по идентификатору
*/
template<class T>
T* collection<T>::getElementById(int id)
{
	if (!this->_begin && !this->_end)
		return nullptr;
	else
	{
		T* obj = this->_begin;
		while (obj)
		{
			if (obj->getId() == id)
				return obj;
			obj = obj->next();
		}
		return nullptr;
	}
}

/*
	Функция сортировки коллекции методом выбора
*/
template<class T>
void collection<T>::sort()
{
	if (this->_count >= 2)
	{
		T* first_layer = this->_begin;
		while (first_layer)
		{
			T* min = first_layer->next();
			T* second_layer = first_layer->next();
			while (second_layer)
			{
				if ((*second_layer) < (*min))
					min = second_layer;
				second_layer = second_layer->next();
			}
			if (min)
			{
				if ((*min) < (*first_layer))
				{
					if (first_layer == this->_begin)
						this->_begin = min;
					if (min == this->_end)
						this->_end = first_layer;
					dequeInstance::swap(min, first_layer);
					first_layer = min;
				}
			}

			first_layer = first_layer->next();
		}
	}
}

/*
	Метод, выводящий коллекцию в консоль
*/
template<class T>
ostream& operator<<(ostream& out, collection<T>& obj)
{
	if (!obj._count)
		out << "Пока нет данных в коллекции" << endl;
	else
	{
		cout << endl << "---------------------------------------------" << endl;
		for (int i = 0; i < obj._count; i++)
			out << obj[i];
		cout << "---------------------------------------------" << endl;
	}
	return out;
}