#include "DIEM.h"

// overload cho cin va cout cac diem
istream& operator>>(istream& is, DIEM& diem)
{
	double x, y;
	cout << "\nNhap hoanh do: "; is >> x;
	cout << "Nhap tung do: "; is >> y;
	diem.setXY(x, y);
	return is;
}
ostream& operator<<(ostream& os, const DIEM& diem)
{
	cout << "(" << diem.x << ";" << diem.y << ")" ;
	return os;
}
DIEM::DIEM()
{
	x = y = 0;
}
DIEM::DIEM(double x)
{
	this->x = x;
	y = 0;
}
DIEM::DIEM(double x, double y)
{
	this->x = x;
	this->y = y;
}
double DIEM::GetX() { return x; }
double DIEM::GetY() { return y; }
void DIEM::setX(double x)
{
	this->x = x;
}
void DIEM::setY(double y)
{
	this->y = y;
}
void DIEM::setXY(double x, double y)
{
	this->x = x;
	this->y = y;
}