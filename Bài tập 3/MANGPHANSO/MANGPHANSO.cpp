#include "MANGPHANSO.h"
#include "PHANSO.h"
#include <iostream>

using namespace std;

int main()
{
	MANGPHANSO mps;
	int choosen;
	mps.NhapMPS();
	do
	{
		cout << "\n=======================================================";
		cout << "\n----------CHUONG TRINH TINH TOAN MANG PHAN SO----------";
		cout << "\n0. Thoat chuong trinh. ";
		cout << "\n1. Xuat mang phan so. ";
		cout << "\n2. Tinh tong cac phan so. ";
		cout << "\n3. Tim phan so lon nhat va phan so nho nhat. ";
		cout << "\n4. Tim phan so co tu so la so nguyen to lon nhat. ";
		cout << "\n5. Sap xep danh sach phan so. ";
		do
		{
			cout << "\nBan chon: "; cin >> choosen;
			if (choosen > 6 || choosen < 0)
				cout << "\nVui long nhap lua chon hop le! ";
		} while (choosen > 6 || choosen < 0);
		switch (choosen)
		{
		case 0:
			cout << "\nChuong trinh dang thoat... ";
			return 0;
		case 1:
			mps.XuatMPS();
			break;
		case 2: 
			cout << "\nTong cac phan so la: " << mps.TongMPS();
			break;
		case 3:
			cout << "\nPhan so lon nhat la: " << mps.maxPS();
			cout << "\nPhan so nho nhat la: " << mps.minPS();
			break;
		case 4:
			if (mps.maxTuIsPrimeNum() == PHANSO(0, 1))
				break;
			cout << "\nPhan so co tu so la so nguyen to lon nhat la: " << mps.maxTuIsPrimeNum();
			break;
		case 5:
			mps.quickSort();
			cout << "\nTang dan: ";
			mps.XuatMPS();
			mps.quickSortDecrease();
			cout << "\nGiam dan: ";
			mps.XuatMPS();
			break;
		default:
			break;
		}
	} while (choosen != 0);
	return 0;
}