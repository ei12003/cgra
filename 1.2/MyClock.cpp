#include "MyClock.h"
#include "myCylinder.h"

#include "math.h"
#define GL_CLAMP_TO_EDGE 33071

MyClock::MyClock(){
	ch_min= MyClockHand();
	ch_h= MyClockHand();
	ch_s= MyClockHand();

	ch_min.setAngle(180);
	ch_h.setAngle(270);
	ch_s.setAngle(90);
}

void MyClock::draw()
{
	// Coefficients for material W
	float ambW[3] = {0.2, 0.2, 0.2};
	float difW[3] = {0.9, 0.9, 0.9};
	float specW[3] = {0.2, 0.2, 0.2};
	float shininessW = 10.f;

	clockAppearance = new CGFappearance(ambW,difW,specW,shininessW);
	clockAppearance->setTexture("clock.png");
	clockAppearance->setTextureWrap(GL_REPEAT, GL_REPEAT);

	
	myCylinder* c= new myCylinder(12,1,true);

	glPushMatrix();
	glScaled(0.10,1,1);
	glRotated(90,0,1,0);
	clockAppearance->apply();
	c->draw();
	glPopMatrix();

	
ch_min.draw(MIN);
ch_h.draw(HORAS);
ch_s.draw(SEG);

}

void MyClock::update(unsigned long t)
{
	float s = ((float)(t)/1000.0)*360.0/(12.0*5.0);
	ch_s.incAngle(-s);
	ch_min.incAngle(-(s/60.0));
	ch_h.incAngle(-(s/(3600.0/5.0)));
}