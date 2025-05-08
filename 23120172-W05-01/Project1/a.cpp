#include "a.h"

A::A()
{
	for (int i = 0; i < NOE; ++i)
	{
		info[i] = i + NOE;
	}
}

A::indexOf A::GetInfo(const int& i)
{
	indexOf rt = new int;
	rt = info + i;
	return rt;
}

void A::Xuat(ostream& os)
{
	for (int i = 0; i < NOE; ++i)
	{
		os << info[i] << ", ";
	}
	os << endl;
}