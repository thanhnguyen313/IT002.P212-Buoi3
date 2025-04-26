#include <iostream>
#include "DAGIAC.h"
#include "DIEM.h"

int DAGIAC::soDaGiac = 0;
int DAGIAC::getSoDaGiac()     // Ham lay bien static dem so tam giac
{
    return soDaGiac;
}
int main()
{
    int choosen;
    do
    {
        DAGIAC ABC; ABC.input();
        do
        {
            cout << "\n\n========== CHUONG TRINH DINH NGHIA CLASS DAGIAC ==========";
            cout << "\n0. Thoat chuong trinh. ";
            cout << "\n1. Kiem tra hop le va phan loai DA GIAC. ";
            cout << "\n2. Di chuyen DA GIAC. ";
            cout << "\n3. Tinh chu vi, dien tich cua DA GIAC. ";
            cout << "\n4. So da giac da tao. ";
            cout << "\n5. Nhap da giac khac. ";
            cout << "\n6. Xoay da giac. ";
            cout << "\n7. Thu phong da giac. ";
            do
            {
                cout << "\nBan chon: "; cin >> choosen;
                if (choosen < 0 || choosen > 7)
                    cout << "\nVui long dua lua chon hop le !";
            } while (choosen < 0 || choosen > 7);
            switch (choosen)
            {
            case 0:
                cout << "\nChuong trinh dang thoat ... ";
                return 0;
            case 1:
                if (!ABC.checkPolygon())
                {
                    cout << "\nCac dinh cua da giac ban nhap vao khong tao thanh 1 da giac !";
                    break;
                }
                else
                    cout << "\nDa giac co ton tai !";
                ABC.output();
                ABC.typePolygon();
                break;
            case 2:
                ABC.displacementPolygon();
                ABC.output();
                break;
            case 3:
                cout << "\nChu vi cua da giac la: " << ABC.perimeterPolygon();
                cout << "\nDien tich cua da giac la: " << ABC.areaPolygon();
                break;
            case 4:
                cout << "\nSo da giac da tao la: " << DAGIAC::getSoDaGiac();
                break;
            case 5:
                break;
            case 6:
                ABC.rotatePolygon();
                ABC.output();
                break;
            case 7:
                ABC.zoomPolygon();
                ABC.output();
                break;
            default:
                break;
            }

        } while (choosen != 5);
    } while (choosen != 0);
    return 0;
}


