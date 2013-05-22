#include "myLamp.h"
#include <math.h>

myLamp::myLamp(int slices, int stacks, bool smooth) {
	
	this->slices = slices;
	this->stacks = stacks;
	this->smooth = smooth;
}


void myLamp::draw()
{

	long float pi = acos(-1.0);
	long float angulo = 360.0/ slices;
	float ki,kf;


		//Base
	glPushMatrix();
	glTranslatef(0,0,-0.5);
	glRotated(180,1,0,0);
	glBegin(GL_POLYGON);
	for(int i = 0; i < slices; ++i) {
		glNormal3f(0,0,1);
	 glVertex3f(cos(angulo*(i)*pi/180),sin(angulo*(i)*pi/180),0);

		}
glEnd();
glPopMatrix();

/*asdasdasd*/
	glPushMatrix();
		glTranslatef(0,0,-0.5);
	glBegin(GL_QUADS);
	for(int i = 0; i < slices; i++) {
		ki=0.0;
		kf=(1.0/(float)slices)/(float)stacks;
		for(int j=0; j < stacks; j++){
			if(!smooth)
			glNormal3f((cos(angulo*(i)*pi/180)+cos(angulo*(i+1)*pi/180))/2.0,(sin(angulo*(i)*pi/180)+sin(angulo*(i+1)*pi/180))/2.0,0);

			if(smooth)
				glNormal3f(cos(angulo*(i)*pi/180),sin(angulo*(i)*pi/180),0);
				glVertex3f(cos(angulo*(i)*pi/180),(sin(angulo*(i)*pi/180)),ki);
			if(smooth)
				glNormal3f(cos(angulo*(i+1)*pi/180),sin(angulo*(i+1)*pi/180),0);
				glVertex3f(cos(angulo*(i+1)*pi/180),sin(angulo*(i+1)*pi/180),ki);
			if(smooth)
				glNormal3f(cos(angulo*(i+1)*pi/180),sin(angulo*(i+1)*pi/180),0);
				glVertex3f(cos(angulo*(i+1)*pi/180),sin(angulo*(i+1)*pi/180),kf);
			if(smooth)
				glNormal3f(cos(angulo*(i)*pi/180),sin(angulo*(i)*pi/180),0);
				glVertex3f(cos(angulo*(i)*pi/180),sin(angulo*(i)*pi/180),kf);
ki=kf;
kf+=(1.0/(float)slices)/(float)stacks;

		}
		}
	glEnd();
	glPopMatrix();
}