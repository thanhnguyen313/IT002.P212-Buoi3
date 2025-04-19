#pragma once
#include "CANDIDATE.h"
#include <vector>

class ListCandidate
{
private:
	vector<CANDIDATE> list;
public:
	void listCandidateInput();
	void listCandidateOutput();
	void listCandidateThatSumOver15();
	void candidateThatHaveMaxScore();
	int partitionDecrease(int low, int high);
	void quickSortDecrease(int low, int high);
	void quickSortDecrease();
	void listCandidateDecrease();
	void swap(CANDIDATE& a, CANDIDATE& b);
};


