#include <iostream>
#include <cmath>
#include <iomanip>
#include "DAGIAC.h"
#include "DIEM.h"


void DAGIAC::input()       // Ham nhap cac diem vao da giac 
{
    cout << "\nNhap so dinh cua da giac: "; cin >> n;
    cout << "\nNhap cac dinh cua da giac: ";
    for (int i = 0; i < n; i++)
    {
        DIEM a; cout << "\nDiem " << i + 1 << " : "; cin >> a;
        pointOfPolygon.push_back(a);
    }
    for (int i = 0; i < n; i++) // Tinh do dai cua cac canh trong da giac
    {
        if (i == 0)
            edgeOfPolygon.push_back(lenV(pointOfPolygon[0], pointOfPolygon[n - 1]));
        else
            edgeOfPolygon.push_back(lenV(pointOfPolygon[i], pointOfPolygon[i - 1]));
    }
}
void DAGIAC::output()      // Ham xuat cac diem cua da giac
{
    cout << "\nCac dinh cua da giac la: ";
    for (int i = 0; i < n; i++)
    {
        cout << pointOfPolygon[i];
    }
}
double DAGIAC::lenV(DIEM x, DIEM y)        // Ham tinh toan do dai cua 1 canh dua tren "do doi" cua vecto giua 2 diem
{
    // Su dung class DIEM de bieu dien "do doi" cua vecto AB trong mat phang vAB(vx;vy)...;
    DIEM vXY;
    vXY.setXY(y.GetX() - x.GetX(), y.GetY() - x.GetY());
    // Tinh do dai cac canh tam giac dua tren vecto
    double XY = sqrt(pow(vXY.GetX(), 2) + pow(vXY.GetY(), 2));
    return round(XY * 100) / 100.0;
}
DIEM DAGIAC::vectorOfPoint(DIEM x, DIEM y)
{
    DIEM vXY;
    vXY.setXY(y.GetX() - x.GetX(), y.GetY() - x.GetY());
    return vXY;
}
bool DAGIAC::checkPolygon()       // Ham kiem tra xem da giac co ton tai hay khong ?  => tat ca cac dinh cua da giac co thang hang ko ?
{
    if (n < 3) // Neu chi co 2 diem thi ko la da giac
        return false;
    // So sanh cac vecto giua cac diem, neu co it nhat 3 diem khong thang hang thi da giac co ton tai (Kiem tra xem 2 vecto cua 3 diem lien ke nhau co khong cung phuong ko)
    vector <DIEM> vEdge;
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
            vEdge.push_back(vectorOfPoint(pointOfPolygon[0], pointOfPolygon[n - 1]));
        else
            vEdge.push_back(vectorOfPoint(pointOfPolygon[i], pointOfPolygon[i - 1]));
    }
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            if (vEdge[0].GetX() * vEdge[n - 1].GetY() - vEdge[0].GetY() * vEdge[n - 1].GetX() != 0) // Neu 2 vecto dau va cuoi ko co cung phuong thi co it nhat 3 diem ko thang hang
                return true;
        }
        if (vEdge[i].GetX() * vEdge[i - 1].GetY() - vEdge[i].GetY() * vEdge[i - 1].GetX() != 0)
            return true;
    }
    return false;
}
void DAGIAC::typePolygon()      // Ham kiem tra phan loai da giac loi/lom va deu/khong deu
{
    bool isConvex = true; // Kiem tra tinh loi/lom cua da giac
    int prevCross = 0;  // Luu dau tich co huong truoc do de so sanh
    // Lap qua cac bo 3 diem lien tiep de kiem tra
    for (int i = 0; i < n; i++)
    {
        // Lay ba diem lien tiep A, B, C
        DIEM A = pointOfPolygon[i];
        DIEM B = pointOfPolygon[(i + 1) % n];  
        DIEM C = pointOfPolygon[(i + 2) % n];  
        DIEM AB = vectorOfPoint(A, B);
        DIEM BC = vectorOfPoint(B, C);
        // Tinh tich co huong (cross product)
        int cross = AB.GetX() * BC.GetY() - AB.GetY() * BC.GetX();
        // Kiem tra neu tich co huong khac 0 (co goc)
        if (cross != 0)
        {
            // Neu day la lan kiem tra dau tien, luu dau tich co huong
            if (prevCross == 0)
                prevCross = (cross > 0) ? 1 : -1;
            else if ((cross > 0 && prevCross < 0) || (cross < 0 && prevCross > 0))
            {
                // Neu co tich co huong trai dau, da giac la lom
                isConvex = false;
                break;
            }
        }
    }
    // In thong tin ve da giac
    cout << "\nDa giac co " << n << " dinh. ";
    // In ket qua loi/lom
    if (isConvex)
        cout << "\nDay la da giac loi." << endl;
    else
        cout << "\nDay la da giac lom." << endl;

    // Kiem tra tinh deu hay khong deu
    double lenEdge = edgeOfPolygon[0];
    bool checkRegularPolygon = true; // Bien xac dinh da giac co deu hay ko
    for (int i = 0; i < n; i++)
    {
        if (edgeOfPolygon[i] != lenEdge)
            checkRegularPolygon = false;
    }
    if (checkRegularPolygon)
        cout << "\nDay la da giac deu !";
    else
        cout << "\nDay khong la da giac deu !";
}

