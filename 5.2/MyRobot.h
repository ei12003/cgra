#ifndef MY_ROBOT
#define MY_ROBOT

#include "CGFobject.h"
#include "CGFappearance.h"
#include "MyClockHand.h"

typedef struct ponto {
	double x;
	double y;
	double z;
}ponto;


class MyRobot : public CGFobject {

private:
	float tx,ty,tz;
	int angle,stacks,slices;
	float rad;
	ponto square[12], **aresta, normal, square_map[12], **aresta_map;
	double raio,coef,a,pi;
	
	public:
		MyRobot(int angle, float tx, float ty, float tz,int stacks);
		void draw();
		CGFappearance *robotAppearance1,*robotAppearance2;
		int texture;
		bool textured;

		ponto getNormal(vector<ponto> v1);
		int getAngle();
		void changeTexture(int id);
		void changeTextured();
		void moveForward();
		void moveBackward();
		void rotateRight();
		void rotateLeft();
		float gettx();
		float gettz();
};



#endif
