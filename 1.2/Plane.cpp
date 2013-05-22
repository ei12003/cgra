#include "Plane.h"
#include "ExampleObject.h"
#include <GL/GLU.h>


Plane::Plane(void)
{
	_numDivisions = 1;
}

Plane::Plane(int n, double si, double sf, double ti, double tf, int type)
{
	_numDivisions = n;
	this->si=si;
	this->sf=sf;
	this->ti=ti;
	this->tf=tf;
	this->type = type;
	if(type==1)
		n-=6;
	coefs= (sf-si)/n;
	coeft= (tf-ti)/n;
	
}


Plane::~Plane(void)
{
}

void Plane::draw()
{
	const double repeat_s = 10;
	const double repeat_t = 15;

	double numDivisions= _numDivisions;
	double min;
	if((tf-ti) < (sf-si)) 
		min= tf-ti;
	else
		min=sf-si;

	//Sj = Si + j* (Sf-Si)/N

	glPushMatrix();
		glRotatef(180.0,1,0,0);
		glTranslatef(-0.5,0.0,-0.5);
		glScalef(1.0/(double) _numDivisions, 1 ,1.0/(double) _numDivisions);
		glNormal3f(0,-1,0);

		for (double bx = 0; bx<_numDivisions; bx++)
		{
			glBegin(GL_TRIANGLE_STRIP);

			if(type==0)
				glTexCoord2f((si+ bx*coeft)/min,0);
			else if(type==1)
				glTexCoord2f(0,1-(si+ (bx-2)*coeft)/min);
			else if(type==2)
				glTexCoord2f(repeat_s*bx/numDivisions,0);

				glVertex3f(bx, 0, 0);

				for (double bz = 0; bz<_numDivisions; bz++)
				{
					if(type==0)
						glTexCoord2f((si+(bx+1)*coeft)/min,(ti+bz*coefs)/min);
					else if(type==1)
						glTexCoord2f((ti+(bz-3)*coefs)/min,1-(si+(bx-2+1)*coeft)/min);
					else if(type==2)
						glTexCoord2f(repeat_s*(bx+1)/numDivisions,repeat_t*(bz)/numDivisions);

					glVertex3f(bx + 1, 0, bz);

					if(type==0)
						glTexCoord2f((si+bx*coeft)/min,(ti+(bz+1)*coefs)/min);
					else if (type==1)
						glTexCoord2f((ti+(bz+1-3)*coefs)/min,1-(si+(bx-2)*coeft)/min);
					else if(type==2)
						glTexCoord2f(repeat_s*(bx)/numDivisions,repeat_t*(bz+1)/numDivisions);

					glVertex3f(bx, 0, bz + 1);
				}
				if(type==0)
					glTexCoord2f((si+(bx+1)*coeft)/min,(ti+numDivisions*coefs)/min);
				else if (type==1)
					glTexCoord2f((ti+(numDivisions-3)*coefs)/min,1-(si+(bx-2+1)*coeft)/min);
				else if(type==2)
					glTexCoord2f(repeat_s*(bx+1)/numDivisions,repeat_t);

				glVertex3d(bx+ 1, 0, _numDivisions);

			glEnd();
		}
	glPopMatrix();
glShadeModel(GL_SMOOTH);
}
