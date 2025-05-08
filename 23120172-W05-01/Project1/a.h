#ifndef _A_H_
#define _A_H_

#include <iostream>

using namespace std;

#define NOE 10
class A
{
private:
	int info[NOE];
public:
	A();
	typedef int* indexOf;
	indexOf GetInfo(const int&);
	void Xuat(ostream&);
};

#endif
