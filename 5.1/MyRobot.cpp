#include "MyRobot.h"
#include "myCylinder.h"

#include "math.h"
#define GL_CLAMP_TO_EDGE 33071
/*
xf=xi+i*(xf-xi)/N
*/

MyRobot::MyRobot(int angle, float tx, float ty, float tz,int stacks){
	pi = 3.141592653589793;
	this->slices=12;
	coef=(360.0/(double)slices ) * (pi)/ 180.0;
	raio=0.25;




	this->angle=angle;
	this->tx=tx;
	this->ty=ty;
	this->tz=tz;
	this->rad=0.0174532925;
	this->stacks=stacks;
	this->texture=1;

	square[0].x = 0.5 - 1.0/3.0;
	square[0].y = 0;
	square[0].z = 0.5;

	square[1].x = 0.5;
	square[1].y = 0;
	square[1].z = 0.5;

	square[2].x = 0.5;
	square[2].y = 0;
	square[2].z = (0.5-1.0/3.0);

	square[3].x = 0.5;
	square[3].y = 0;
	square[3].z = -0.5+1.0/3.0;

	square[4].x = 0.5;
	square[4].y = 0;
	square[4].z = -0.5;

	square[5].x = 0.5-1.0/3.0;
	square[5].y = 0;
	square[5].z = -0.5;

	square[6].x = -0.5+1.0/3.0;
	square[6].y = 0;
	square[6].z = -0.5;

	square[7].x = -0.5;
	square[7].y = 0;
	square[7].z = -0.5;

	square[8].x = -0.5;
	square[8].y = 0;
	square[8].z = -0.5 +1.0/3.0;

	square[9].x = -0.5;
	square[9].y = 0;
	square[9].z = 0.5-1.0/3.0;

	square[10].x = -0.5;
	square[10].y = 0;
	square[10].z = 0.5;

	square[11].x = -0.5+1.0/3.0;
	square[11].y = 0;
	square[11].z = 0.5;

	
	square_map[0].x = 2.0/3.0;
	square_map[0].y = 0;
	square_map[0].z = 0.0;



	square_map[1].x = 1.0/3.0;
	square_map[1].y = 0;
	square_map[1].z = 0;



	square_map[2].x = 0;
	square_map[2].y = 0;
	square_map[2].z = 0;



	square_map[3].x = 0;
	square_map[3].y = 0;
	square_map[3].z = 1.0/3.0;


	square_map[4].x = 0.0;
	square_map[4].y = 0;
	square_map[4].z = 2.0/3.0;


	square_map[5].x = 0;
	square_map[5].y = 0;
	square_map[5].z = 1.0;


	square_map[6].x = 1.0/3.0;
	square_map[6].y = 0;
	square_map[6].z = 1.0;

	square_map[7].x = 2.0/3.0;
	square_map[7].y = 0;
	square_map[7].z = 1.0;


	square_map[8].x = 1.0;
	square_map[8].y = 0;
	square_map[8].z = 1.0;


	square_map[9].x = 1.0;
	square_map[9].y = 0;
	square_map[9].z = (2.0/3.0);


	square_map[10].x = 1.0;
	square_map[10].y = 0;
	square_map[10].z = 1.0/3.0;

	square_map[11].x = 1.0;
	square_map[11].y = 0;
	square_map[11].z = 0;

	aresta = new ponto*[13];
	aresta_map = new ponto*[13];

	for(int i=0;i<=	slices;i++){

		a = (double)(i)*coef + (360.0/(double)slices/2.0)*(pi)/ 180.0; // degrees to radians
		aresta[i] = new ponto[stacks+1];
		aresta_map[12-i] = new ponto[stacks+1];

		for(int j=0;j<=stacks;j++){		
			aresta_map[12-i][j].x= ((square_map[i%12].x - 0.5)/(double)(stacks))*(double)(j) + 0.5;
			aresta_map[12-i][j].z= ((square_map[i%12].z - 0.5)/(double)(stacks))*(double)(j) + 0.5;

			aresta[i][j].x = raio*sin(a)+(double)j*(square[i%12].x-raio*sin(a))/(double)stacks;
			aresta[i][j].y = 1+(double)(j)*((square[i%12].y - 1)/(double)(stacks));
			aresta[i][j].z = raio*cos(a)+(double)j*(square[i%12].z-raio*cos(a))/(double)stacks;
		}

	}

			// Coefficients for material RBT
	float ambRBT[3] = {0.2, 0.2, 0.2};
	float difRBT[3] = {0.9, 0.9, 0.9};
	float specRBT[3] = {0.2, 0.2, 0.2};
	float shininessRBT = 10.f;

	robotAppearance1 = new CGFappearance(ambRBT,difRBT,specRBT,shininessRBT);
	robotAppearance1->setTexture("robot1.jpg");
	robotAppearance1->setTextureWrap(GL_REPEAT, GL_REPEAT);

	robotAppearance2 = new CGFappearance(ambRBT,difRBT,specRBT,shininessRBT);
	robotAppearance2->setTexture("robot2.jpg");
	robotAppearance2->setTextureWrap(GL_REPEAT, GL_REPEAT);

}

