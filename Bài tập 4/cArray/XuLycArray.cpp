#include <iostream>
#include <cstdlib> // cho rand() và srand()
#include <ctime>   // cho time()
#include "cArray.h"
using namespace std;

void cArray::createRandomArray(int minValue , int maxValue)	// Ham tao mang ngau nhien voi n phan tu la so nguyen
{
	int n; cout << "\nNhap so luong phan tu cua mang: "; cin >> n;
	if (n == 0) return;
	array.resize(n);
	for (size_t i = 0; i < array.size(); i++) 
	{
		int randomNumber = minValue + rand() % (maxValue - minValue + 1);
		array[i] = randomNumber;
	}
}
int cArray::getArraySize() { return array.size(); }
void cArray::output()
{
	for (size_t i = 0; i < array.size(); i++)
	{
		cout << array[i] << " ";
	}
}
int cArray::countX(int x)
{
	int count = 0;
	for (size_t i = 0; i < array.size(); i++)
	{
		if (array[i] == x)
			count++;
	}
	return count;
}
bool cArray::increasingArray()
{
	for (size_t i = 1; i < array.size(); i++)
	{
		if (array[i] < array[i - 1])
			return false;
	}
	return true;
}
int cArray::minOddElement()
{
	int minOdd = -1; //Neu mang ko co so le
	for (size_t i = 0; i < array.size(); i++)
	{
		if (array[i] % 2 != 0) // tim so le
			if (minOdd == -1 || array[i] < minOdd) // so le dau tien trong  (khi do minOdd bang -1 thi gan minOdd = so le dau tien do)
				minOdd = array[i];
	}
	return minOdd;
}
int cArray::maxPrimeElement()
{
	int maxPrimeNum = -1; 
	for (size_t i = 0; i < array.size(); i++)
	{
		if (isPrimeNum(array[i]))
			if (maxPrimeNum == -1 || array[i] > maxPrimeNum)
				maxPrimeNum = array[i];	
	}
	return maxPrimeNum;
}
void cArray::copy(cArray &otherArray)
{
	otherArray.array.resize(array.size());
	for (size_t i = 0; i < otherArray.array.size(); i++)
	{
		otherArray.array[i] = array[i];
	}
}
void cArray::bubbleSort()
{
	for (size_t i = 0; i < array.size() - 1; i++)
	{
		bool finish = false;
		for (size_t j = 0; j < array.size() - 1 - i; j++)
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
	for (size_t i = 0; i < array.size(); i++)
	{
		size_t min_index = i;
		for (size_t j = i; j < array.size(); j++)
		{
			if (array[j] < array[min_index])
				min_index = j;
		}
		swap(array[i], array[min_index]);
	}
}
void cArray::insertionSort()
{
	for (size_t i = 1; i < array.size(); i++)
	{
		int temp = array[i];
		int j = static_cast<int>(i) - 1;;
		while (j >= 0 && array[j] > temp)
		{
			array[j + 1] = array[j];
			j--;
		}
		array[j + 1] = temp;
	}
}
void cArray::merge(size_t left, size_t mid, size_t right)
{
	size_t nL = mid - left + 1;
	size_t nR = right - mid;
	vector <int> L(nL), R(nR);
	for (size_t i = 0; i < nL; i++)
	{
		L[i] = array[left + i];
	}
	for (size_t i = 0; i < nR; i++)
	{
		R[i] = array[mid + 1 + i];
	}
	size_t i = 0, j = 0, k = left;
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
void cArray::mergeSort(size_t left, size_t right)
{
	if (left < right)
	{
		size_t mid = (left + right) / 2;
		mergeSort(left, mid);
		mergeSort(mid + 1, right);
		merge(left, mid, right);
	}
}
void cArray::mergeSort()
{
	mergeSort(0, array.size() - 1);
}
int cArray::partition(int low, int high)
{
	int pivot = array[high];
	int i = low - 1;
	for (int j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap(array[i], array[j]);
		}
	}
	swap(array[i + 1], array[high]);
	return i + 1;
}

void cArray::quickSort(int low, int high)
{
	if (low < high)
	{
		int pivot = partition(low, high);

		quickSort(low, pivot - 1);
		quickSort(pivot + 1, high);
	}
}

void cArray::quickSort()
{
	quickSort(0, array.size() - 1);
}
bool isPrimeNum(int x)
{
	if (x == 2) return true;
	if (x % 2 == 0) return false;
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