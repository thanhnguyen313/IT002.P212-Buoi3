#include <iostream>
#include <vector>
#include "cArray.h"
using namespace std;

int main()
{
	cArray arr;
	// Tao mang so nguyen ngau nhien voi n phan tu
	cout << "\nTao mang so nguyen ngau nhien: "; 
	srand(static_cast<unsigned int>(time(0)));
	arr.createRandomArray();
	int n = arr.getArraySize();
	if (n == 0)
	{
		cout << "\nMang rong !";
		return 0;
	}
	cout << "\nMang vua tao: "; arr.output();
	// Dem so lan x xuat hien trong mang 
	int x; cout << "\nNhap x: "; cin >> x;
	cout << "\nSo lan xuat hien cua " <<  x << " trong mang la : " << arr.countX(x);
	// Kiem tra cac phan tu trong mang co tang dan hay khong
	if (arr.increasingArray())
		cout << "\nMang nay tang dan ";
	else
		cout << "\nMang nay khong tang dan ";
	// Tim phan le nho nhat trong mang
	cout << "\nPhan le nho nhat trong mang la: " << arr.minOddElement();
	// Tim so nguyen to lon nhat trong mang
	if (arr.maxPrimeElement() == -1)
		cout << "\nMang khong co so nguyen to ";
	else
		cout << "\nSo nguyen to lon nhat trong mang la: " << arr.maxPrimeElement();
	// Sap xep mang
	cout << "\n\nMang goc: "; arr.output();
	// bubbleSort();
	cout << "\n\nSap xep bang bubbleSort: ";
	cArray bubbleSortArray; arr.copy(bubbleSortArray);
	bubbleSortArray.bubbleSort(); bubbleSortArray.output();
	// selectionSort();
	cout << "\n\nSap xep bang selectionSort: ";
	cArray selectionSortArray; arr.copy(selectionSortArray);
	selectionSortArray.selectionSort(); selectionSortArray.output();
	// insertionSort();
	cout << "\n\nSap xep bang insertionSort: ";
	cArray insertionSortArray; arr.copy(insertionSortArray);
	insertionSortArray.insertionSort(); insertionSortArray.output();
	// mergeSort();
	cout << "\n\nSap xep bang mergeSort: ";
	cArray mergeSortArray; arr.copy(mergeSortArray);
	mergeSortArray.mergeSort(); mergeSortArray.output();
	// void quickSort();
	cout << "\n\nSap xep bang quickSort: ";
	cArray quickSortArray; arr.copy(quickSortArray);
	quickSortArray.quickSort(); quickSortArray.output();
	return 0;
}
