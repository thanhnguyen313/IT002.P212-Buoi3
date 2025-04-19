#include <iostream>
#include "TAMGIAC.h"
#include "DIEM.h"

int TAMGIAC::soTamGiac = 0;
int TAMGIAC::getSoTamGiac()     // Ham lay bien static dem so tam giac
{
    return soTamGiac;
}
int main()
{
    int choosen;
    do
    {
        TAMGIAC ABC; ABC.input();
        do
        {
            cout << "\n\n========== CHUONG TRINH DINH NGHIA CLASS TAMGIAC ==========";
            cout << "\n0. Thoat chuong trinh. ";
            cout << "\n1. Kiem tra hop le va phan loai TAM GIAC. ";
            cout << "\n2. Di chuyen TAM GIAC. ";
            cout << "\n3. Tinh chu vi, dien tich cua TAM GIAC. ";
            cout << "\n4. So tam giac da tao. ";
            cout << "\n5. Nhap tam giac khac. ";
            cout << "\n6. Xoay tam giac. ";
            cout << "\n7. Thu phong tam giac. ";
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
                if (!ABC.checkTriangle())
                {
                    cout << "\n3 dinh cua tam giac ban nhap vao khong tao thanh 1 tam giac !";
                    break;
                }
                else
                    cout << "\nTam giac co ton tai !";
                ABC.output();
                ABC.typeTriangle();
                break;
            case 2:
                ABC.displacementTriangle();
                ABC.output();
                break;
            case 3:
                cout << "\nChu vi cua tam giac la: " <<  ABC.perimeterTriangle();
                cout << "\nDien tich cua tam giac la: " << ABC.acreageTriangle();
                break;
            case 4:
                cout << "\nSo tam giac da tao la: " << TAMGIAC::getSoTamGiac();
                break;
            case 5:
                break;
            case 6:
                ABC.rotateTriangle();
                ABC.output();
                break;
            case 7:
                ABC.zoomTriangle();
                ABC.output();
                break;
            default:
                break;
            }

        } while (choosen != 5);
    } while (choosen != 0);
    return 0;
}


