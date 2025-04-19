#include "ListCandidate.h"
#include "CANDIDATE.h"
#pragma once

void ListCandidate::listCandidateInput()
{
	int n;
	do
	{
		cout << "\nNhap so luong thi sinh: "; cin >> n;
		if (n < 0)
			cout << "\nVui long nhap so luong hop le !";
	} while (n < 0);
	list.resize(n);
	for (int i = 0; i < n; i++)
	{
		list[i].Input();
	}
}
void ListCandidate::listCandidateOutput()
{
	for (int i = 0; i < list.size(); i++)
	{
		cout << "\n====================";
		list[i].Output();
	}
}
void ListCandidate::listCandidateThatSumOver15()
{
	for (int i = 0; i < list.size(); i++)
	{
		if (list[i].getSum() > 15.00)
			list[i].Output();
	}
}
void ListCandidate::candidateThatHaveMaxScore()
{
	float maxScore = 0;
	for (int i = 0; i < list.size(); i++)
	{
		if (list[i].getSum() > maxScore)
			maxScore = list[i].getSum();
	}
	cout << "\nTong diem cao nhat: " << maxScore;
	cout << "\nThi sinh co tong diem cao nhat: ";
	for (int i = 0; i < list.size(); i++) 
	{
		if (list[i].getSum() == maxScore)
			cout << list[i].getName() << endl;
	}
}
void ListCandidate::swap(CANDIDATE& a, CANDIDATE& b)
{
	CANDIDATE temp;
	temp = b;
	b = a;
	a = temp;
}
int ListCandidate::partitionDecrease(int low, int high)
{
	CANDIDATE pivot = list[high];
	int i = low - 1;
	for (int j = low; j < high; j++)
	{
		if (list[j].getSum() > pivot.getSum())
		{
			i++;
			swap(list[i], list[j]);
		}
	}
	swap(list[i + 1], list[high]);
	return i + 1;
}
void ListCandidate::quickSortDecrease(int low, int high)
{
	if (low < high)
	{
		int pivot = partitionDecrease(low, high);

		quickSortDecrease(low, pivot - 1);
		quickSortDecrease(pivot + 1, high);
	}
}
void ListCandidate::quickSortDecrease()
{
	quickSortDecrease(0, list.size() - 1);
}
void ListCandidate::listCandidateDecrease()
{
	quickSortDecrease();
	cout << "\nDanh sach hoc sinh giam dan theo tong diem: ";
	for (int i = 0; i < list.size(); i++)
	{
		cout << endl << list[i].getName() << " " << list[i].getSum() << " Diem.";
	}
}