/*
Programul afiseaza un patrat pe care il translateaza
pe axa x la apasarea sagetilor stanga, dreapta
*/
#include "glos.h"

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glaux.h>
#include <math.h>

void myinit(void);
void CALLBACK display(void);
void CALLBACK myReshape(GLsizei w, GLsizei h);
void CALLBACK MutaStanga(void);
void CALLBACK MutaDreapta(void);
void CALLBACK MutaSus(void);
void CALLBACK MutaSus(void);
void CALLBACK rot_z_up(void);
void CALLBACK rot_z_down(void);


static GLfloat x = 0, y = 0, alfa = 0, angle = 0.0;


void myinit(void) {
	
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	GLfloat light_ambient[] = { 0.2, 0.2, 0.2, 1.0 };
	GLfloat light_diffuse[] = { 0.8, 0.8, 0.8, 1.0 };
	GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);

	GLfloat light_position[] = { -10.0, 10.0, 20.0, 1.0 };
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);

	
	glDepthFunc(GL_LESS);
	glEnable(GL_COLOR_MATERIAL);

	GLfloat mat_ambient[] = { 0.5, 0.5, 0.5, 1.0 };
	GLfloat mat_diffuse[] = { 0.7, 0.7, 0.7, 1.0 };
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_shininess[] = { 30.0 };

	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

	glColorMaterial(GL_FRONT, GL_DIFFUSE);

	glClearColor(0.1, 0.2, 0.1, 0.0);
}

