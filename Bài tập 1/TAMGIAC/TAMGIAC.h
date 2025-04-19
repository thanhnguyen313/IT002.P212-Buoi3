#pragma once
#include "DIEM.h"
class TAMGIAC
{
private:
	DIEM A, B, C;
	static int soTamGiac;
public:
	// set/ get/ constructor 
	void setA(DIEM a);
	DIEM getA() const;
	void setB(DIEM b);
	DIEM getB() const;
	void setC(DIEM c);
	DIEM getC() const;
	TAMGIAC();
	TAMGIAC(DIEM a, DIEM b, DIEM c);
	// bien static 
	static int getSoTamGiac();

	void input();
	void output();
	bool checkTriangle();
	double lenV(DIEM x, DIEM y);
	void typeTriangle();
	void displacementTriangle();
	double perimeterTriangle();
	double acreageTriangle();
	void rotateTriangle();
	void zoomTriangle();
};

