#include "mystring.h"


MyString::MyString(const char* str)
{
	CopyString(str);
}

MyString::MyString(const MyString& str)
{
	CopyString(str.line);
}

MyString::~MyString()
{
	delete[]line;
}


MyString& MyString::operator=(const MyString& str)
{
	if (this != &str)
	{
		delete[]line;
		CopyString(str.line);
	}
	return *this;
}

MyString MyString::operator+(const MyString& str)
{
	int size = n + str.n;
	char* newLine = new char[size + 1];

	strcpy(newLine, str.line);
	strcat(newLine, line);

	MyString result(newLine);
	return result;

}

MyString operator+(const char* other, const MyString& str)
{
	MyString tmp(other);
	char* newLine = new char[tmp.n + str.n + 1];

	strcpy(newLine, tmp.line);
	strcat(newLine, str.line);

	MyString result(newLine);
	delete[]newLine;
	return result;
}

ostream& operator<<(ostream& os, const MyString& str)
{
	os << str.line;
	return os;
}

vector<MyString> MyString::Split(const vector<char>& v, bool removeEmpty)
{
    std::vector<MyString> result;
    if (line == nullptr) 
    {
        return result;
    }
    int currentWordStart = 0;
    for (int i = 0; i <= n; ++i) 
    {
        bool isDelimiter = false;
        if (i < n) 
        {
            for (auto delimiter : v) 
            {
                if (line[i] == delimiter) 
                {
                    isDelimiter = true;
                    break;
                }
            }
        }

        if (isDelimiter || i == n) 
        {
            int currentWordLength = i - currentWordStart;
            if (currentWordLength > 0 || !removeEmpty) 
            {
                char* word = new char[currentWordLength + 1];
                std::strncpy(word, line + currentWordStart, currentWordLength);
                word[currentWordLength] = '\0';
                result.push_back(MyString(word));
                delete[] word;
            }
            currentWordStart = i + 1;
        }
    }
    return result;
}