void DAGIAC::displacementPolygon()        // Ham dich chuyen (tinh tien da giac)
{
    // coi do doi cua vecto la 1 diem
    DIEM vDisplacement; cout << "\nNhap vecto dich chuyen tam giac !"; cin >> vDisplacement;
    for (int i = 0; i < n; i++)
    {
        pointOfPolygon[i].setXY(pointOfPolygon[i].GetX() + vDisplacement.GetX(), pointOfPolygon[i].GetY() + vDisplacement.GetY());
    }
}
double DAGIAC::perimeterPolygon()         // Ham tinh chu vi da giac
{
    double perimeterPolygon = 0;
    for (int i = 0; i < n; i++)
    {
        perimeterPolygon += edgeOfPolygon[i];
    }
    return perimeterPolygon;
}   
double DAGIAC::areaPolygon()        // Ham tinh dien tich da giac
{
    double area = 0.0;
    // Tinh to hop x * y cua cac cap diem ke nhau va tru nguoc lai
    for (int i = 0; i < n; i++)
    {
        int j = (i + 1) % n;  // Diem ke tiep, neu la diem cuoi thi quay ve diem dau
        area += pointOfPolygon[i].GetX() * pointOfPolygon[j].GetY();
        area -= pointOfPolygon[j].GetX() * pointOfPolygon[i].GetY();
    }
    // Lay tri tuyet doi va chia doi de tinh dien tich
    area = fabs(area) / 2.0;
    return area;
}
void DAGIAC::rotatePolygon()          // Ham quay da giac quanh goc toa do O (0,0)
{
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
        // Thuc hien phep quay toa do quanh goc O cac dinh cua da giac
        for (int i = 0; i < n; i++)
        {
            pointOfPolygon[i].setXY(pointOfPolygon[i].GetX() * cos(angle) - pointOfPolygon[i].GetY() * sin(angle), pointOfPolygon[i].GetX() * sin(angle) + pointOfPolygon[i].GetY() * cos(angle));
        }
    } while (chooseAngle > 1 || chooseAngle < 0);
}
void DAGIAC::zoomPolygon()        // Ham thu phong tam giac
{
    double k; cout << "\nNhap do thu phong (k < 0: thu ; k > 0: phong) k = "; cin >> k;
    // Thu hien thu phong cac dinh cua tam giac: A(x, y) => A(k*x, k*y);
    for (int i = 0; i < n; i++)
    {
        pointOfPolygon[i].setXY(pointOfPolygon[i].GetX() * k, pointOfPolygon[i].GetY() * k);
    }
}