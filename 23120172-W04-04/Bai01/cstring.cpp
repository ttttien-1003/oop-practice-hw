#include "cstring.h"

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