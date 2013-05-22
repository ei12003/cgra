#ifndef MY_ROBOT
#define MY_ROBOT

#include "CGFobject.h"
#include "CGFappearance.h"
#include "MyClockHand.h"

class MyRobot : public CGFobject {

private:
	float tx,ty,tz;
	int angle;
	float rad;

	public:
		MyRobot(int angle, float tx, float ty, float tz);
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
