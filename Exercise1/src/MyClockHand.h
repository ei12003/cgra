#ifndef MY_CLOCKHAND
#define MY_CLOCKHAND

#include "CGFobject.h"
#include "CGFappearance.h"
#define HORAS 1
#define MIN 2
#define SEG 3


class MyClockHand : public CGFobject {

	private:
		float angulo;

	public:
		MyClockHand();
		void draw(int opt);
		void setAngle(float ang);
		void incAngle(float ang);
		CGFappearance* matB;
	

};



#endif
