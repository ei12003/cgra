#include "MyRobot.h"
#include "myCylinder.h"

#include "math.h"
#define GL_CLAMP_TO_EDGE 33071
/*
xf=xi+i*(xf-xi)/N
*/

MyRobot::MyRobot(int angle, float tx, float ty, float tz,float stacks){
	long float pi = acos(-1.0);
	float slices=12;
	long float angulo = 360.0/ slices;
	const double coef=(360.0/12.0 ) * (3.141592653589793)/ 180.0;
	double raio=0.25;
	double a;
	const int test=stacks+1;

	this->angle=angle;
	this->tx=tx;
	this->ty=ty;
	this->tz=tz;
	this->rad=0.0174532925;
	this->stacks=stacks;

	square[0].x=0.5;
	square[0].y=0;
	square[0].z=(2.0/3)-0.5;

	square[1].x=0.5;
	square[1].y=0;
	square[1].z=0.5;

	square[2].x=(2.0/3)-0.5;
	square[2].y=0;
	square[2].z=0.5;

	square[3].x=(1.0/3)-0.5;
	square[3].y=0;
	square[3].z=0.5;

	square[4].x=-0.5;
	square[4].y=0;
	square[4].z=0.5;

	square[5].x=-0.5;
	square[5].y=0;
	square[5].z=(1.0/3)-0.5;

	square[6].x=-0.5;
	square[6].y=0;
	square[6].z=(2.0/3)-0.5;

	square[7].x=-0.5;
	square[7].y=0;
	square[7].z=-0.5;

	square[8].x=(1.0/3)-0.5;
	square[8].y=0;
	square[8].z=-0.5;

	square[9].x=(2.0/3)-0.5;
	square[9].y=0;
	square[9].z=-0.5;

	square[10].x=0.5;
	square[10].y=0;
	square[10].z=-0.5;

	square[11].x=0.5;
	square[11].y=0;
	square[11].z=(1.0/3)-0.5;

	for(int i=12;i>=0;i--){
		a  = i*coef + (360.0/12.0/2.0)*(3.141592653589793)/ 180.0; 
		circle[i].x=raio*cos(a);
		circle[i].z=raio*sin(a);
	}

	aresta = new ponto*[13];	

	for(int i=0;i<=	12;i++){
		aresta[i] = new ponto[(int)stacks+1];

		for(int j=0;j<=stacks;j++){		

			aresta[i][j].x = square[i%12].x+j*(circle[i%12].x-square[i%12].x)/stacks;
			aresta[i][j].y = j*(1/stacks);
			aresta[i][j].z = square[i%12].z+j*(circle[i%12].z-square[i%12].z)/stacks;
		}

	}
}

void MyRobot::draw()
{

	glTranslated(tx,ty,tz);
	glRotated(angle,0,1,0);

	/* Quadrado */
	glBegin(GL_QUADS);
	glNormal3f(0,1,0);
	glVertex3f(0.5f,0.0f,-0.5f);
	glVertex3f(0.5f,0.0f,0.5f);
	glVertex3f(-0.5f,0.0f,0.5f);
	glVertex3f(-0.5f,0.0f,-0.5f);
	glEnd();


	/* Circulo */
	glBegin(GL_POLYGON);
	for(int i = 12; i >= 0; i-- ){
		glNormal3f(0,1,0);
		glVertex3f( circle[i].x,  1, circle[i].z);
	}
	glEnd();

	/* Corpo */
	glBegin(GL_TRIANGLE_STRIP);
	for(int i = 1; i <= 12; i++ ) { 
		for(int h=stacks ; h>=0; h-=1) {
			//glTexCoord2f(texMap[i-1][h].x,texMap[i-1][h].z);
			glVertex3f( aresta[i-1][h].x,aresta[i-1][h].y,aresta[i-1][h].z);
			//glTexCoord2f(texMap[i][h].x,texMap[i][h].z);
			glVertex3f( aresta[i][h].x,aresta[i][h].y,aresta[i][h].z);
		}
	}
	glEnd();
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