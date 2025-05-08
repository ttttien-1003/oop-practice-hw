#include "a.h"

int main()
{
	const int i = 7;
	A a;
	A::indexOf io = a.GetInfo(i);
	cout << *io << endl;
	*io = 10;
	a.Xuat(cout);

	system("pause");
	return 0;
}