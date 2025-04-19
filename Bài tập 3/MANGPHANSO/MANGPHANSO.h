#pragma once
#include "PHANSO.h"
#include <vector>
using namespace std;
class MANGPHANSO
{
private:
	vector<PHANSO> mps;
	int partition(int low, int high);
	int partitionDecrease(int low, int high);
	void quickSort(int low, int high);
	void quickSortDecrease(int low, int high);
public:
	void NhapMPS();
	void XuatMPS();
	PHANSO TongMPS();
	PHANSO maxPS();
	PHANSO minPS();
	PHANSO maxTuIsPrimeNum();
	void quickSort();
	void quickSortDecrease();
};