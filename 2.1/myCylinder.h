#ifndef MY_CYLINDER
#define MY_CYLINDER

#include "CGF/CGFobject.h"


class myCylinder : public CGFobject {

	bool smooth;
	int slices;
	int stacks;

	public:
		myCylinder(int slices, int stacks, bool smooth);
		void draw();

};



#endif
