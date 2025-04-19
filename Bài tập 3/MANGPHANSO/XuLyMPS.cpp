#include"MANGPHANSO.h"
#include<iostream>
using namespace std;

void MANGPHANSO::NhapMPS()	//Ham nhap mang phan so
{
	int n;
	do
	{
		cout << "\nNhap so luong phan tu cua MANG PHAN SO: "; cin >> n;
		if (n < 0)
			cout << "\nVui long nhap so phan tu mang hop le!";
		else if (n == 0)
			cout << "\nMang rong!";
	} while (n <= 0);
	mps.resize(n); //Khoi tao mps voi n phan tu
	for (int i = 0; i < n; i++)
	{
		mps[i].Nhap();
		mps[i].RutGon();
	}
}
void MANGPHANSO::XuatMPS()	//Ham xuat mang phan so ra man hinh
{
	cout << "\n=> Mang phan so: ";
	for (int i = 0; i < mps.size(); i++)
	{
		mps[i].Xuat(); cout << " ";
	}
}
PHANSO MANGPHANSO::TongMPS()
{
	PHANSO tongMPS;
	for (int i = 0; i < mps.size(); i++)
	{
		tongMPS = tongMPS + mps[i];
	}
	tongMPS.RutGon();
	return tongMPS;
}
PHANSO MANGPHANSO::maxPS()
{
	PHANSO maxPS = mps[0];
	for (int i = 0; i < mps.size(); i++)
	{
		if (mps[i] >= maxPS)
			maxPS = mps[i];
	}
	return maxPS;
}
PHANSO MANGPHANSO::minPS()
{
	PHANSO minPS = mps[0];
	for (int i = 0; i < mps.size(); i++)
	{
		if (mps[i] <= minPS)
			minPS = mps[i];
	}
	return minPS;
}
PHANSO MANGPHANSO::maxTuIsPrimeNum()
{
	PHANSO maxTuIsPrimeNum = mps[0];
	bool found = false;
	for (int i = 0; i < mps.size(); i++)
	{
		if (mps[i].getTu() >= maxTuIsPrimeNum.getTu() && isPrimeNum(mps[i].getTu()))
		{
			maxTuIsPrimeNum = mps[i];
			found = true;
		}
	}
	if (!found)
	{
		cout << "\nKhong co phan so nao co tu so la so nguyen to! ";
		return PHANSO(0, 1);
	}
	return maxTuIsPrimeNum;
}
int MANGPHANSO::partition(int low, int high)
{
	PHANSO pivot = mps[high];
	int i = low - 1;
	for (int j = low; j < high; j++)
	{
		if (mps[j] < pivot)
		{
			i++;
			swap(mps[i], mps[j]);
		}
	}
	swap(mps[i + 1], mps[high]);
	return i + 1;
}
void MANGPHANSO::quickSort(int low, int high)
{
	if (low < high)
	{
		int pivot = partition(low, high);

		quickSort(low, pivot - 1);
		quickSort(pivot + 1, high);
	}
}
void MANGPHANSO::quickSort()
{
	quickSort(0, mps.size() - 1);
}
int MANGPHANSO::partitionDecrease(int low, int high)
{
	PHANSO pivot = mps[high];
	int i = low - 1;
	for (int j = low; j < high; j++)
	{
		if (mps[j] > pivot)
		{
			i++;
			swap(mps[i], mps[j]);
		}
	}
	swap(mps[i + 1], mps[high]);
	return i + 1;
}
void MANGPHANSO::quickSortDecrease(int low, int high)
{
	if (low < high)
	{
		int pivot = partitionDecrease(low, high);

		quickSortDecrease(low, pivot - 1);
		quickSortDecrease(pivot + 1, high);
	}
}
void MANGPHANSO::quickSortDecrease()
{
	quickSortDecrease(0, mps.size() - 1);
}
	