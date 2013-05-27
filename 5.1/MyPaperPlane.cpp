#include "MyPaperPlane.h"
#include "myCylinder.h"

#include "math.h"
#define GL_CLAMP_TO_EDGE 33071

MyPaperPlane::MyPaperPlane(int anglex,int tx, int ty, int tz){
	this->anglex=anglex;
	this->tx=tx;
	this->ty=ty;
	this->tz=tz;
}


void MyPaperPlane::changePlanePosition(int anglex,int tx, int ty, int tz){
	this->anglex+=anglex;
	this->tx+=tx;
	this->ty+=ty;
	this->tz+=tz;
}


void MyPaperPlane::draw()
{

 //glScaled(0.10,1,1);
	glPushMatrix();
		
	glTranslated(tx,ty,tz);
	
		glRotated(-90,0,1,0);
		glRotated(anglex,1,0,0);

	//ambas as assas, dentro e fora
		glNormal3d(0,0,1);
		glBegin(GL_TRIANGLE_STRIP); 
		
		glVertex3f( 0.0f, 0.0f, 0.0f ); //vertex 1
		
		glVertex3f( 0.35f, 0.0f, 0.0f ); //vertex 1
		
		glVertex3f( 0.5f, 1.0f, 0.0f ); //vertex 2
		

		glVertex3f( 0.5f, 1.0f, 0.0f ); //vertex 2	
		
		glVertex3f( 1.0f, 0.0f, 0.0f ); //vertex 3
		
		glVertex3f( 0.65f, 0.0f, 0.0f ); //vertex 1
		glEnd();

		glNormal3d(0,0,-1);
		glBegin(GL_TRIANGLE_STRIP);    
		
		glVertex3f( 0.35f, 0.0f, 0.0f ); //vertex 1
		
		glVertex3f( 0.0f, 0.0f, 0.0f ); //vertex 1
		
		glVertex3f( 0.5f, 1.0f, 0.0f ); //vertex 2
		glVertex3f( 0.5f, 1.0f, 0.0f ); //vertex 2	
		
		glVertex3f( 0.65f, 0.0f, 0.0f ); //vertex 1
		
		glVertex3f( 1.0f, 0.0f, 0.0f ); //vertex 3
		glEnd();	
		//Parte de baixo2, fora & dentro
		
		glNormal3d(0,0,1);
		glBegin(GL_TRIANGLE_STRIP);    
		
		glVertex3f( 0.5f, 1.0f, 0.0f ); //vertex 2	
		
		glVertex3f( 0.5f, 0.0f, 0.15f ); //vertex 1
		
		glVertex3f( 0.65f, 0.0f, 0.0f ); //vertex 1
		glEnd();
		glNormal3d(0,0,-1);
		glBegin(GL_TRIANGLE_STRIP);    
		
		glVertex3f( 0.5f, 1.0f, 0.0f ); //vertex 2	
		
		glVertex3f( 0.65f, 0.0f, 0.0f ); //vertex 1
		
		glVertex3f( 0.5f, 0.0f, 0.15f ); //vertex 1
		glEnd();
		//Parte de baixo2, fora & dentro
		
		glNormal3d(0,0,1);
		glBegin(GL_TRIANGLE_STRIP);    
		
		glVertex3f( 0.5f, 1.0f, 0.0f ); //vertex 2	
		
		glVertex3f( 0.35f, 0.0f, 0.0f ); //vertex 1
		
		glVertex3f( 0.5f, 0.0f, 0.15f ); //vertex 1
		glEnd();

		glNormal3d(0,0,-1);
		glBegin(GL_TRIANGLE_STRIP);    
		
		glVertex3f( 0.5f, 1.0f, 0.0f ); //vertex 2	
		
		glVertex3f( 0.5f, 0.0f, 0.15f ); //vertex 1
		
		glVertex3f( 0.35f, 0.0f, 0.0f ); //vertex 1
		glEnd();
	glPopMatrix();

}

void MyPaperPlane::update(unsigned long t)
{

	if (ty<=1) {
		
		if(anglex>=-90){	
			anglex-=5;
			ty-=0.05;
		}
		
	}
	else if(tx>1.1) {
		tx-=0.2;
		anglex+=-1;
		if(ty<6) 
			ty+=0.1;
	}

	else {
		
		anglex-=5;
		if(ty>0.5)
			ty-=0.2;
	}


	



}