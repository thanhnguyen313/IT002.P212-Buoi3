#pragma once
#include <iostream>
#include <string>
#include "DATE.h"
using namespace std;
class CANDIDATE
{
private:
	string name;
	int code;
	DATE dateOfBirth;
	float mathScore;
	float literatureScore;
	float englishScore;
	float sum;
public:
	void Input();
	void Output();
	bool isValidName(const string& name);
	void standardizeNames(string& str);
	CANDIDATE& operator=(const CANDIDATE& otherCandidate);
	string getName();
	float getSum();
};

