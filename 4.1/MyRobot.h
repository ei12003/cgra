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
	int angle;
	float rad,stacks;
	ponto square[12];
	ponto circle[12];
	ponto **aresta;

	public:
		MyRobot(int angle, float tx, float ty, float tz,float stacks);
		void draw();

		int getAngle();
		void moveForward();
		void moveBackward();
		void rotateRight();
		void rotateLeft();
		float gettx();
		float gettz();
};



#endif
