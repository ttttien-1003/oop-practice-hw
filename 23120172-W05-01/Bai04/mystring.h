#ifndef _MYSTRING_H_
#define _MYSTRING_H_
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class MyString
{
private:
	char* line;
	int n;
	void CopyString(const char* source) 
	{
		n = strlen(source);
		line = new char[n + 1];
		strcpy(line, source);
	}
public:
	MyString() : line(nullptr), n(0) {}
	MyString(const char*);
	MyString(const MyString&);
	~MyString();

	MyString& operator=(const MyString&);
	MyString operator+(const MyString&);
	friend MyString operator+(const char*, const MyString&);
	friend ostream& operator<<(ostream&, const MyString&);
	vector<MyString> Split(const vector<char>&, bool removeEmpty);
};

#endif
