#include "MyRobot.h"
#include "myCylinder.h"

#include "math.h"
#define GL_CLAMP_TO_EDGE 33071
#define rad =  0.0174532925 ;
MyRobot::MyRobot(int angle, float tx, float ty, float tz){
	this->angle=angle;
	this->tx=tx;
	this->ty=ty;
	this->tz=tz;

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

/*void MyRobot::updateAngle(int angle){
	
	
	this->angle+=angle;
	if(this->angle>=360)
		this->angle-=360;
	else if(this->angle<=-360)
		this->angle+=360;
}

int MyRobot::getAngle(){
	return angle;
}

void MyRobot::inctx(float var){
	this->tx+=var;

}
void MyRobot::inctz(float var){
	this->tz+=var;
}

float MyRobot::gettx(){
	return tx;

}
float MyRobot::gettz(){
	return tz;
}*/