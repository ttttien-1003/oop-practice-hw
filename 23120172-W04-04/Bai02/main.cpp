#include "cstring.h"

int main()
{
	const int iN = 2;
	CString cs1("cs1_content");
	cout << "cs2(cs1)" << std::endl;
	CString cs2(cs1);
	cs2[iN] = '2';
	cout << "cs3 = cs1" << endl;
	CString cs3 = cs1;
	cs3[iN] = '3';
	cout << cs1 << endl << cs2 << endl << cs3 << endl;
	cout << "cs3 = cs2" << endl;
	cs3 = cs2;
	cout << cs3 << endl;
	system("pause");
	return 0;
}