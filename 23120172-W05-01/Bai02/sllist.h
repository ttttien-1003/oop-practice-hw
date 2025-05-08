#ifndef _SLLIST_H_
#define _SLLIST_H_

#include <iostream>
using namespace std;

template<class T>
class SLList
{
private:
	struct Node
	{
		T _info;
		Node* _pNext;
	};
	Node* _pHead, * _pTail;
	int _n;
	static Node* CreateNode(const T& value)
	{
		Node* node = new Node{ value, nullptr };
		return node;
	}
public:
	class Iterator;
	SLList();
	~SLList();

	void AddHead(const T&);
	void AddTail(const T&);
	void RemoveHead();
	void RemoveTail();
	void Clear();

	Iterator begin()
	{
		return Iterator(_pHead);
	}

	Iterator end()
	{
		return Iterator(nullptr);
	}

	template<class T>
	friend ostream& operator <<(ostream& os, const SLList<T>& ll)
	{
		SLList <T>::Node* node = ll._pHead;
		while (node != nullptr)
		{
			os << node->_info << ", ";
			node = node->_pNext;
		}
		return os;
	}
};

template<class T>
SLList<T>::SLList()
{
	_pHead = _pTail = nullptr;
	_n = 0;
}

template <class T>
SLList<T>::~SLList()
{
	_n = 0;
	Node* node = _pHead;
	while (_pHead != nullptr)
	{
		_pHead = _pHead->_pNext;
		delete node;
		node = _pHead;
	}
}

template<class T>
void SLList<T>::Clear()
{
	Node* node = _pHead;
	while (node != nullptr)
	{
		node->_info = 0;
		node = node->_pNext;
	}
}

template <class T>
void SLList<T>::AddTail(const T& value)
{
	Node* node = CreateNode(value);
	if (node == nullptr)
	{
		return;
	}
	if (_pHead == nullptr)
	{
		_pHead = _pTail = node;
		_n++;
		return;
	}
	_pTail->_pNext = node;
	_pTail = node;
	_n++;
}

template <class T>
void SLList<T>::AddHead(const T& value)
{
	Node* node = CreateNode(value);
	if (node == nullptr)
	{
		return;
	}
	if (_pHead == nullptr)
	{
		_pHead = _pTail = node;
		_n++;
		return;
	}
	Node* tmp = _pHead->_pNext;
	_pHead = node;
	_pHead->_pNext = tmp;
	_n++;
}

template <class T>
void SLList<T>::RemoveHead()
{
	Node* node = _pHead;
	delete node;
	_pHead = _pHead->_pNext;
}

template <class T>
void SLList<T>::RemoveTail()
{
	Node* node = _pHead;
	Node* prev = nullptr;
	while (node->_pNext->_pNext != nullptr)
	{
		node = node->_pNext;
	}
	prev = node->_pNext;
	delete prev;
	_pTail = node;
	_pTail->_pNext = nullptr;
}

template<class T>
class SLList<T>::Iterator
{
public:
	using iterator_category = forward_iterator_tag;
	using difference_type = ptrdiff_t;
	using value_type = T;
	using pointer = T*;
	using reference = T&;
private:
	Node* current_node;
	Iterator(Node* node) : current_node(node) {}
	friend class SLList <T>;
public:
	Iterator() : current_node(nullptr) {}
	reference operator*() const
	{
		if (!current_node)
		{
			throw out_of_range("Dereferencing end() or null iterator");
		}
		return current_node->_info;
	}
	pointer operator->() const
	{
		if (!current_node)
		{
			throw out_of_range("Accessing member via end() or null iterator");
		}
		return &(current_node->_info);
	}
	Iterator& operator++()
	{
		if (current_node)
		{
			current_node = current_node->_pNext;
		}
		else
		{
			throw out_of_range("Incrementing end() or null iterator");
		}
		return *this;
	}
	Iterator operator++(int)
	{
		if (!current_node)
		{
			throw out_of_range("Incrementing end() or null iterator");
		}
		Iterator temp = *this;
		current_node = current_node->_pNext;
		return temp;
	}
	bool operator==(const Iterator& other) const
	{
		return current_node == other.current_node;
	}
	bool operator!=(const Iterator& other) const
	{
		return !(*this == other);
	}
};

#include <algorithm>

void fnAction(int val)
{
	cout << val << ", ";
}

void fnAction2(int& val)
{
	val *= 2;
}

bool fnPredict(int val)
{
	const int threshold = 3;
	return val > threshold;
}

#endif