void CALLBACK desenare() {
	glPointSize(1);
	glColor3f(1.0, 0, 1.0);
	glBegin(GL_QUADS);

	// ******************FATA MASINII******************
	// fata de sus
	glColor3f(0.0, 0, 1.0);
	glVertex3f(0.1, -1.4, 0.6);
	glVertex3f(0.6, -1.3, 0.6);
	glVertex3f(0.6, -1.3, 0.2);
	glVertex3f(0.1, -1.4, 0.2);

	// fata de jos
	glVertex3f(0.1, -1.6, 0.6);
	glVertex3f(0.6, -1.6, 0.6);
	glVertex3f(0.6, -1.6, 0.2);
	glVertex3f(0.1, -1.6, 0.2);

	// fata din stanga
	glVertex3f(0.1, -1.6, 0.6);
	glVertex3f(0.1, -1.4, 0.6);
	glVertex3f(0.1, -1.4, 0.2);
	glVertex3f(0.1, -1.6, 0.2);

	// fata din dreapta
	glVertex3f(0.6, -1.6, 0.6);
	glVertex3f(0.6, -1.3, 0.6);
	glVertex3f(0.6, -1.3, 0.2);
	glVertex3f(0.6, -1.6, 0.2);

	// fata din fata
	glVertex3f(0.1, -1.6, 0.6);
	glVertex3f(0.6, -1.6, 0.6);
	glVertex3f(0.6, -1.3, 0.6);
	glVertex3f(0.1, -1.4, 0.6);

	// fata din spate
	glVertex3f(0.1, -1.6, 0.2);
	glVertex3f(0.6, -1.6, 0.2);
	glVertex3f(0.6, -1.3, 0.2);
	glVertex3f(0.1, -1.4, 0.2);

	// capota
	glVertex3f(0.7, -1.13, 0.6);
	glVertex3f(0.7, -1.13, 0.2);
	glVertex3f(1.5, -1.13, 0.2);
	glVertex3f(1.5, -1.13, 0.6);

	// ******************SPATELE MASINII******************
	// fata de sus
	glColor3f(0.0, 0, 1.0);
	glVertex3f(1.6, -1.3, 0.6);
	glVertex3f(1.6, -1.3, 0.2);
	glVertex3f(2, -1.4, 0.2);
	glVertex3f(2, -1.4, 0.6);

	// fata de jos
	glVertex3f(2, -1.6, 0.6);
	glVertex3f(2, -1.6, 0.2);
	glVertex3f(1.6, -1.6, 0.6);
	glVertex3f(1.6, -1.6, 0.6);

	// fata din dreapta
	glVertex3f(2, -1.4, 0.6);
	glVertex3f(2, -1.4, 0.2);
	glVertex3f(2, -1.6, 0.2);
	glVertex3f(2, -1.6, 0.6);

	// fata din stanga
	glVertex3f(1.6, -1.3, 0.6);
	glVertex3f(1.6, -1.3, 0.2);
	glVertex3f(1.6, -1.6, 0.2);
	glVertex3f(1.6, -1.6, 0.6);

	// fata din spate
	glVertex3f(1.6, -1.6, 0.2);
	glVertex3f(1.6, -1.3, 0.2);
	glVertex3f(2, -1.4, 0.2);
	glVertex3f(2, -1.6, 0.2);

	// fata din fata
	glVertex3f(1.6, -1.6, 0.6);
	glVertex3f(1.6, -1.3, 0.6);
	glVertex3f(2, -1.4, 0.6);
	glVertex3f(2, -1.6, 0.6);

	// ******************MIJLOCUL MASINII******************
	// fata din fata
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.6, -1.3, 0.6);
	glVertex3f(0.6, -1.6, 0.6);
	glVertex3f(1.6, -1.6, 0.6);
	glVertex3f(1.6, -1.3, 0.6);

	// fata de sus
	glVertex3f(0.6, -1.3, 0.6);
	glVertex3f(0.6, -1.3, 0.2);
	glVertex3f(1.6, -1.3, 0.2);
	glVertex3f(1.6, -1.3, 0.6);

	// fata de jos
	glVertex3f(0.6, -1.6, 0.6);
	glVertex3f(0.6, -1.6, 0.2);
	glVertex3f(1.6, -1.6, 0.2);
	glVertex3f(1.6, -1.6, 0.6);

	// fata din spate
	glVertex3f(0.6, -1.3, 0.2);
	glVertex3f(0.6, -1.6, 0.2);
	glVertex3f(1.6, -1.6, 0.2);
	glVertex3f(1.6, -1.3, 0.2);

	// ******************GEAMURI******************
	// parbriz
	glColor3f(0.8, 0.8, 0.8);
	glVertex3f(0.6, -1.3, 0.6);
	glVertex3f(0.6, -1.3, 0.2);
	glVertex3f(0.7, -1.13, 0.2);
	glVertex3f(0.7, -1.13, 0.6);

	// luneta
	glVertex3f(1.5, -1.13, 0.6);
	glVertex3f(1.5, -1.13, 0.2);
	glVertex3f(1.6, -1.3, 0.2);
	glVertex3f(1.6, -1.3, 0.6);

	// geam lateral - fata din spate
	glColor3f(0.8, 0.8, 0.8);
	glVertex3f(0.7, -1.13, 0.21);
	glVertex3f(0.7, -1.3, 0.21);
	glVertex3f(1.5, -1.3, 0.21);
	glVertex3f(1.5, -1.13, 0.21);

	// separatoare
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(0.7, -1.15, 0.2);
	glVertex3f(0.6, -1.3, 0.2);
	glVertex3f(0.73, -1.3, 0.2);
	glVertex3f(0.73, -1.15, 0.2);

	glVertex3f(1.1, -1.15, 0.2);
	glVertex3f(1.1, -1.3, .2);
	glVertex3f(1.13, -1.3, 0.2);
	glVertex3f(1.13, -1.15, 0.2);

	glVertex3f(1.47, -1.15, 0.2);
	glVertex3f(1.47, -1.3, .2);
	glVertex3f(1.6, -1.3, 0.2);
	glVertex3f(1.5, -1.15, 0.2);

	glVertex3f(0.7, -1.13, 0.2);
	glVertex3f(0.7, -1.15, 0.2);
	glVertex3f(1.5, -1.15, 0.2);
	glVertex3f(1.5, -1.13, 0.2);

	// geam lateral - fata din fata
	glColor3f(0.8, 0.8, 0.8);
	glVertex3f(0.7, -1.13, 0.59);
	glVertex3f(0.7, -1.3, 0.59);
	glVertex3f(1.5, -1.3, 0.59);
	glVertex3f(1.5, -1.13, 0.59);

	// separatoare
	glColor3f(1.0, 0, 1.0);
	glVertex3f(0.7, -1.13, 0.6);
	glVertex3f(0.6, -1.3, 0.6);
	glVertex3f(0.73, -1.3, 0.6);
	glVertex3f(0.73, -1.13, 0.6);

	glVertex3f(1.1, -1.13, 0.6);
	glVertex3f(1.1, -1.3, 0.6);
	glVertex3f(1.13, -1.3, 0.6);
	glVertex3f(1.13, -1.13, 0.6);

	glVertex3f(1.47, -1.13, 0.6);
	glVertex3f(1.47, -1.3, 0.6);
	glVertex3f(1.6, -1.3, 0.6);
	glVertex3f(1.5, -1.13, 0.6);

	glVertex3f(0.7, -1.13, 0.6);
	glVertex3f(0.7, -1.15, 0.6);
	glVertex3f(1.5, -1.15, 0.6);
	glVertex3f(1.5, -1.13, 0.6);

	glEnd();

	// ******************ROTILE******************
	glColor3f(0, 0, 0);
	glPushMatrix();

	glBegin(GL_TRIANGLE_FAN);
	int i = 0;
	int c = 0;
	glVertex3f(0.6, -1.6, 0.63);
	for (i = 0; i < 360; i = i + 22)
	{
		glColor3f(c%2,c%2, c%2);
		glVertex3f(0.6 + (0.1 * (cos(((i + angle) *3.14*3.14) /360))), -1.6 + (0.1 * (sin(((i + angle) *3.14* 3.14) / 360))), 0.6);
		glVertex3f(0.6 + (0.1 * (cos(((i+1 + angle) *3.14* 3.14) / 360))), -1.6 + (0.1 * (sin(((i+1 + angle) *3.14* 3.14) / 360))), 0.6);
		c++;
	}
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	c = 0;
	glVertex3f(0.6, -1.6, 0.17);
	for (i = 0; i < 360; i = i + 22)
	{
		glColor3f(c % 2, c % 2, c % 2);
		glVertex3f(0.6 + (0.1 * (cos(((i + angle) * 3.14 * 3.14) / 360))), -1.6 + (0.1 * (sin(((i + angle) * 3.14 * 3.14) / 360))), 0.2);
		glVertex3f(0.6 + (0.1 * (cos(((i + 1 + angle) * 3.14 * 3.14) / 360))), -1.6 + (0.1 * (sin(((i + 1 + angle) * 3.14 * 3.14) / 360))), 0.2);
		c++;
	}
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	c = 0;
	glVertex3f(1.6, -1.6, 0.17);
	for (i = 0; i < 360; i = i + 22)
	{
		glColor3f(c % 2, c % 2, c % 2);
		glVertex3f(1.6 + (0.1 * (cos(((i + angle) * 3.14 * 3.14) / 360))), -1.6 + (0.1 * (sin(((i + angle) * 3.14 * 3.14) / 360))), 0.2);
		glVertex3f(1.6 + (0.1 * (cos(((i + 1 + angle) * 3.14 * 3.14) / 360))), -1.6 + (0.1 * (sin(((i + 1 + angle) * 3.14 * 3.14) / 360))), 0.2);
		c++;
	}
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	c = 0;
	glVertex3f(1.6, -1.6, 0.63);
	for (i = 0; i < 360; i = i + 22)
	{
		glColor3f(c % 2, c % 2, c % 2);
		glVertex3f(1.6 + (0.1 * (cos(((i + angle) * 3.14 * 3.14) / 360))), -1.6 + (0.1 * (sin(((i + angle) * 3.14 * 3.14) / 360))), 0.6);
		glVertex3f(1.6 + (0.1 * (cos(((i + 1 + angle) * 3.14 * 3.14) / 360))), -1.6 + (0.1 * (sin(((i + 1 + angle) * 3.14 * 3.14) / 360))), 0.6);
		c++;
	}
	glEnd();

	glPopMatrix();


}

