#pragma once
#include <iostream>
#include <vector>
using namespace std;
class cArray
{
private:
	vector <int> array;
public:
	void createRandomArray(int minValue = 0, int maxValue = 100);
	void output();
	int countX(int x);
	bool increasingArray();
	int minOddElement();
	int maxPrimeElement();
	void bubbleSort();
	void selectionSort();
	void insertionSort();
	void merge(int left, int mid, int right);
	void mergeSort(int left, int right);
	void mergeSort();
	void quickSort();
	void heapSort();
};
bool isPrimeNum(int x);
void swap(int& a, int& b);
