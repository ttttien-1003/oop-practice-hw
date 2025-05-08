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

	CString& operator++();
	CString operator++(int);
	char& operator[](const int&);
	CString& operator=(const CString&);
	friend ostream& operator<<(ostream&, const CString&);
};

#endif
