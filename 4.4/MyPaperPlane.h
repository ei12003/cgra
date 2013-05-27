#ifndef MY_PAPERPLANE
#define MY_PAPERPLANE

#include "CGFobject.h"
#include "CGFappearance.h"


class MyPaperPlane : public CGFobject {

	private:
		int anglex;
		float tx,ty,tz;

	public:
		MyPaperPlane(int anglex,int tx, int ty, int tz);
		void draw();
		void update(unsigned long t);
		void changePlanePosition(int anglex,int tx, int ty, int tz);
	

};



#endif
