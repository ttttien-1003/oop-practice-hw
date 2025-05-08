#pragma once
#ifndef _CSTRING_H_
#define _CSTRING_H_

#include <iostream>
using std::cout;
using std::ostream;

class CString
{
private:
	char* _mang;

public:
	CString();
	CString(const char*);
	~CString();
	char& operator[](const int&);
	friend ostream& operator<<(ostream&, const CString&);
};

#endif