void CALLBACK MutaStanga(void)
{
	x = x - 0.1;
	angle = angle + 10;
}
void CALLBACK MutaDreapta(void)
{
	x = x + 0.1;
	angle = angle - 10;
}
void CALLBACK MutaSus(void)
{
	y = y + 0.1;
}
void CALLBACK MutaJos(void)
{
	y = y - 0.1;
}
void CALLBACK rot_z_up(void)
{
	alfa = alfa + 20;
}
void CALLBACK rot_z_down(void)
{
	alfa = alfa - 20;
}

void CALLBACK display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();
	glEnable(GL_DEPTH_TEST);

	glPushMatrix();
	glTranslatef(x, y, 0.0);
	glRotatef(alfa, 1, 1, 0);
	desenare();
	glPopMatrix();

	
	glFlush();
}

void CALLBACK myReshape(GLsizei w, GLsizei h)
{
	if (!h) return;
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w <= h)
		glOrtho(-3.0, 3.0, -3.0 * (GLfloat)h / (GLfloat)w,
			3.0 * (GLfloat)h / (GLfloat)w, -4.0, 4.0);
	else
		glOrtho(-3.0 * (GLfloat)w / (GLfloat)h,
			3.0 * (GLfloat)w / (GLfloat)h, -3.0, 3.0, -4.0, 4.0);
	glMatrixMode(GL_MODELVIEW);
}


int main(int argc, char** argv)
{
	auxInitDisplayMode(AUX_SINGLE | AUX_RGB | AUX_DEPTH);
	auxInitPosition(0, 0, 300, 200);
	auxInitWindow("O super masina");
	myinit();
	auxKeyFunc(AUX_LEFT, MutaStanga);
	auxKeyFunc(AUX_RIGHT, MutaDreapta);
	auxKeyFunc(AUX_UP, MutaSus);
	auxKeyFunc(AUX_DOWN, MutaJos);
	auxMouseFunc(AUX_LEFTBUTTON, AUX_MOUSEDOWN, rot_z_up);
	auxMouseFunc(AUX_RIGHTBUTTON, AUX_MOUSEDOWN, rot_z_down);

	auxReshapeFunc(myReshape);
	auxMainLoop(display);
	return(0);
}