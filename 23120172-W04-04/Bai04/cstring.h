#pragma once
#ifndef _CSTRING_H_
#define _CSTRING_H_

#include <iostream>
using namespace std;

class CString
{
private:
	char* _mang;

public:
	CString();
	CString(const char*);
	CString(const CString&);
	~CString();

	char& operator[](const int&);
	CString& operator=(const CString&);
	friend ostream& operator<<(ostream&, const CString&);
};

CString::~CString()
{
	if (_mang != nullptr)
	{
		delete[] _mang;
	}
}

CString::CString()
{
	_mang = nullptr;
}

CString::CString(const char* str)
{
	int len = strlen(str);
	_mang = new char[len + 1];
	strcpy_s(_mang, len + 1, str);
}

CString::CString(const CString& cs) : CString(cs._mang)
{
	
}

char& CString::operator[](const int& i)
{
	int len = strlen(_mang);
	if (i < 0 || i >= len)
	{
		throw std::exception("out of range");
	}
	return _mang[i];
}

ostream& operator<<(ostream& os, const CString& cs)
{
	os << cs._mang;
	return os;
}

CString& CString::operator=(const CString& cs)
{
	if (this == &cs)
	{
		return *this;
	}
	if (_mang != nullptr)
	{
		delete[]_mang;
	}
	int len = strlen(cs._mang) + 1;
	_mang = new char[len];
	strcpy_s(_mang, len, cs._mang);
	return *this;
}


#endif
