#include <iostream>
#include <cstdlib> // cho rand() và srand()
#include <ctime>   // cho time()
#include "cArray.h"
using namespace std;

void cArray::createRandomArray(int minValue = 0, int maxValue = 100)	// Ham tao mang ngau nhien voi n phan tu la so nguyen
{
	srand(static_cast<unsigned int>(time(0))); // Khoi tao seed cho rand()
	int n; cout << "\nNhap so luong phan tu cua mang: "; cin >> n;
	if (n == 0) return;
	array.resize(n);
	for (int i = 0; i < array.size(); ++i) 
	{
		int randomNumber = minValue + rand() % (maxValue - minValue + 1);
		array.push_back(randomNumber);
	}
}
void cArray::output()
{
	cout << "\nMang array: ";
	for (int i = 0; i < array.size(); i++)
	{
		cout << array[i];
	}
}
int cArray::countX(int x)
{
	int count = 0;
	for (int i = 0; i < array.size(); i++)
	{
		if (array[i] == x)
			count++;
	}
	return count;
}
bool cArray::increasingArray()
{
	for (int i = 1; i < array.size(); i++)
	{
		if (array[i] < array[i - 1])
			return false;
	}
	return true;
}
int cArray::minOddElement()
{
	int minOdd = -1; //Neu mang ko co so le
	for (int i = 0; i < array.size(); i++)
	{
		if (array[i] % 2 == 0) // tim so le
			if (minOdd == -1 || array[i] < minOdd) // so le dau tien trong  (khi do minOdd bang -1 thi gan minOdd = so le dau tien do)
				minOdd = array[i];
	}
	return minOdd;
}
int cArray::maxPrimeElement()
{
	int maxPrimeNum = -1; 
	for (int i = 0; i < array.size(); i++)
	{
		if (isPrimeNum(array[i]))
			if (maxPrimeNum == -1 || array[i] > maxPrimeNum)
				maxPrimeNum = array[i];	
	}
	return maxPrimeNum;
}
void cArray::bubbleSort()
{
	for (int i = 0; i < array.size() - 1; i++)
	{
		bool finish = false;
		for (int j = 0; j < array.size() - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(array[j], array[j + 1]);
				finish = true;
			}
		}
		if (!finish)
			break;
	}
}
void cArray::selectionSort()
{
	for (int i = 0; i < array.size(); i++)
	{
		int min_index = i;
		for (int j = i; j < array.size(); j++)
		{
			if (array[j] < array[min_index])
				min_index = j;
		}
		swap(array[i], array[min_index]);
	}
}
void cArray::insertionSort()
{
	for (int i = 1; i < array.size(); i++)
	{
		int temp = array[i];
		int j = i - 1;
		while (j >= 0 && array[j] > temp)
		{
			array[j + 1] = array[j];
			j--;
		}
		array[j + 1] = temp;
	}
}
void cArray::merge(int left, int mid, int right)
{
	int nL = mid - left + 1;
	int nR = right - mid;
	vector <int> L(nL), R(nR);
	for (int i = 0; i < nL; i++)
	{
		L[i] = array[left + i];
	}
	for (int i = 0; i < nR; i++)
	{
		R[i] = array[mid + 1 + i];
	}
	int i = 0, j = 0, k = left;
	while (i < nL && j < nR)
	{
		if (L[i] <= R[j])
			array[k++] = L[i++];
		else
			array[k++] = R[j++];
	}
	while (i < nL) array[k++] = L[i++];
	while (j < nR) array[k++] = R[j++];
}
void cArray::mergeSort(int left, int right)
{
	if (left < right)
	{
		int mid = (left + right) / 2;
		mergeSort(left, mid);
		mergeSort(mid + 1, right);
		merge(left, mid, right);
	}
}
void cArray::mergeSort()
{
	mergeSort(0, array.size() - 1);
}
void cArray::quickSort()
{

}
void cArray::heapSort()
{

}
bool isPrimeNum(int x)
{
	if (x == 2) return true;
	if (x < 2) return false;
	for (int i = 3; i * i <= x; i += 2)
	{
		if (x % i == 0)
			return false;
	}
	return true;
}
void swap(int& a, int& b)
{
	int temp = b;
	b = a;
	a = temp;
}