#ifndef MY_CLOCK
#define MY_CLOCK

#include "CGFobject.h"
#include "CGFappearance.h"
#include "MyClockHand.h"

class MyClock : public CGFobject {

private:
	bool state;

	public:
		MyClock();
		void draw();
		void update(unsigned long t);
		CGFappearance* clockAppearance;
		void changeState();
		bool getState();

	MyClockHand ch_min;
	MyClockHand ch_h;
	MyClockHand ch_s;

};



#endif
