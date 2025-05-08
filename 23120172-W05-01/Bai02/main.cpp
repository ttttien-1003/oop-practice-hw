#include "sllist.h"
#include <algorithm>

int main()
{
	SLList <int>l;
	l.AddTail(1);
	l.AddTail(1);
	l.AddTail(0);
	l.AddTail(4);
	l.AddTail(2);
	l.AddTail(5);
	
	for (SLList<int>::Iterator it = l.begin(); it != l.end(); ++it)
	{
		cout << *it << ", ";
	}
	cout << endl;

	for_each(l.begin(), l.end(), fnAction2);
	for_each(l.begin(), l.end(), fnAction);
	cout << endl;

	replace_if(l.begin(), l.end(), fnPredict, 100);
	cout << l << endl;

	fill(l.begin(), l.end(), 123);
	cout << l << endl;
	l.Clear();

	system("pause");
	return 0;

}