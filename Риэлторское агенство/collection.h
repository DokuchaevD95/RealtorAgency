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
	void pop(T& obj);
	int count();
	T& operator[](int index);
	~collection();
};

template<class T>
collection<T>::collection()
{
	this->_begin = nullptr;
	this->_end = nullptr;
	this->_count = 0;
}

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
				this->_begin = dynamic_cast<T*>(obj.next());
			if (&obj == this->_end)
				this->_end = dynamic_cast<T*>(obj.prev());
			delete &obj;
			this->_count--;

			break;
		}
		tmp = dynamic_cast<T*>(tmp->next());
	}

}

template<class T>
T& collection<T>::operator[](int index)
{
	if (index >= this->_count || index < 0)
		throw 0;

	T* tmp = this->_begin;
	for (auto i = 0; i < index; i++)
		tmp = dynamic_cast<T*>(tmp->next());

	return *tmp;
}

template<class T>
collection<T>::~collection()
{
	auto tmp = this->_begin;
	if (tmp)
		while (tmp)
		{
			auto next = tmp->next();
			delete tmp;
			tmp = dynamic_cast<T*>(next);
		}
}

template<class T>
int collection<T>::count()
{
	return this->_count;
}