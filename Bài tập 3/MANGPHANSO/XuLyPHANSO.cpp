#include"PHANSO.h"
#include<iostream>
using namespace std;

int PHANSO::getTu() const
{
	return iTu; 
}
int PHANSO::getMau() const
{
	return iMau; 
}
PHANSO::PHANSO(int iTu, int iMau)
{
	this->iTu = iTu;
	this->iMau = (iMau != 0) ? iMau : 1; 
}
istream& operator>>(istream& is, PHANSO& ps)
{
	cout << "\nNhap tu so: "; is >> ps.iTu;
	cout << "Nhap mau so: "; is >> ps.iMau;
	return is;
}
ostream& operator<<(ostream& os, const PHANSO& ps)
{
	os << ps.iTu << "/" << ps.iMau;
	return os;
}
PHANSO& PHANSO::operator=(const PHANSO& ps)
{
	if (this != &ps)
	{
		iTu = ps.iTu;
		iMau = ps.iMau;
	}
	return *this;
}
int UCLN(int a, int b)
{
	a = abs(a);
	b = abs(b);
	while (b != 0)
	{
		int temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}
void PHANSO::RutGon() //Ham rut gon phan so
{
	if (iTu == 0)
	{
		iMau = 1;  //phan so co tu = 0 -> 0/1;
		return;
	}
	int ucln = UCLN(iTu, iMau);
	iTu /= ucln;
	iMau /= ucln;
	if (iMau < 0)
	{
		iMau = -1 * iMau;
		iTu = -1 * iTu;
	}
}
void PHANSO::Nhap()
{
	do
	{
		cout << "\nNhap phan so"; cin >> *this;
		if (iMau == 0)
			cout << "\nVui long nhap phan so hop le!";
	} while (iMau == 0);
}
void PHANSO::Xuat()
{
	this->RutGon();
	cout << *this;
}
PHANSO PHANSO::operator+(const PHANSO& ps) const
{
	PHANSO psTong;
	psTong.iTu = iTu * ps.iMau + ps.iTu * iMau;
	psTong.iMau = iMau * ps.iMau;
	return psTong;
}
PHANSO PHANSO::operator-(const PHANSO& ps) const
{
	PHANSO psHieu;
	psHieu.iTu = iTu * ps.iMau - ps.iTu * iMau;
	psHieu.iMau = iMau * ps.iMau;
	return psHieu;
}
PHANSO PHANSO::operator*(const PHANSO& ps) const
{
	PHANSO psTich;
	psTich.iTu = iTu * ps.iTu;
	psTich.iMau = iMau * ps.iMau;
	return psTich;
}
PHANSO PHANSO::operator/(const PHANSO& ps) const
{
	PHANSO psThuong;
	psThuong.iTu = iTu * ps.iMau;
	psThuong.iMau = iMau * ps.iTu;
	return psThuong;
}
bool PHANSO::operator>=(const PHANSO& ps) const
{
	return (iTu * ps.iMau >= ps.iTu * iMau);
}
bool PHANSO::operator<=(const PHANSO& ps) const
{
	return (iTu * ps.iMau <= ps.iTu * iMau);
}
bool PHANSO::operator>(const PHANSO& ps) const
{
	return (iTu * ps.iMau > ps.iTu * iMau);
}
bool PHANSO::operator<(const PHANSO& ps) const
{
	return (iTu * ps.iMau < ps.iTu * iMau);
}
bool PHANSO::operator==(const PHANSO& ps) const
{
	return (iTu * ps.iMau == ps.iTu * iMau);
}
bool isPrimeNum(int x)
{
	if (x == 2) return true;
	else if (x < 2) return false;
	for (int i = 2; i * i <= x; ++i)
	{
		if (x % i == 0)	
			return false;
	}
	return true;
}
void PHANSO::swap(PHANSO& ps1, PHANSO& ps2)
{
	PHANSO temp;
	temp.iTu = ps1.iTu;
	temp.iMau = ps1.iMau;
	ps1.iTu = ps2.iTu;
	ps1.iMau = ps2.iMau;
	ps2.iTu = temp.iTu;
	ps2.iMau = temp.iMau;
}
