#pragma once
#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

#include <iostream>
#include "cstring.h"
using namespace std;

template<class T>
struct Node
{
	T info;
	Node* next;
};

template<class T>
class LinkedList
{
private:
	Node<T>* _head, * _tail;
	int _n;
	static Node<T>* CreateNode(const T&);

public:
	LinkedList();
	~LinkedList();

	Node<T>* AddHead(const T&);
	Node<T>* AddTail(const T&);
	Node<T>* RemoveHead();
	Node<T>* RemoveTail();

	T& operator[](const int&);

	template<class T>
	friend ostream& operator<<(ostream&, const LinkedList<T>&);
};

template<class T>
LinkedList<T>::LinkedList()
{
	_head = _tail = nullptr;
	_n = 0;
}

template<class T>
LinkedList<T>::~LinkedList()
{
	_n = 0;
	Node<T>* node = _head;
	while (_head != nullptr)
	{
		_head = _head->next;
		delete node;
		node = _head;
	}
}

template <class T>
Node<T>* LinkedList<T>::CreateNode(const T& value)
{
	Node<T>* node = new Node<T>{ value, nullptr };
	return node;
}

template <class T>
Node<T>* LinkedList<T>::AddTail(const T& value)
{
	Node<T>* node = CreateNode(value);
	if (node == nullptr)
	{
		return nullptr;
	}
	if (_head == nullptr)
	{
		_head = _tail = node;
		_n++;
		return node;
	}
	_tail->next = node;
	_tail = node;
	_n++;
	return node;
}

template<class T>
Node<T>* LinkedList<T>::AddHead(const T& value)
{
	Node<T>* node = CreateNode(value);
	node->next = _head;
	if (_head == nullptr)
	{
		_tail = node;
	}
	_head = node;
	_n++;
	return node;
}

template<class T>
Node<T>* LinkedList<T>::RemoveHead()
{
	if (_head == nullptr)
	{
		return nullptr;
	}
	Node<T>* node = _head;
	_head = _head->next;
	_n--;
	if (_head == nullptr)
	{
		_tail = nullptr;
	}
	return node;
}

template<class T>
Node<T>* LinkedList<T>::RemoveTail()
{
	if (_head == nullptr)
	{
		return nullptr;
	}
	Node<T>* node = _tail;
	if (_head == _tail)
	{
		_head = _tail = nullptr;
	}
	else
	{
		Node<T>* prev = _head;
		while (prev->next != _tail)
		{
			prev = prev->next;
		}
		_tail = prev;
		_tail->next = nullptr;
	}
	_n--;
	return node;
}

template<class T>
T& LinkedList<T>::operator[](const int& i)
{
	if (i < 0 || i >= _n)
	{
		throw exception("out of range");
	}
	Node<T>* node = _head;
	for (int j = 0; j < i; j++)
	{
		node = node->next;
	}
	return node->info;
}

template<class T>
ostream& operator<<(ostream& os, const LinkedList<T>& ll)
{
	Node<T>* node = ll._head;
	while (node != nullptr)
	{
		os << node->info << ", ";
		node = node->next;
	}
	return os;
}


#endif
