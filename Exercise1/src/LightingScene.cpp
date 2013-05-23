#include "TPinterface.h"
#include "LightingScene.h"
#include "CGFaxis.h"
#include "CGFapplication.h"
#include "myTable.h"
#include "Plane.h"

#include <math.h>
#define GL_CLAMP_TO_EDGE 33071
#define RAD  0.0174532925 ;


float pi = acos(-1.0);
float deg2rad=pi/180.0;

#define BOARD_HEIGHT 6.0
#define BOARD_WIDTH 6.4

// Positions for two lights
float light0_pos[4] = {4, 6.0, 1.0, 1.0};
float light1_pos[4] = {2, 6.0, 8.0, 1.0};

float light2_pos[4] = {2, 6.0, 8.0, 1.0};
float light3_pos[4] = {2, 6.0, 8.0, 1.0};

// Global ambient light (do not confuse with ambient component of individual lights)
float globalAmbientLight[4]= {0,0,0,0};

// number of divisions
#define BOARD_A_DIVISIONS 30
#define BOARD_B_DIVISIONS 100

// Coefficients for material A
float ambA[3] = {0.2, 0.2, 0.2};
float difA[3] = {0.6, 0.6, 0.6};
float specA[3] = {0, 0.8, 0.8};
float shininessA = 120.f;

// Coefficients for material B
float ambB[3] = {0.2, 0.2, 0.2};
float difB[3] = {0.6, 0.6, 0.6};
float specB[3] = {0.8, 0.8, 0.8};
float shininessB = 120.f;

// Coefficients for material BA
float ambBA[3] = {0.4, 0.4, 0.4};
float difBA[3] = {0.3, 0.3, 0.3};
float specBA[3] = {0.4, 0.4, 0.4};
float shininessBA = 120.f;

// Coefficients for material SA
float ambSA[3] = {0.4, 0.4, 0.4};
float difSA[3] = {0.9, 0.9, 0.9};
float specSA[3] = {0.2, 0.2, 0.2};
float shininessSA = 1.f;

// Coefficients for material W
float ambW[3] = {0.2, 0.2, 0.2};
float difW[3] = {0.9, 0.9, 0.9};
float specW[3] = {0.2, 0.2, 0.2};
float shininessW = 10.f;


// Coefficients for material F
float ambF[3] = {0.4, 0.4, 0.4};
float difF[3] = {0.9, 0.9, 0.9};
float specF[3] = {0.2, 0.2, 0.2};
float shininessF = 1.f;




float ambientNull[4]={0,0,0,1};
float yellow[4]={1,1,0,1};

void LightingScene::init() 
{
	// Enables lighting computations
	glEnable(GL_LIGHTING);

	// Sets up some lighting parameters
	// Computes lighting only using the front face normals and materials
	glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_FALSE);  
	
	// Define ambient light (do not confuse with ambient component of individual lights)
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, globalAmbientLight);  
	//glShadeModel(GL_FLAT);
	// Declares and enables two lights, with null ambient component

	light0 = new CGFlight(GL_LIGHT0, light0_pos);
	light0->setAmbient(ambientNull);

	light0->disable();
	light0->setSpecular(yellow);
	light0->enable();

	light1 = new CGFlight(GL_LIGHT1, light1_pos);
	light1->setAmbient(ambientNull);
	
	light1->disable();
	light1->enable();

	light2 = new CGFlight(GL_LIGHT2, light2_pos);
	light2->setAmbient(ambientNull);
	
	light2->disable();
	light2->setKc(0);
	light2->setKl(1);
	light2->setKq(0);
	light2->enable();

	light3 = new CGFlight(GL_LIGHT3, light3_pos);
	light3->setAmbient(ambientNull);
	
	light3->disable();
	light3->setKc(0);
	light3->setKl(0);
	light3->setKq(0.2);
	light3->enable();
	
	// Uncomment below to enable normalization of lighting normal vectors
	 glEnable (GL_NORMALIZE);

	//Declares scene elements
	 //robot = new MyRobot(180,4,4,7);
	  robot = new MyRobot(0,4,4,7,10);
	 sceneVar=0;
	 t = CGFapplication::getTime();
	 aviao=new MyPaperPlane(90,4,4,8);
	clock1= new MyClock();
	table = new myTable();
	floor = new Plane(10, 0, 0, 0 , 0, 2);
	wallWindow = new Plane(10, 0, 16,0-3.5, 8.53-3.5,1);
	wall = new Plane(10, 0, 16,0-3.5, 8.53-3.5,1);
	boardA = new Plane(BOARD_A_DIVISIONS,0, 512, 0, 512);
	boardB = new Plane(BOARD_B_DIVISIONS,0, 512, 0-70, 372-70);
	

	//Declares materials
	materialA = new CGFappearance(ambA,difA,specA,shininessA);
	materialB = new CGFappearance(ambB,difB,specB,shininessB);
	
	slidesAppearance = new CGFappearance(ambSA,difSA,specSA,shininessSA);
	slidesAppearance->setTexture("slides.png");

	boardAppearance = new CGFappearance(ambBA,difBA,specBA,shininessBA);
	boardAppearance->setTexture("board.png");
	boardAppearance->setTextureWrap(GL_CLAMP,GL_CLAMP);


	windowAppearance = new CGFappearance(ambW,difW,specW,shininessW);
	windowAppearance->setTexture("window.png");
	windowAppearance->setTextureWrap(GL_CLAMP_TO_EDGE, GL_CLAMP_TO_EDGE);

	
		 
	floorAppearance = new CGFappearance(ambF,difF,specF,shininessF);
	floorAppearance->setTexture("floor.png");
	floorAppearance->setTextureWrap(GL_REPEAT, GL_REPEAT);

	
	setUpdatePeriod(100);

}


