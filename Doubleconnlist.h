#ifndef DOUBLECONNLIST_H
#define DOUBLECONNLIST_H
#pragma once
#include "iostream"
using namespace std;

template <typename T>
class DoubleConnList
{
public:
	DoubleConnList()
	{
		firstElement = nullptr;
		lastElement = nullptr;
	}

	DoubleConnList(DoubleConnList& T)
	{
		firstElement = nullptr;
		lastElement = nullptr;

		Element* current_element = T.firstElement;

		while (current_element)
		{
			add(current_element->data);
			current_element = current_element->ptrNextElement;
		}

	}
	DoubleConnList& operator = (const DoubleConnList& T)
	{
		if (this == &T)
		{
			return *this;
		}


		clear();

		Element* current_element = T.firstElement;

		while (current_element)
		{
			add(current_element->data);
			current_element = current_element->ptrNextElement;
		}
		return *this;
	}

	DoubleConnList(DoubleConnList&& T) noexcept
	{
		firstElement = T.firstElement;
		lastElement = T.lastElement;
		T.firstElement = nullptr;
		T.lastElement = nullptr;
	}

	DoubleConnList& operator = (DoubleConnList&& T) noexcept
	{
		if (this == &T)
		{
			return *this;
		}

		firstElement = T.firstElement;
		lastElement = T.lastElement;
		T.firstElement = nullptr;
		T.lastElement = nullptr;

		return *this;
	}


	~DoubleConnList()
	{
		clear();
		delete firstElement;
		delete lastElement;
	}

	void add(char data)
	{
		Element* new_element = new Element;
		new_element->data = data;
		new_element->ptrNextElement = nullptr;
		new_element->ptrPrevElement = nullptr;

		if (!lastElement)
		{
			new_element->ptrNextElement = nullptr;
			firstElement = new_element;
		}
		else
		{
			lastElement->ptrNextElement = new_element;
			new_element->ptrPrevElement = lastElement;
		}
		lastElement = new_element;
	}
	void show()
	{
		if (!lastElement)
		{
			cout << "list empty" << endl;
			return;
		}

		Element* current_element = firstElement;
		cout << current_element->data << endl;

		while (current_element->ptrNextElement)
		{
			current_element = current_element->ptrNextElement;
			cout << current_element->data << endl;
		}
		cout << endl;
	}
	void reverse()
	{
		if (!lastElement)
		{
			cout << "Empty " << endl;
			return;
		}
		Element* current_element = firstElement;
		Element* next_element = nullptr;
		Element* prev_element = nullptr;

		do
		{
			prev_element = current_element->ptrPrevElement;
			next_element = current_element->ptrNextElement;

			current_element->ptrPrevElement = next_element;
			current_element->ptrNextElement = prev_element;

			current_element = next_element;
		} while (current_element);

		current_element = firstElement;
		firstElement = lastElement;
		lastElement = current_element;
	}
	void insert(char data, int index)
	{
		Element* new_element = new Element;
		new_element->data = data;
		if (index == 0)
		{

			new_element->ptrNextElement = firstElement;
			new_element->ptrPrevElement = nullptr;
			firstElement->ptrPrevElement = new_element;
			firstElement = new_element;
			return;
		}
		else
		{
			Element* ptrFirst;
			ptrFirst = firstElement;
			for (int i = 0; i < index; i++)
			{
				if (ptrFirst->ptrNextElement)
					ptrFirst = ptrFirst->ptrNextElement;
			}


			if (ptrFirst == lastElement)
			{
				lastElement->ptrNextElement = new_element;
				new_element->ptrPrevElement = lastElement;
				new_element->ptrNextElement = nullptr;
				lastElement = new_element;
				return;
			}
			else
			{
				new_element->ptrPrevElement = ptrFirst->ptrPrevElement;
				new_element->ptrNextElement = ptrFirst;
				ptrFirst->ptrPrevElement = new_element;
				new_element->ptrPrevElement->ptrNextElement = new_element;
			}
		}
	}
	void remove(int index)
	{

		Element* delElement = firstElement;

		for (int i = 0; i < index; i++)
		{
			delElement = delElement->ptrNextElement;
		}

		if (firstElement == lastElement)
		{
			clear();
			return;
		}

		if (delElement == firstElement)
		{
			Element* next_element = delElement->ptrNextElement;
			firstElement = next_element;
			next_element->ptrPrevElement = 0;
		}
		else if (delElement == lastElement)
		{
			Element* next_element = delElement->ptrPrevElement;
			lastElement = next_element;
			next_element->ptrNextElement = 0;
		}

		else
		{
			Element* prev_element = delElement->ptrPrevElement;
			Element* next_element = delElement->ptrNextElement;

			next_element->ptrPrevElement = prev_element;
			prev_element->ptrNextElement = next_element;
		}


		delElement->data = 0;
		delElement->ptrNextElement = 0;
		delElement->ptrPrevElement = 0;
		delete delElement;

	}
	void clear()
	{
		if (!lastElement && !firstElement)
		{
			return;
		}
		Element<T>* current_element = lastElement;
		while (lastElement != firstElement)
		{
			lastElement = lastElement->ptrPrevElement;
			current_element = nullptr;
			delete current_element;
			current_element = lastElement;
		}
		firstElement = nullptr;
		lastElement = nullptr;


	}



private:
	template <typename T>
	struct Element
	{
		Element<T>* ptrPrevElement;
		T data;
		Element<T>* ptrNextElement;
	};

	Element<T>* firstElement;
	Element<T>* lastElement;

};

/*
template <typename T>
DoubleConnList<T>::DoubleConnList()
{
}

template <typename T>
void DoubleConnList<T>::add(char data)
{
	
}
template <typename T>
void DoubleConnList<T>::show()

template <typename T>
void DoubleConnList<T>::reverse()

template <typename T>
void DoubleConnList<T>::insert(char data, int index)



template <typename T>
void DoubleConnList<T>::remove(int index)


template <typename T>
void DoubleConnList<T>::clear()
*/



#endif // DOUBLECONNLIST_H