#include "MyClockHand.h"
#include "myUnitCube.h"

#include "math.h"

MyClockHand::MyClockHand(){
	this->angulo=0;
	float ambB[3] = {0.2, 0.2, 0.2};
	float difB[3] = {0.6, 0.6, 0.6};
	float specB[3] = {0.8, 0.8, 0.8};
	float shininessB = 120.f;

	matB = new CGFappearance(ambB,difB,specB,shininessB);

}
void MyClockHand::draw(int opt)
{
	
	myUnitCube pt;
	switch(opt){

	case HORAS:
	glPushMatrix();
	glRotated(angulo,1,0,0);
	glScaled(0.025,0.42,0.05);
	glTranslated(2.4,0,0);
	matB->apply();
	pt.draw();
	glPopMatrix();
	break;

	case MIN:
	glPushMatrix();
	glRotated(angulo,1,0,0);
	glScaled(0.025,0.6,0.05);
	glTranslated(2.2,0,0);
	matB->apply();
	pt.draw();
	glPopMatrix();
	break;

	case SEG:
	glPushMatrix();
	glRotated(angulo,1,0,0);
	glScaled(0.025,0.69,0.01);
	glTranslated(2.8,0,0);
	matB->apply();
	pt.draw();
	glPopMatrix();
	break;
	}




}
void MyClockHand::incAngle(float ang)
{
this->angulo+=ang;	
}
void MyClockHand::setAngle(float ang)
{
this->angulo=ang;	
}