void LightingScene::display() 
{

	// ---- BEGIN Background, camera and axis setup
	
	// Clear image and depth buffer everytime we update the scene
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	// Initialize Model-View matrix as identity (no transformation
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// Apply transformations corresponding to the camera position relative to the origin
	CGFscene::activeCamera->applyView();

	light0->draw();
	light1->draw();
	
	// Draw axis
	axis.draw();


	// ---- END Background, camera and axis setup

	// ---- BEGIN Primitive drawing section
	
	//First Table
	glPushMatrix();
		glTranslated(5,0,8);
		table->draw();
	glPopMatrix();

	//Second Table
	glPushMatrix();
		glTranslated(12,0,8);
		table->draw();
	glPopMatrix();

	//Floor
	glPushMatrix();
		glTranslated(7.5,0,7.5);
		glScaled(15,0.2,15);
		floorAppearance->apply();
		floor->draw();
	glPopMatrix();

	//PlaneWall
	glPushMatrix();
		glTranslated(7.5,4,0);
		glRotated(90.0,1,0,0);
		glScaled(15,0.2,8);
		materialB->apply();
		wall->draw();
	glPopMatrix();

	

		//LeftWall
	glPushMatrix();
		glTranslated(0,4,7.5);
		glRotated(-90.0,0,0,1);
		glScaled(8,0.2,15);
		windowAppearance->apply();
		wallWindow->draw();
	glPopMatrix();

	// Board A
	glPushMatrix();
		glTranslated(4,4,0.2);
		glScaled(BOARD_WIDTH,BOARD_HEIGHT,1);
		glRotated(90.0,1,0,0);
		slidesAppearance->apply();
		boardA->draw();
	glPopMatrix();
	
	//BoardB
	glPushMatrix();
		glTranslated(10.5,4,0.2);
		glScaled(BOARD_WIDTH,BOARD_HEIGHT,1);
		glRotated(90.0,1,0,0);
		boardAppearance->apply();
		boardB->draw();
	glPopMatrix();

	//m= new myCylinder(23,10,true);
	m2= new myCylinder(12,10,true);
	//l= new myLamp(12,10,false);

	glPushMatrix();
	glTranslated(6,3,12);
	glScaled(1,6,1);
	glRotated(90.0,1,0,0);
	slidesAppearance->apply();
	m2->draw();
	glPopMatrix();

	
	glPushMatrix();
	//glScaled(1,0.5,0.5);
	
	glTranslated(7.3,7.5,0.175);
	glRotated(-90,0,1,0);
	clock1->draw();
	glPopMatrix();
	
	/*glPushMatrix();

	//glRotated(-90,0,1,0);
	aviao->draw();
	glPopMatrix();*/

	// We have been drawing in a memory area that is not visible - the back buffer, 
	// while the graphics card is showing the contents of another buffer - the front buffer
	// glutSwapBuffers() will swap pointers so that the back buffer becomes the front buffer and vice-versa
			glPushMatrix();
	slidesAppearance->apply();
	robot->draw();
	glPopMatrix();
	glutSwapBuffers();
}

LightingScene::~LightingScene() 
{
	delete(light0);
	delete(light1);
	delete(table);
	delete(wall);
	delete(boardA);
	delete(boardB);
	delete(materialA);
	delete(materialB);
}


void LightingScene::update(unsigned long time) 
{
	long elapsed = time - t;
	t = time;

	clock1->update(elapsed);
	aviao->update(elapsed);
	
}

