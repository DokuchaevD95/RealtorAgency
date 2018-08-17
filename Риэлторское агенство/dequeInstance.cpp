#include "dequeInstance.h"

/*
	Конструктор экземпляра двунаправленной очереди.
	"Обнуляет" указатели на предыдущий и следующий экземпляры очереди.
*/
dequeInstance::dequeInstance()
{
	this->_prev = this->_next = nullptr;
}

/*
	Конструктор копирования
*/
dequeInstance::dequeInstance(const dequeInstance& obj)
{
	this->_prev = obj._prev;
	this->_next = obj._next;
}

/*
	Определеяет указатели на предыдущий и последующие экземпляры очереди
*/
void dequeInstance::initPrevAndNext(dequeInstance* prev, dequeInstance* next)
{
	this->_prev = prev;
	this->_next = next;
}

/*
	Определяет указатель на предыдущий экзепляр очереди
*/
void dequeInstance::setPrev(dequeInstance* prev)
{
	this->_prev = prev;
}

/*
	Определеяет указатель на последующий экземпляр очереди
*/
void dequeInstance::setNext(dequeInstance* next)
{
	this->_next = next;
}

/*
	Перемещает данный экземпляр очереди вверх.
	Если перемещие состоялоть, возвращает true.
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
	Перемещает текующий экзщемпляр очереди вниз.
	Если перемещение состоялось, возвращает true.
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
	Возвращает true, если экземпляр двунаправленной очереди - начало очереди
*/
bool dequeInstance::is_begin()
{
	if (!this->_prev)
		return true;
	else return false;
}

/*
	Возвращает true, если экземпляр двунаправленной очереди - конец очереди
*/
bool dequeInstance::is_end()
{
	if (!this->_next)
		return true;
	else return false;
}

/*
	Возвращает указатель предыдущего экземпляра относительно текущего
*/
dequeInstance* dequeInstance::prev()
{
	return this->_prev;
}


/*
	Возвращает указатель следующего экземпляра очереди относительно текущего
*/
dequeInstance* dequeInstance::next()
{
	return this->_next;
}

/*
	Статический метод, перемещающий два элемента стека между собой
*/
bool dequeInstance::swap(dequeInstance* src, dequeInstance* dst)
{
	if (!src || !dst)
		return false;
	else
	{
		if (src->_prev == dst)
			src->up();
		else if (src->_next == dst)
			src->down();
		else
		{
			dequeInstance* src_prev = src->_prev;
			dequeInstance* src_next = src->_next;

			dequeInstance* dst_prev = dst->_prev;
			dequeInstance* dst_next = dst->_next;

			if (src_prev)
				src_prev->_next = dst;
			if (src_next)
				src_next->_prev = dst;

			if (dst_prev)
				dst_prev->_next = src;
			if (dst_next)
				dst_next->_prev = src;

			src->_prev = dst_prev;
			src->_next = dst_next;

			dst->_prev = src_prev;
			dst->_next = src_next;

			return true;
		}
	}
}

/*
	Деструктор экземпляра очереди, который удаляет объект и перестраивает связи
*/
dequeInstance::~dequeInstance()
{
	if (this->_prev)
		this->_prev->_next = this->_next;
	if (this->_next)
		this->_next->_prev = this->_prev;
}