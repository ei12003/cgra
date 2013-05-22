#include "myTable.h"
#include "myUnitCube.h"

void myTable::draw() 
{
	// Coefficients for tableAppearance
	float ambTA[3] = {0.4, 0.4, 0.4};
	float difTA[3] = {0.8, 0.8, 0.8};
	float specTA[3] = {0.2, 0.2, 0.2};
	float shininessTA = 10.f;
	tableAppearance = new CGFappearance(ambTA,difTA,specTA,shininessTA);
	tableAppearance->setTexture("table.png");

	// Coefficients for material B
	float ambB[3] = {0.2, 0.2, 0.2};
	float difB[3] = {0.6, 0.6, 0.6};
	float specB[3] = {0.8, 0.8, 0.8};
	float shininessB = 120.f;

	matB = new CGFappearance(ambB,difB,specB,shininessB);



	myUnitCube c1;

	
	//perna1
	glPushMatrix();
	glTranslated(2.3,0,1.3);
	glScaled(0.3,3.5,0.3);
	matB->apply();
	c1.draw();
	glPopMatrix();

		//perna2
	glPushMatrix();
	glTranslated(2.3,0,-1.3);
	glScaled(0.3,3.5,0.3);
	c1.draw();
	glPopMatrix();

		//perna3
	glPushMatrix();
	glTranslated(-2.3,0,1.3);
	glScaled(0.3,3.5,0.3);
	c1.draw();
	glPopMatrix();

		//perna4
	glPushMatrix();
	glTranslated(-2.3,0,-1.3);
	glScaled(0.3,3.5,0.3);
	c1.draw();
	glPopMatrix();

	
		//tampo
	glPushMatrix();
	glTranslated(0,3.5,0);
	glScaled(5,0.3,3);
	tableAppearance->apply();
	c1.draw();
	glPopMatrix();



}