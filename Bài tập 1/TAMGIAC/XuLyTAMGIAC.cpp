#include <iostream>
#include <cmath>
#include <iomanip>
#include "TAMGIAC.h"
#include "DIEM.h"

// set, get cho cac diem cua tam giac va constructor tam giac
void TAMGIAC::setA(DIEM a) { A = a; }
DIEM TAMGIAC::getA() const { return A; }
void TAMGIAC::setB(DIEM b) { B = b; }
DIEM TAMGIAC::getB() const { return B; }
void TAMGIAC::setC(DIEM c) { C = c; }
DIEM TAMGIAC::getC() const { return C; }
TAMGIAC::TAMGIAC() 
{
    A = { 0, 0 };
    B = { 0, 0 };
    C = { 0, 0 };
    soTamGiac++;
}
TAMGIAC::TAMGIAC(DIEM a, DIEM b, DIEM c)
{
    A = a;
    B = b;
    C = c;
}

void TAMGIAC::input()       // Ham nhap cac diem vao tam giac 
{
	DIEM a, b, c;
	cout << "\nNhap 3 dinh cua tam giac: \n";
    cout << "\nDinh A: "; cin >> a; setA(a);
    cout << "\nDinh B: "; cin >> b; setB(b);
    cout << "\nDinh C: "; cin >> c; setC(c);
}
void TAMGIAC::output()      // Ham xuat cac diem cua tam giac
{
    cout << "\n3 dinh cua tam giac la: A" << this->getA() << " B" << this->getB() << " C" << this->getC();
}
double TAMGIAC::lenV(DIEM x, DIEM y)        // Ham tinh toan do dai cua 1 canh dua tren "do doi" cua vecto giua 2 diem
{
    // Su dung class DIEM de bieu dien "do doi" cua vecto AB, BC va AC trong mat phang vAB(vx;vy)...;
    DIEM vXY;
    vXY.setXY(y.GetX() - x.GetX(), y.GetY() - x.GetY());
    // Tinh do dai cac canh tam giac dua tren vecto
    double XY = sqrt(pow(vXY.GetX(), 2) + pow(vXY.GetY(), 2));
    return round(XY * 100) / 100.0;
}
bool TAMGIAC::checkTriangle()       // Ham kiem tra xem tam giac (ABC) co ton tai hay khong ? 
{
    double AB = this->lenV(A, B), BC = this->lenV(B, C), AC = this->lenV(A, C);
    if (AB + BC <= AC)
        return false;
    if (AB + AC <= BC)
        return false;
    if (BC + AC <= AB)
        return false;
    return true;
}
void TAMGIAC::typeTriangle()        // Ham phan loai tam giac
{
    double AB = this->lenV(A, B), BC = this->lenV(B, C), AC = this->lenV(A, C);
    if (pow(AB, 2) + pow(BC, 2) == pow(AC, 2) || pow(AB, 2) + pow(AC, 2) == pow(BC, 2) || pow(AC, 2) + pow(BC, 2) == pow(AB, 2))
        cout << "\nDay la tam giac vuong !";
    else if ((AB == AC && AC == BC))
        cout << "\nDay la tam giac deu !";
    else if (AB == BC || AB == AC || BC == AC)
        cout << "\nDay la tam giac can !";
    else
        cout << "\nDay la tam giac thuong !";
}
void TAMGIAC::displacementTriangle()        // Ham dich chuyen (tinh tien tam giac)
{
    // coi do doi cua vecto la 1 diem
    DIEM vDisplacement; cout << "\nNhap vecto dich chuyen tam giac !"; cin >> vDisplacement;
    DIEM a, b, c;
    // Thuc hien tinh tien 3 dinh cua tam giac: A(x, y) => A'(x + vx, y + vy) (vecto tinh tien v(vx, vy). );
    a.setXY(this->getA().GetX() + vDisplacement.GetX(), this->getA().GetY() + vDisplacement.GetY());
    b.setXY(this->getB().GetX() + vDisplacement.GetX(), this->getB().GetY() + vDisplacement.GetY());
    c.setXY(this->getC().GetX() + vDisplacement.GetX(), this->getC().GetY() + vDisplacement.GetY());
    // Set lai cac dinh moi cho tam giac
    this->setA(a); this->setB(b); this->setC(c);
}   
double TAMGIAC::perimeterTriangle()         // Ham tinh chu vi tam giac
{
    double AB = this->lenV(A, B), BC = this->lenV(B, C), AC = this->lenV(A, C);
    return AB + BC + AC;
}
double TAMGIAC::acreageTriangle()           // Ham tinh dien tich tam giac
{
    double AB = this->lenV(A, B), BC = this->lenV(B, C), AC = this->lenV(A, C);
    double p = this->perimeterTriangle() / 2;
    return sqrt(p * (p - AB) * (p - BC) * (p - AC));    // Su dung cong thuc herong tam giac
}
void TAMGIAC::rotateTriangle()          // Ham quay tam giac quanh goc toa do O (0,0)
{
    DIEM a = this->getA(), b = this->getB(), c = this->getC();
    double angle; int chooseAngle;
    const double pi = 3.14159265358979323846;
    cout << "\n0. Do ";
    cout << "\n1. Radian ";
    cout << "\nChon don vi goc: "; cin >> chooseAngle;
    do
    {
        if (chooseAngle > 1 || chooseAngle < 0)
            cout << "\nVui long nhap lua chon hop le !";
        cout << "\nNhap do quay:  "; cin >> angle;
        if (chooseAngle == 0)
            angle = (angle * pi) / 180;     // Doi do sang don vi radian
        // Thuc hien phep quay toa do quanh goc O voi 3 dinh cua tam giac
        a.setXY(a.GetX() * cos(angle) - a.GetY() * sin(angle), a.GetX() * sin(angle) + a.GetY() * cos(angle));
        b.setXY(b.GetX() * cos(angle) - b.GetY() * sin(angle), b.GetX() * sin(angle) + b.GetY() * cos(angle));
        c.setXY(c.GetX() * cos(angle) - c.GetY() * sin(angle), c.GetX() * sin(angle) + c.GetY() * cos(angle));
        // Set lai cac dinh tam giac
        this->setA(a); this->setB(b); this->setC(c);
    } while (chooseAngle > 1 || chooseAngle < 0);
}
void TAMGIAC::zoomTriangle()        // Ham thu phong tam giac
{
    double k; cout << "\nNhap do thu phong (k < 0: thu ; k > 0: phong) k = "; cin >> k;
    DIEM a = this->getA(), b = this->getB(), c = this->getC();
    // Thu hien thu phong cac dinh cua tam giac: A(x, y) => A(k*x, k*y);
    a.setXY(a.GetX() * k, a.GetY() * k);
    b.setXY(b.GetX() * k, b.GetY() * k);
    c.setXY(c.GetX() * k, c.GetY() * k);
    // Set lai cac dinh tam giac
    this->setA(a); this->setB(b); this->setC(c);
}