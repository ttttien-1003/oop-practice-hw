#pragma once
#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

#include <iostream>
using namespace std;

template<class T>
struct Node
{
	T info;
	Node* next;
	Node* prev;
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
	Node<T>* GetHead() const;
	Node<T>* GetTail() const;

	T& operator[](const int&);
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
	Node<T>* node = new Node<T>{ value, nullptr, nullptr };
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
	node->prev = _tail;
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
	else
	{
		_head->prev = node;
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
	if (_head == nullptr)
	{
		_tail = nullptr;
	}
	else
	{
		_head->prev = nullptr;
	}
	_n--;
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
		_tail = _tail->prev;
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
Node<T>* LinkedList<T>::GetTail() const
{
	return _tail;
}

template<class T>
Node<T>* LinkedList<T>::GetHead() const
{
	return _head;
}



#endif
