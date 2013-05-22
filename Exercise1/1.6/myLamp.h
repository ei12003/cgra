#ifndef MY_LAMP
#define MY_LAMP

#include "CGF/CGFobject.h"

class myLamp : public CGFobject {

	bool smooth;
	int slices;
	int stacks;

	public:
		myLamp(int slices, int stacks, bool smooth);
		void draw();

};



#endif
