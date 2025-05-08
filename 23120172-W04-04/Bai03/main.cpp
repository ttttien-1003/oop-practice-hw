#include "cstring.h"

int main()
{
	const int iN = 2;
	CString cs1("cs1_content");
	cout << "cs1" << std::endl;
	cout << "cs1++: " << cs1++ << endl << cs1 << endl;
	cout << "++ ++cs1: " << ++ ++cs1 << endl << cs1 << endl;
	system("pause");
	return 0;
}