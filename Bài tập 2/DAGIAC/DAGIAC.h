#pragma once
#include <vector> 
#include "DIEM.h"
class DAGIAC
{
private:
	int n;
	vector <DIEM> pointOfPolygon;
	vector <double> edgeOfPolygon;
	static int soDaGiac;
public:
	// bien static 
	static int getSoDaGiac();
	void input();
	void output();
	DIEM vectorOfPoint(DIEM x, DIEM y);
	bool checkPolygon();
	double lenV(DIEM x, DIEM y);
	void typePolygon();
	void displacementPolygon();
	double perimeterPolygon();
	double areaPolygon();
	void rotatePolygon();
	void zoomPolygon();
};

