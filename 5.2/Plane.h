#pragma once

#include "CGF\CGFobject.h"
class Plane
{
public:
	Plane(void);
	Plane(int, double,double,double, double, int type = 0);
	~Plane(void);
	void draw();
private:
	double _numDivisions; // Number of triangles that constitute rows/columns
		double si, sf, ti, tf;
	double coefs,coeft;
	int type;
};

