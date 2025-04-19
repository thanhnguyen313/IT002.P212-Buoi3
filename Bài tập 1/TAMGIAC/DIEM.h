#pragma once
#include <iostream>
using namespace std;
class DIEM
{
private:
	double x, y;
public:
	DIEM();
	DIEM(double x);
	DIEM(double x, double y);
	double GetX();
	double GetY();
	void setX(double x);
	void setY(double y);
	void setXY(double x, double y);
	friend istream& operator>>(istream& is, DIEM& diem);
	friend ostream& operator<<(ostream& os, const DIEM& diem);

};

