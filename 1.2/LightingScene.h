#ifndef LightingScene_H
#define LightingScene_H

#include "TPinterface.h"
#include "CGFscene.h"
#include "CGFappearance.h"
#include "myTable.h"
#include "Plane.h"
#include "myCylinder.h"
#include "myLamp.h"
#include "myUnitCube.h"
#include "MyClock.h"
#include "MyClockHand.h"
#include "MyPaperPlane.h"
#include "MyRobot.h"

class LightingScene : public CGFscene
{
public:
	void init();
	void display();
	void virtual update(unsigned long t);
	//void toggleSomething(int angle, int rx, int ry, int rz, int sentido);
	int sceneVar;
	long t;
	CGFlight* light0;
	CGFlight* light1;
	CGFlight* light2;
	CGFlight* light3;

	
	MyRobot* robot;
	MyPaperPlane* aviao;
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