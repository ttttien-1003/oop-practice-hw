#include "cstring.h"

int main()
{
	const int iN = 2;
	CString cs1("cs1_content");
	cout << cs1 << std::endl;
	cout << "cs1[" << iN << "] = " << cs1[iN] << std::endl;
	cs1[iN] = 'N';
	cout << cs1 << std::endl;
	system("pause");
	return 0;
}