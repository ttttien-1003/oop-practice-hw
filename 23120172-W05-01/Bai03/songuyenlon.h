#ifndef _SONGUYENLON_H_
#define _SONGUYENLON_H_

#include <iostream>
#include <vector>
using namespace std;

class SoNguyenLon
{
private:
	vector<unsigned char> lCS;
	void Pow10(const int& n);
public:
	SoNguyenLon(void);
	SoNguyenLon(const int& cs, const int& scs);
	SoNguyenLon(const unsigned long& n);
	SoNguyenLon(const SoNguyenLon& snl);
	SoNguyenLon(const char* s);
	~SoNguyenLon(void);

	int SoCS();
	SoNguyenLon operator+(SoNguyenLon snl);
	SoNguyenLon operator-(SoNguyenLon snl);
	SoNguyenLon operator*(SoNguyenLon snl);
	bool operator>(SoNguyenLon& snl);
	const SoNguyenLon& operator=(const SoNguyenLon& snl);
	SoNguyenLon& operator+=(SoNguyenLon snl);

	friend SoNguyenLon operator+(const unsigned int& n, const SoNguyenLon& snl);
	friend SoNguyenLon operator-(const unsigned int& n, const SoNguyenLon& snl);
	friend ostream& operator<<(ostream& ps, const SoNguyenLon& snl);
};


#endif