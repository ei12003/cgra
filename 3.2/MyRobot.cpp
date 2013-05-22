#include "MyRobot.h"
#include "myCylinder.h"

#include "math.h"
#define GL_CLAMP_TO_EDGE 33071

MyRobot::MyRobot(int angle, float tx, float ty, float tz){
	this->angle=angle;
	this->tx=tx;
	this->ty=ty;
	this->tz=tz;
	this->rad=0.0174532925;
}

void MyRobot::draw()
{
	
	glPushMatrix();
	glTranslated(tx,ty,tz);
	glRotated(angle,0,1,0);

		glNormal3d(0,1,0);
		glBegin(GL_TRIANGLES); 
		
		glVertex3f( 0.5f, 0.3f, 0.0f ); //vertex 1
		
		glVertex3f( -0.5f, 0.3f, 0.0f ); //vertex 1
		
		glVertex3f( 0.0f, 0.3f, 2.0f ); //vertex 2
		
		glEnd();

	glPopMatrix();


}



int MyRobot::getAngle(){
	return angle;
}

void MyRobot::moveForward(){
	float co, ca;
	//Multiplica-se com rad para passarmos a radianos
	co=sin((double)angle*rad);
	ca=cos(rad*(double)angle);
	tx+=co;
	tz+=ca;


}

void MyRobot::moveBackward(){

	float co, ca;
	//Multiplica-se com rad para passarmos a radianos
	co=sin((double)angle*rad);
	ca=cos(rad*(double)angle);
	tx-=co;
	tz-=ca;

}

void MyRobot::rotateRight(){
	this->angle-=10;
	if(this->angle>=360)
		this->angle-=360;
	else if(this->angle<=-360)
		this->angle+=360;

}

void MyRobot::rotateLeft(){
		this->angle+=10;
	if(this->angle>=360)
		this->angle-=360;
	else if(this->angle<=-360)
		this->angle+=360;
}



float MyRobot::gettx(){
	return tx;

}
float MyRobot::gettz(){
	return tz;
}