#pragma once
#include <iostream>
#include <cmath>
using namespace std;
class PHANSO
{
private:
	int iTu;
	int iMau;
public:
	void Nhap();
	void Xuat();
	void RutGon();
	int getTu() const;
	int getMau() const;
	PHANSO(int iTu = 0, int iMau = 1);
	friend istream& operator>>(istream& is, PHANSO& ps);
	friend ostream& operator<<(ostream& os, const PHANSO& ps);
	PHANSO operator+(const PHANSO& ps) const;
	PHANSO operator-(const PHANSO& ps) const;
	PHANSO operator*(const PHANSO& ps) const;
	PHANSO operator/(const PHANSO& ps) const;
	PHANSO& operator=(const PHANSO& ps);
	bool operator>=(const PHANSO& ps) const;
	bool operator<=(const PHANSO& ps) const;
	bool operator>(const PHANSO& ps) const;
	bool operator<(const PHANSO& ps) const;
	bool operator==(const PHANSO& ps) const;
	PHANSO Tong(const PHANSO& ps);
	PHANSO Hieu(const PHANSO& ps);
	PHANSO Tich(const PHANSO& ps);
	PHANSO Thuong(const PHANSO& ps);
	void swap(PHANSO& ps1, PHANSO& ps2);
};
int UCLN(int a, int b);
bool isPrimeNum(int x);