void MyRobot::draw()
{   


	vector<ponto> v(3);

	glTranslated(tx,ty+1.5,tz);
	glRotated(angle,0,1,0);
	if(texture==1)
		robotAppearance1->apply();
	else if(texture==2)
		robotAppearance2->apply();

	/* Quadrado */
	glBegin(GL_QUADS);
	glNormal3f(0,-1,0);
	glVertex3f(0.5f,0.0f,-0.5f);
	glVertex3f(0.5f,0.0f,0.5f);
	glVertex3f(-0.5f,0.0f,0.5f);
	glVertex3f(-0.5f,0.0f,-0.5f);
	glEnd();


	/* Circulo */
	glBegin(GL_POLYGON);
	glNormal3f(0,1,0);
	for(int i = 12; i >= 0; i-- ){
		
		a  = i*coef + (360.0/(double)slices/2.0)*(pi)/ 180.0; 		
		glTexCoord2f(0.5,0.5);
		glVertex3f( raio*cos(a),  1, raio*sin(a));
	}
	glEnd();

	/* Corpo */
	
	glBegin(GL_TRIANGLE_STRIP);
	for(int i = 1; i <= 12; i++ ) {
		v[0]=(aresta[i][0]);
		v[1]=(aresta[i-1][0]);
		v[2]=(aresta[i-1][stacks]);

		normal = getNormal(v);
		glNormal3f(normal.x,normal.y,normal.z);
		for(int j=stacks ; j>=0; j-=1) {
			glTexCoord2f(aresta_map[i-1][j].x,aresta_map[i-1][j].z);
			glVertex3f( aresta[i-1][j].x,aresta[i-1][j].y,aresta[i-1][j].z);
			glTexCoord2f(aresta_map[i][j].x,aresta_map[i][j].z);
			glVertex3f( aresta[i][j].x,aresta[i][j].y,aresta[i][j].z);
		}
	}
	glEnd();

}



ponto MyRobot::getNormal(vector<ponto> p){
	ponto vec1,vec2;
	ponto crossp;
	ponto normal;
	float sq,aux;

	vec1.x = p.at(1).x - p.at(0).x;
	vec1.y = p.at(1).y - p.at(0).y;
	vec1.z = p.at(1).z - p.at(0).z;

	vec2.x = p.at(2).x - p.at(0).x;
	vec2.y = p.at(2).y - p.at(0).y;
	vec2.z = p.at(2).z - p.at(0).z;

	crossp.x = (vec1.y * vec2.z) - (vec1.z * vec2.y);
	crossp.y = (vec2.z * vec1.x) - (vec2.x * vec1.z);
	crossp.z = (vec1.x * vec2.y) - (vec1.y * vec2.x);

	sq=(crossp.x * crossp.x) + (crossp.y * crossp.y) + (crossp.z * crossp.z);
	aux=sqrt(sq);

	normal.x=crossp.x/aux;
	normal.y=crossp.y/aux;
	normal.z=crossp.z/aux;

	return normal;
}

void MyRobot::changeTexture(int id){
		texture=id;
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