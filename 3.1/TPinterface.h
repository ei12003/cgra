#ifndef TPinterface_H
#define TPinterface_H

#include "CGFinterface.h"
#include "LightingScene.h"

class TPinterface: public CGFinterface {
	public:
		TPinterface();

		virtual void initGUI();
		virtual void processGUI(GLUI_Control *ctrl);
		
		

		virtual void processKeyboard(unsigned char key, int x, int y);
		int luz1,luz2,luz3,luz4,testVar;
};


#endif
