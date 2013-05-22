#ifndef MY_CLOCK
#define MY_CLOCK

#include "CGFobject.h"
#include "CGFappearance.h"
#include "MyClockHand.h"

class MyClock : public CGFobject {

	

	public:
		MyClock();
		void draw();
		void update(unsigned long t);
		CGFappearance* clockAppearance;

	MyClockHand ch_min;
	MyClockHand ch_h;
	MyClockHand ch_s;

};



#endif
