#pragma once
#ifndef _SONGUYENLON_H_
#define _SONGUYENLON_H_

#include "linkedlist.h"

class SoNguyenLon
{
private:
	LinkedList<int> digits;
public:
	SoNguyenLon();
	SoNguyenLon(long long number);
	SoNguyenLon(int a, int b);
	const LinkedList<int>& GetDigits() const;
	SoNguyenLon operator-(const SoNguyenLon&);
	friend SoNguyenLon operator-(long long, const SoNguyenLon&);
	SoNguyenLon operator+(const SoNguyenLon&) const;
	friend SoNguyenLon operator+(const SoNguyenLon& , long long);
	SoNguyenLon operator*(const SoNguyenLon&) const;
	friend ostream& operator<<(ostream&, const SoNguyenLon&);
	SoNguyenLon& operator=(const SoNguyenLon&);
	SoNguyenLon(const SoNguyenLon&);

};


SoNguyenLon::SoNguyenLon()
{
	digits.AddHead(0);
}

SoNguyenLon::SoNguyenLon(long long number)
{
	if (number < 0)
	{
		digits.AddHead(0);
	}
	else
	{
		while (number > 0)
		{
			digits.AddHead(number%10);
			number /= 10;
		}
	}
}

SoNguyenLon::SoNguyenLon(int a, int b)
{
	if (a < 0)
	{
		for (int i = 1; i <= b; i++)
		{
			digits.AddTail(0);
		}
	}
	else
	{
		for (int i = 1; i <= b; i++)
		{
			digits.AddTail(a);
		}
	}
}

const LinkedList<int>& SoNguyenLon::GetDigits() const
{
	return digits;
}

SoNguyenLon SoNguyenLon::operator-(const SoNguyenLon& snl) 
{
	SoNguyenLon result;
	Node<int>* p1 = this->digits.GetTail();
	Node<int>* p2 = snl.GetDigits().GetTail();

	int borrow = 0;

	while (p1 != nullptr || p2 != nullptr || borrow != 0) 
	{
		int digit1 = (p1 != nullptr) ? p1->info : 0;
		int digit2 = (p2 != nullptr) ? p2->info : 0;

		int diff = digit1 - digit2 - borrow;
		if (diff < 0) 
		{
			diff += 10;
			borrow = 1;
		}
		else 
		{
			borrow = 0;
		}

		result.digits.AddHead(diff);

		if (p1 != nullptr) p1 = p1->prev;
		if (p2 != nullptr) p2 = p2->prev;
	}
	result.digits.RemoveTail();

	return result;
}


SoNguyenLon operator-(long long num, const SoNguyenLon& snl)
{
	SoNguyenLon numObj(num);
	return numObj.operator-(snl);
}

SoNguyenLon::SoNguyenLon(const SoNguyenLon& other) 
{
	Node<int>* current = other.digits.GetHead();
	while (current != nullptr) 
	{
		this->digits.AddTail(current->info);
		current = current->next;
	}
}


SoNguyenLon& SoNguyenLon::operator=(const SoNguyenLon& other) 
{
	if (this == &other) return *this; // Kiểm tra gán cho chính nó

	// Xóa dữ liệu hiện tại
	this->digits.~LinkedList();

	// Sao chép danh sách liên kết từ `other`
	Node<int>* current = other.digits.GetHead();
	while (current != nullptr) {
		this->digits.AddTail(current->info);
		current = current->next;
	}

	return *this;
}


SoNguyenLon SoNguyenLon::operator+(const SoNguyenLon& other) const
{
	SoNguyenLon result;         
	Node<int>* p1 = this->digits.GetTail(); 
	Node<int>* p2 = other.digits.GetTail();

	int carry = 0;           

	while (p1 != nullptr || p2 != nullptr)
	{
		int digit1 = (p1 != nullptr) ? p1->info : 0;
		int digit2 = (p2 != nullptr) ? p2->info : 0;

		int sum = digit1 + digit2 + carry;
		result.digits.AddHead(sum % 10);   
		carry = sum / 10;                 

		if (p1 != nullptr) p1 = p1->prev; 
		if (p2 != nullptr) p2 = p2->prev;
	}

	result.digits.RemoveTail();

	return result;
}

SoNguyenLon operator+(const SoNguyenLon& snl, long long num) 
{
	SoNguyenLon numObj(num);
	
	return snl.operator+(num);
}

SoNguyenLon SoNguyenLon::operator*(const SoNguyenLon& snl) const 
{
	SoNguyenLon result;
	SoNguyenLon KQTam;
	result.digits.AddTail(0);
	int shift = 0;
	Node<int>* p2 = snl.digits.GetTail();

	while (p2 != nullptr)
	{
		SoNguyenLon tempResult;
		int carry = 0;
		Node<int>* p1 = this->digits.GetTail(); 

		for (int i = 0; i < shift; i++)
		{
			tempResult.digits.AddTail(0);
		}

		while (p1 != nullptr || carry != 0)
		{
			int digit1 = (p1 != nullptr) ? p1->info : 0;
			int digit2 = p2->info;

			int product = digit1 * digit2 + carry;
			tempResult.digits.AddHead(product % 10);
			carry = product / 10;

			if (p1 != nullptr) p1 = p1->prev;
		}

		tempResult.digits.RemoveTail();

		result = tempResult + result;

		shift++;
		p2 = p2->prev;
	}

	return result;
}



ostream& operator<<(ostream& os, const SoNguyenLon& snl) 
{
	Node<int>* node = snl.digits.GetHead();
	if (node == nullptr) 
	{
		os << 0;
	}
	while (node != nullptr) 
	{
		os << node->info;
		node = node->next;
	}
	return os;
}





#endif
