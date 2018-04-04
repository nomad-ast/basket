#pragma once
#include<string>
#include <fstream>
template<class T> class TList
{
private:
	class ListElement;
	void _deleteElement(ListElement *deletedElement);

	ListElement *_first;
	ListElement *_last;
public:
	ListElement *_getElement(int index);
	void Add(T value);
	void Insert(int index, T value);
	void Delete(void);
	void Delete(int index);
	T GetValue(int index);
	int Count(void);
	void CopyList(TList<T> &list);

	void swap_p(ListElement *Pi, ListElement *Pj);
	void swapS(ListElement *Pi, ListElement *Pj);

	TList();
	TList(TList<T> &Object);
	~TList();

	TList &TList::operator =(TList<T> &list)
	{
		this->CopyList(list);
		return *this;
	};
	T &TList::operator [](int number);



};

template<class T>  TList<T>::TList() // конструктор по умолчанию создает пустой список
{
	_first = NULL;
	_last = NULL;
};

template<class T>  TList<T>::TList(TList<T> &list) // конструктор копирования
{
	this->_first = NULL;
	this->_last = NULL;
	// копирование элементов списка-параметра в текущий объект
	this->CopyList(list);
}
// деструктор  - освождение памяти, занимаемой элементами списка
template<class T>  TList<T>::~TList()
{
	
	ListElement *currentElement = _last;

	while (currentElement != NULL)
	{
		currentElement = _last->_prev;
		delete _last;
		_last = currentElement;
	}

	_first = NULL;
	_last = NULL;
}

template<class T> void TList<T>::CopyList(TList &list)
{
	

	this->~TList();
	for (int i = 0; i < list.Count(); i++)
		this->Add(list.GetValue(i));
}


//-------------------------------------------------------------------------------------------
// описание шаблонного класса элемента связного списка ListElement


template<class T> class TList<T>::ListElement
{
public:
	T _value;
	ListElement *_next;
	ListElement *_prev;
	ListElement()
	{
		_next = NULL;
		_prev = NULL;
		_value = 0;
	}

	ListElement(T value)
	{
		_next = NULL;
		_prev = NULL;
		_value = value;
	}
};

//-------------------------------------------------------------------------------------------
// реализация метода добавления шаблонного элемента в шаблонный 
// связный список класса TList

template<class T> void TList<T>::Add(T value)
{
	ListElement *newElement = new ListElement(value);

	if (!_first)
	{

		this->_first = newElement;
		_last = newElement;
	}

	_last->_next = newElement;

	newElement->_prev = _last;
	newElement->_next = NULL;

	_last = newElement;
	_first->_prev = NULL;
};

template<class T> int TList<T>::Count()
{
	int count = 0; ListElement *currentElement = _first;
	while (currentElement)
	{
		count++; currentElement = currentElement->_next;
	}

	return count;
}


template<class T> void PrintList(TList<T> list)
{
	for (int i = 0; i < list.Count(); i++)
		cout << list.GetValue(i) << " ";

	cout << endl;
}
//
//template<class T> void InputList(TList<T> &list, int count)
//{
//	int number;
//	cout << "Введите элементы формируемого списка: " << endl;
//	for (int i = 0; i < count; i++)
//	{
//		cin >> number;
//		list.Add(number);
//	}
//}

//-------------------------------------------------------------------------------------------
// в методе поиска элемента списка по заданному индексу
// обрабатывается аварийная ситуация (генерируется исключение),
// когда значение заданного индекса не соответствует границам списка

template<class T>  typename TList<T> ::ListElement *TList<T>::_getElement(int index)
{
	int count = this->Count();
	if (count == 0) 	throw "список пуст";
	if ((index < 0) || (index >= count))
		throw "выход за границы списка";

	ListElement* element = _first;
	for (int i = 1; i <= index; i++)   element = element->_next;
	return element;
}

template<class T> void TList<T>::_deleteElement(ListElement *deletedElement)
{
	ListElement *prev;
	ListElement *next;

	prev = deletedElement->_prev;
	next = deletedElement->_next;

	if (prev) prev->_next = next;
	else     _first = deletedElement->_next;

	if (next) next->_prev = prev;
	else    _last = deletedElement->_prev;

	delete deletedElement;
};


template<class T> T TList<T>::GetValue(int index)
{
	return _getElement(index)->_value;
}

template<class T> T &TList<T>::operator [](int index)
{
	return _getElement(index)->_value;
}

template<class T> void TList<T>::Delete()
{
	ListElement *last;

	last = _last;

	_last = _last->_prev;
	_last->_next = NULL;

	delete last;


};
template<class T> void TList<T>::Delete(int index)
{
	ListElement *deletedElement = _getElement(index);
	_deleteElement(deletedElement);
};

template<class T> void TList<T>::Insert(int index, T value)
{
	ListElement *element = _getElement(index);
	ListElement *prev = element->_prev;
	ListElement *next = element;

	element = new ListElement(value);
	element->_prev = prev;
	element->_next = next;

	if (prev) prev->_next = element;
	else	 _first = element;

	if (next) next->_prev = element;
	else	 _last = element;
}

template <class T> void TList<T>::swap_p(ListElement *Pi, ListElement *Pj){			//обмен элементво
	ListElement *t = Pi;
	Pi = Pj;
	Pj = t;
}
template <class T> void TList<T>::swapS(ListElement *Pi, ListElement *Pj){			//исключения обмена элементво 
	ListElement *tp = Pi->_prev, *tn = Pi->_next;
	if (Pi->_prev != NULL){					//если Pi не первый
		Pi->_prev->_next = Pj;
	}
	if (Pi->_next != NULL && Pi->_next != Pj){			//если Pi не последний и следующий элемент после Pi не равен Pj
		Pi->_next->_prev = Pj;
	}
	if (Pj->_prev != NULL && Pj->_prev != Pi){			//если Pj не первый и элемент до Pj не равен Pi 
		Pj->_prev->_next = Pi;
	}
	if (Pj->_next != NULL){								//если следующий после Pj не последний
		Pj->_next->_prev = Pi;
	}

	if (Pi->_next != Pj)									//если Следующий после Pi не равен Pj
	{
		Pi->_prev = Pj->_prev;
		Pi->_next = Pj->_next;
		Pj->_prev = tp;
		Pj->_next = tn;
	}
	else{
		Pi->_prev = Pj;
		Pi->_next = Pj->_next;
		Pj->_prev = tp;
		Pj->_next = Pi;
	}


	if (Pi->_next == NULL){ _last = Pi; }					//если Следующий после Pi не последний
	if (Pi->_prev == NULL){ _first = Pi; }					//если предыдущий перед Pi не первый
	if (Pj->_next == NULL){ _last = Pj; }					//если Следующий после Pj не последний
	if (Pj->_prev == NULL){ _first = Pj; }					//если предыдущий перед Pj не первый
	swap_p(Pi, Pj);
}

