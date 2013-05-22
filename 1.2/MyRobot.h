#ifndef MY_ROBOT
#define MY_ROBOT

#include "CGFobject.h"
#include "CGFappearance.h"
#include "MyClockHand.h"

class MyRobot : public CGFobject {

private:
	float tx,ty,tz;
	int angle;

	public:
		MyRobot(int angle, float tx, float ty, float tz);
		void draw();
		void updateAngle(int angle);
		int getAngle();
		void inctx(float var);
		void inctz(float var);
		float MyRobot::gettx();
float MyRobot::gettz();
};



#endif
