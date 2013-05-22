#ifndef MYTABLE_H
#define MYTABLE_H

#include "CGFobject.h"
#include "CGFappearance.h"

class myTable: public CGFobject {
	public:
		void draw();

	CGFappearance* tableAppearance;
	CGFappearance* matB;
};

#endif