#include "songuyenlon.h"

void SoNguyenLon::Pow10(const int& n)
{
	for (int i = 0; i < n; ++i)
	{
		lCS.insert(lCS.begin(), 0);
	}
}

SoNguyenLon::SoNguyenLon(void)
{
	lCS.push_back(0);
}

SoNguyenLon::SoNguyenLon(const int& cs, const int& scs)
{
	int csR = cs;
	if (csR < 1)
	{
		csR = 1;
	}
	if (csR > 9)
	{
		csR = 9;
	}
	int soCS = abs(scs);
	if (soCS < 1)
	{
		soCS = 1;
	}
	for (int i = 0; i < soCS; ++i)
	{
		lCS.push_back(csR);
	}
}

SoNguyenLon::SoNguyenLon(const unsigned long& n)
{
	unsigned long temp = n;
	while (temp > 0)
	{
		lCS.push_back(temp % 10);
		temp /= 10;
	}
}

SoNguyenLon::SoNguyenLon(const SoNguyenLon& snl)
{
	lCS = snl.lCS;
}

SoNguyenLon::SoNguyenLon(const char* s)
{
	for (int i = strlen(s)-1; i >= 0; --i)
	{
		lCS.push_back((int)s[i]);
	}
}

SoNguyenLon::~SoNguyenLon(void)
{
	// Không cần giải quyết bộ nhớ khi dùng vector
}

int SoNguyenLon::SoCS()
{
	return lCS.size();
}

bool SoNguyenLon::operator>(SoNguyenLon& snl)
{
	if (lCS.size() > snl.lCS.size())
	{
		return true;
	}
	if (lCS.size() < snl.lCS.size())
	{
		return false;
	}
	for (int i = lCS.size() - 1; i >= 0; --i)
	{
		if (lCS[i] == snl.lCS[i])
		{
			continue;
		}
		if (lCS[i] > snl.lCS[i])
		{
			return true;
		}
		return false;
	}
	return false;
}

const SoNguyenLon& SoNguyenLon::operator=(const SoNguyenLon& snl)
{
	lCS = snl.lCS;
	return *this;
}

SoNguyenLon& SoNguyenLon::operator+=(SoNguyenLon snl)
{
	SoNguyenLon snlKQ = *this + snl;
	lCS = snlKQ.lCS;
	return *this;
}

SoNguyenLon SoNguyenLon::operator+(SoNguyenLon snl)
{
	SoNguyenLon snlKQ;
	snlKQ.lCS.clear();
	SoNguyenLon* snlSCSMax = (SoCS() > snl.SoCS()) ? this : &snl;
	SoNguyenLon* snlSCSMin = (SoCS() < snl.SoCS()) ? this : &snl;
	int nho = 0, temp;
	for (int i = 0; i < snlSCSMin->SoCS(); ++i)
	{
		temp = lCS[i] + snl.lCS[i] + nho;
		snlKQ.lCS.push_back(temp % 10);
		nho = temp / 10;
	}
	for (int i = snlSCSMin->SoCS(); i < snlSCSMax->SoCS(); ++i)
	{
		temp = snlSCSMax->lCS[i] + nho;
		snlKQ.lCS.push_back(temp % 10);
		nho = temp / 10;
	}
	if (nho > 0)
	{
		snlKQ.lCS.push_back(1);
	}
	return snlKQ;
}

SoNguyenLon SoNguyenLon::operator-(SoNguyenLon snl)
{
	SoNguyenLon snlKQ;
	snlKQ.lCS.clear();
	SoNguyenLon* snlSCSMax = (SoCS() > snl.SoCS()) ? this : &snl;
	SoNguyenLon* snlSCSMin = (SoCS() < snl.SoCS()) ? this : &snl;
	if (SoCS() < snl.SoCS())
	{
		snlKQ.lCS.push_back(0);
		return snlKQ;
	}
	int nho = 0, temp;
	for (int i = 0; i < snlSCSMin->SoCS(); ++i)
	{
		if (lCS[i] - snl.lCS[i] < 0)
		{
			lCS[i] += 10;
		}
		temp = lCS[i] - snl.lCS[i] - nho;
		snlKQ.lCS.push_back(temp % 10);
		lCS[i] -= 10;
		if (lCS[i] - snl.lCS[i] < 0)
		{
			nho = 1;
		}
	}
	for (int i = snlSCSMin->SoCS(); i < snlSCSMax->SoCS(); ++i)
	{
		temp = snlSCSMax->lCS[i] - nho;
		if (temp < 0)
		{
			temp += 10;
			nho = 1;
		}
		snlKQ.lCS.push_back(temp % 10);
	}
	return snlKQ;
}

SoNguyenLon SoNguyenLon::operator*(SoNguyenLon snl)
{
	SoNguyenLon snlKQ, * psnlTemp;
	SoNguyenLon* snlSCSMax = (SoCS() > snl.SoCS()) ? this : &snl;
	SoNguyenLon* snlSCSMin = (SoCS() < snl.SoCS()) ? this : &snl;
	int nho = 0, temp;
	for (int i = 0; i < snlSCSMin->SoCS(); ++i)
	{
		psnlTemp = new SoNguyenLon;
		psnlTemp->lCS.clear();
		nho = 0;
		for (int j = 0; j < snlSCSMax->SoCS(); ++j)
		{
			temp = snlSCSMin->lCS[i] * snlSCSMax->lCS[j] + nho;
			psnlTemp->lCS.push_back(temp % 10);
			nho = temp / 10;
		}
		if (nho > 0)
		{
			psnlTemp->lCS.push_back(nho);
		}
		psnlTemp->Pow10(i);
		snlKQ += *psnlTemp;
		delete psnlTemp;
	}
	return snlKQ;
}

SoNguyenLon operator+(const unsigned int& n, const SoNguyenLon& snl)
{
	const unsigned long tmp = (const unsigned long)n;
	SoNguyenLon tmp2 = SoNguyenLon(tmp);
	SoNguyenLon KQsnl = tmp2 + snl;
	return KQsnl;
}

SoNguyenLon operator-(const unsigned int& n, const SoNguyenLon& snl)
{
	const unsigned long tmp = (const unsigned long)n;
	SoNguyenLon tmp2 = SoNguyenLon(tmp);
	SoNguyenLon KQsnl = tmp2 - snl;
	return KQsnl;
}

ostream& operator<<(ostream& os, const SoNguyenLon& snl)
{
	for (int i = snl.lCS.size() - 1; i >= 0; --i)
	{
		os << (int)snl.lCS[i];
	}
	return os;
}