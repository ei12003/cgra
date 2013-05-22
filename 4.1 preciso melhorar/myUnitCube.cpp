#include "myUnitCube.h"


void myUnitCube::draw() 
{
	glPushMatrix();
	glTranslatef(-0.5,0,0.5);
	glNormal3f(0,0,1);
	glBegin(GL_POLYGON);
	glTexCoord2d(1,1);
	glVertex3f(1,1,0);
	glTexCoord2d(0,1);
	glVertex3f(0,1,0);
	glTexCoord2d(0,0);
	glVertex3f(0,0,0);
	glTexCoord2d(1,0);
	glVertex3f(1,0,0);
	glEnd();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(0.5,0,-0.5);
	glRotated(180,0,1,0);
	glNormal3f(0,0,1);
		glBegin(GL_POLYGON);
	glTexCoord2d(1,1);
	glVertex3f(1,1,0);
	glTexCoord2d(0,1);
	glVertex3f(0,1,0);
	glTexCoord2d(0,0);
	glVertex3f(0,0,0);
	glTexCoord2d(1,0);
	glVertex3f(1,0,0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.5,0,-0.5);
	glRotated(90,1,0,0);
	glNormal3f(0,0,1);
		glBegin(GL_POLYGON);
	glTexCoord2d(1,1);
	glVertex3f(1,1,0);
	glTexCoord2d(0,1);
	glVertex3f(0,1,0);
	glTexCoord2d(0,0);
	glVertex3f(0,0,0);
	glTexCoord2d(1,0);
	glVertex3f(1,0,0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.5,1,0.5);
	glRotated(-90,1,0,0);
	glNormal3f(0,0,1);
		glBegin(GL_POLYGON);
	glTexCoord2d(1,1);
	glVertex3f(1,1,0);
	glTexCoord2d(0,1);
	glVertex3f(0,1,0);
	glTexCoord2d(0,0);
	glVertex3f(0,0,0);
	glTexCoord2d(1,0);
	glVertex3f(1,0,0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.5,0,0.5);
	glRotated(90,0,1,0);
	glNormal3f(0,0,1);
		glBegin(GL_POLYGON);
	glTexCoord2d(1,1);
	glVertex3f(1,1,0);
	glTexCoord2d(0,1);
	glVertex3f(0,1,0);
	glTexCoord2d(0,0);
	glVertex3f(0,0,0);
	glTexCoord2d(1,0);
	glVertex3f(1,0,0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.5,0,-0.5);
	glRotated(-90,0,1,0);
	glNormal3f(0,0,1);
		glBegin(GL_POLYGON);
	glTexCoord2d(1,1);
	glVertex3f(1,1,0);
	glTexCoord2d(0,1);
	glVertex3f(0,1,0);
	glTexCoord2d(0,0);
	glVertex3f(0,0,0);
	glTexCoord2d(1,0);
	glVertex3f(1,0,0);
	glEnd();
	glPopMatrix();



}