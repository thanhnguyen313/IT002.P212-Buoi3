#pragma once
#include <iostream>
#include <vector>
using namespace std;
class cArray
{
private:
	vector <int> array;
public:
	int getArraySize();
	void createRandomArray(int minValue = 0, int maxValue = 100);
	void output();
	int countX(int x);
	bool increasingArray();
	int minOddElement();
	int maxPrimeElement();
	void copy(cArray &otherArray);
	void bubbleSort();
	void selectionSort();
	void insertionSort();
	void merge(size_t left, size_t mid, size_t right);
	void mergeSort(size_t left, size_t right);
	void mergeSort();
	int partition(int low, int high);
	void quickSort(int low, int high);
	void quickSort();
};
bool isPrimeNum(int x);
void swap(int& a, int& b);
