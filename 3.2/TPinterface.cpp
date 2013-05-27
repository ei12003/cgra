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
	GLUI_Panel *lights= addPanel("Luzes", 1);
	addCheckboxToPanel(lights,"Light0", NULL,100)->set_int_val(1);
	addCheckboxToPanel(lights,"Light1", NULL,101)->set_int_val(1);
	addCheckboxToPanel(lights,"Light2", NULL,102)->set_int_val(1);
	addCheckboxToPanel(lights,"Light3", NULL,103)->set_int_val(1);

	GLUI_Panel *clock= addPanel("Clock", 1);
	clockbt=addButtonToPanel(clock,"Stop",104);
	

}

void TPinterface::processGUI(GLUI_Control *ctrl)
{

	printf ("GUI control id: %d\n  ",ctrl->user_id);
	
	switch (ctrl->user_id)
	{

		case 104:
		{
			if(clockbt->name=="Start")
				clockbt->name="Stop";
			else
				clockbt->name="Start";

			((LightingScene *) scene)->clock1->changeState();
			break;
		};

		case 100:
		{
			if(	((LightingScene *) scene)->light0_state)
			{
				((LightingScene *) scene)->light0_state=false;
				((LightingScene *) scene)->light0->disable();
			}
			else{
				((LightingScene *) scene)->light0_state=true;
				((LightingScene *) scene)->light0->enable();
			}
			break;
		};
			case 101:
		{
			if(	((LightingScene *) scene)->light1_state)
			{
				((LightingScene *) scene)->light1_state=false;
				((LightingScene *) scene)->light1->disable();
			}
			else{
				((LightingScene *) scene)->light1_state=true;
				((LightingScene *) scene)->light1->enable();
			}
			break;
		};

		case 102:
		{
			if(	((LightingScene *) scene)->light2_state)
			{
				((LightingScene *) scene)->light2_state=false;
				((LightingScene *) scene)->light2->disable();
			}
			else{
				((LightingScene *) scene)->light2_state=true;
				((LightingScene *) scene)->light2->enable();
			}
			break;
		};

		case 103:
		{
			if(	((LightingScene *) scene)->light3_state)
			{
				((LightingScene *) scene)->light3_state=false;
				((LightingScene *) scene)->light3->disable();
			}
			else{
				((LightingScene *) scene)->light3_state=true;
				((LightingScene *) scene)->light3->enable();
			}
			break;
		};



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

