#include "TPinterface.h"
#include "LightingScene.h"

TPinterface::TPinterface()
{
	testVar=0;
}


void TPinterface::processKeyboard(unsigned char key, int x, int y)
{
	// Uncomment below if you would like to process the default keys (e.g. 's' for snapshot, 'Esc' for exiting, ...)
	// CGFinterface::processKeyboard(key, x, y);

	switch(key)
	{
		case 'a':
		{
			// This is an example of accessing the associated scene
			// To test, create the function toggleSomething in your scene to activate/deactivate something
			//int angle, int rx, int ry, int rz, int tx, int ty, int tz
			//((LightingScene *) scene)->toggleSomething(int angle, int rx, int ry, int rz, int tx, int ty, int tz);
			
			break;
		}
		case 'k':
		{
			// This is an example of accessing the associated scene
			// To test, create the function toggleSomething in your scene to activate/deactivate something
			//((LightingScene *) scene)->toggleSomething();
		//((LightingScene *) scene)->toggleSomething(0,0,0,0,2);
			((LightingScene *) scene)->robot->moveBackward();
			break;
		}
		case 'j':
		{
			// This is an example of accessing the associated scene
			// To test, create the function toggleSomething in your scene to activate/deactivate something
			((LightingScene *) scene)->robot->rotateLeft();
			
			break;
		}
		case 'l':
		{
			// This is an example of accessing the associated scene
			// To test, create the function toggleSomething in your scene to activate/deactivate something
			((LightingScene *) scene)->robot->rotateRight();
			break;
		}
		case 'i':
		{
			// This is an example of accessing the associated scene
			// To test, create the function toggleSomething in your scene to activate/deactivate something
			//((LightingScene *) scene)->toggleSomething(0,0,0,0,);
			((LightingScene *) scene)->robot->moveForward();
			break;
		}

	}
}

void TPinterface::initGUI()
{
	// Check CGFinterface.h and GLUI documentation for the types of controls available
	GLUI_Panel *obj_panel= addPanel("Luz", 1);
	
	GLUI_Checkbox *checkbox1= addCheckboxToPanel(obj_panel,"Luzes",&luz1);
	GLUI_Checkbox *checkbox2= addCheckboxToPanel(obj_panel,"Luzes",&luz2);
	GLUI_Checkbox *checkbox3= addCheckboxToPanel(obj_panel,"Luzes",&luz3);
	GLUI_Checkbox *checkbox4= addCheckboxToPanel(obj_panel,"Luzes",&luz4);
	//addSpinnerToPanel(varPanel, "Luz", 2, &testVar, 1);
	//addCheckboxToPanel(GLUI_Panel *p,char* name, int* value= (int*) 0,int id = -1);
	// You could also pass a reference to a variable from the scene class, if publicobj_panel, "Wireframe", &wireframe, 1, control_cb
	//addSpinnerToPanel(varPanel, "Val 2(scene)", 2, &(((LightingScene*) scene)->sceneVar), 2);

}

void TPinterface::processGUI(GLUI_Control *ctrl)
{

	
	printf("%d|%d|%d|%d|\n", luz1,luz2,luz3,luz4);
	
	printf ("GUI control id: %d\n  ",ctrl->user_id);
	switch (ctrl->user_id)
	{
		case 1:
		{
			printf ("New Val 1(interface): %d\n",testVar);
			break;
		};

		case 2:
		{
			printf ("New Val 2(scene): %d\n",((LightingScene*) scene)->sceneVar);
			break;
		};
	};
}

