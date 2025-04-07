#pragma once

#include "data.hpp"

template <class T>
class Node
{
private:
	T* pData;
	Node* pNext;
public:
	Node(T* newData);

	~Node()
	{
		// commented out to avoid message being shown
		//cout << "inside node destructor" << endl;
	}

	T* getData()const;
	Node* getNextPtr()const;
	void setNextPtr(Node* const pNewNext);
};


template<class T>
Node<T>::Node(T* newData)
{
	this->pData = new T(*newData); // create memory for the data and set the data in the node to the data passed
	this->pNext = nullptr; // set the next pointer to null
}

template<class T>
T* Node<T>::getData() const
{
	return this->pData; // return a pointer to the data
}

template<class T>
Node<T>* Node<T>::getNextPtr() const
{
	return this->pNext; // return a pointer to the next node
}

template<class T>
void Node<T>::setNextPtr(Node* const pNewNext)
{
	this->pNext = pNewNext; // set the next pointer to the node passed
}
