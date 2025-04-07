#pragma once

#include "node.hpp"

template <class T>
class List
{
private:
	Node<T>* pHead;
public:
	List() : pHead(nullptr) {}; // set headptr to null

	~List();
	void destroyList();
	void destroyList(Node<T>* const pMem);

	Node<T>* getHeadPtr() const;

	void insert(T* newData);
};

template<class T>
List<T>::~List()
{
	cout << "inside list destructor" << endl;
	destroyList(); // destroy the list
}

template<class T>
void List<T>::destroyList()
{
	destroyList(this->pHead); // call destroy list passing in the headptr
	this->pHead = nullptr;
}

template<class T>
void List<T>::destroyList(Node<T>* const pMem)
{
	if (pMem != nullptr)
	{
		destroyList(pMem->getNextPtr()); // recursively call delete list to go to the end and work backwards
		delete pMem->getData(); // delete the data in the node
		delete pMem; // delete the node
	}
}

template<class T>
Node<T>* List<T>::getHeadPtr() const
{
	return this->pHead;
}

template<class T>
void List<T>::insert(T* newData)
{
	Node<T>* pMem = new Node<T>(newData); // create memory for the new node

	if (pMem != nullptr) // if memory was successfully allocated
	{
		pMem->setNextPtr(this->pHead); // set the pnext of the new node to phead
		this->pHead = pMem; // set the new phead to the new node
	}
}
