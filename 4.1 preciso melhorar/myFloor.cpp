#include "myFloor.h"
#include "myUnitCube.h"

void myFloor::draw() 
{
	myUnitCube c1;

	//tampo
	glPushMatrix();
	glScaled(8,0.1,6);
	c1.draw();
	glPopMatrix();





}