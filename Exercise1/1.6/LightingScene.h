#ifndef LightingScene_H
#define LightingScene_H

#include "CGFscene.h"
#include "CGFappearance.h"
#include "myTable.h"
#include "Plane.h"
#include "myCylinder.h"
#include "myLamp.h"
#include "myUnitCube.h"
#include "MyClock.h"
#include "MyClockHand.h"

class LightingScene : public CGFscene
{
public:
	void init();
	void display();
	void virtual update(unsigned long t);
	long t;
	CGFlight* light0;
	CGFlight* light1;
	CGFlight* light2;
	CGFlight* light3;

	
	myTable* table;
	Plane* wall;
	Plane* wallWindow;
	Plane* boardA;
	Plane* boardB;
	Plane* floor;
	CGFappearance* materialA;
	CGFappearance* materialB;

	CGFappearance* slidesAppearance;
	CGFappearance* boardAppearance;
	CGFappearance* windowAppearance;
	CGFappearance* floorAppearance;
	
	myCylinder* m;
	myCylinder* m2;
	myLamp* l;
	MyClock* clock1;

	~LightingScene();
};

#endif