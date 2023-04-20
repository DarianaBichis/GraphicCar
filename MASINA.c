#include "glos.h"

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glaux.h>
#include <math.h>

void myinit(void);
void CALLBACK display(void);
void CALLBACK myReshape(GLsizei w, GLsizei h);
void CALLBACK MoveLeft(void);
void CALLBACK MoveRight(void);
void CALLBACK MoveUp(void);
void CALLBACK MoveUp(void);
void CALLBACK RotateUp(void);
void CALLBACK RotateDown(void);


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

	// ******************FRONT OF THE CAR******************
	// top
	glColor3f(0.0, 0, 1.0);
	glVertex3f(0.1, -1.4, 0.6);
	glVertex3f(0.6, -1.3, 0.6);
	glVertex3f(0.6, -1.3, 0.2);
	glVertex3f(0.1, -1.4, 0.2);

	// bottom
	glVertex3f(0.1, -1.6, 0.6);
	glVertex3f(0.6, -1.6, 0.6);
	glVertex3f(0.6, -1.6, 0.2);
	glVertex3f(0.1, -1.6, 0.2);

	// left
	glVertex3f(0.1, -1.6, 0.6);
	glVertex3f(0.1, -1.4, 0.6);
	glVertex3f(0.1, -1.4, 0.2);
	glVertex3f(0.1, -1.6, 0.2);

	// right
	glVertex3f(0.6, -1.6, 0.6);
	glVertex3f(0.6, -1.3, 0.6);
	glVertex3f(0.6, -1.3, 0.2);
	glVertex3f(0.6, -1.6, 0.2);

	// front
	glVertex3f(0.1, -1.6, 0.6);
	glVertex3f(0.6, -1.6, 0.6);
	glVertex3f(0.6, -1.3, 0.6);
	glVertex3f(0.1, -1.4, 0.6);

	// back
	glVertex3f(0.1, -1.6, 0.2);
	glVertex3f(0.6, -1.6, 0.2);
	glVertex3f(0.6, -1.3, 0.2);
	glVertex3f(0.1, -1.4, 0.2);

	// hood
	glVertex3f(0.7, -1.13, 0.6);
	glVertex3f(0.7, -1.13, 0.2);
	glVertex3f(1.5, -1.13, 0.2);
	glVertex3f(1.5, -1.13, 0.6);

	// ******************BACK OF THE CAR******************
	// top
	glColor3f(0.0, 0, 1.0);
	glVertex3f(1.6, -1.3, 0.6);
	glVertex3f(1.6, -1.3, 0.2);
	glVertex3f(2, -1.4, 0.2);
	glVertex3f(2, -1.4, 0.6);

	// bottom
	glVertex3f(2, -1.6, 0.6);
	glVertex3f(2, -1.6, 0.2);
	glVertex3f(1.6, -1.6, 0.6);
	glVertex3f(1.6, -1.6, 0.6);

	// right
	glVertex3f(2, -1.4, 0.6);
	glVertex3f(2, -1.4, 0.2);
	glVertex3f(2, -1.6, 0.2);
	glVertex3f(2, -1.6, 0.6);

	// left
	glVertex3f(1.6, -1.3, 0.6);
	glVertex3f(1.6, -1.3, 0.2);
	glVertex3f(1.6, -1.6, 0.2);
	glVertex3f(1.6, -1.6, 0.6);

	// back
	glVertex3f(1.6, -1.6, 0.2);
	glVertex3f(1.6, -1.3, 0.2);
	glVertex3f(2, -1.4, 0.2);
	glVertex3f(2, -1.6, 0.2);

	// front
	glVertex3f(1.6, -1.6, 0.6);
	glVertex3f(1.6, -1.3, 0.6);
	glVertex3f(2, -1.4, 0.6);
	glVertex3f(2, -1.6, 0.6);

	// ******************MIDDLE OF THE CAR******************
	// front
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.6, -1.3, 0.6);
	glVertex3f(0.6, -1.6, 0.6);
	glVertex3f(1.6, -1.6, 0.6);
	glVertex3f(1.6, -1.3, 0.6);

	// top
	glVertex3f(0.6, -1.3, 0.6);
	glVertex3f(0.6, -1.3, 0.2);
	glVertex3f(1.6, -1.3, 0.2);
	glVertex3f(1.6, -1.3, 0.6);

	// bottom
	glVertex3f(0.6, -1.6, 0.6);
	glVertex3f(0.6, -1.6, 0.2);
	glVertex3f(1.6, -1.6, 0.2);
	glVertex3f(1.6, -1.6, 0.6);

	// back
	glVertex3f(0.6, -1.3, 0.2);
	glVertex3f(0.6, -1.6, 0.2);
	glVertex3f(1.6, -1.6, 0.2);
	glVertex3f(1.6, -1.3, 0.2);

	// ******************WINDOWS******************
	// windshield
	glColor3f(0.8, 0.8, 0.8);
	glVertex3f(0.6, -1.3, 0.6);
	glVertex3f(0.6, -1.3, 0.2);
	glVertex3f(0.7, -1.13, 0.2);
	glVertex3f(0.7, -1.13, 0.6);

	// rear window
	glVertex3f(1.5, -1.13, 0.6);
	glVertex3f(1.5, -1.13, 0.2);
	glVertex3f(1.6, -1.3, 0.2);
	glVertex3f(1.6, -1.3, 0.6);

	// side back window
	glColor3f(0.8, 0.8, 0.8);
	glVertex3f(0.7, -1.13, 0.21);
	glVertex3f(0.7, -1.3, 0.21);
	glVertex3f(1.5, -1.3, 0.21);
	glVertex3f(1.5, -1.13, 0.21);

	// separators
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

	// side front window
	glColor3f(0.8, 0.8, 0.8);
	glVertex3f(0.7, -1.13, 0.59);
	glVertex3f(0.7, -1.3, 0.59);
	glVertex3f(1.5, -1.3, 0.59);
	glVertex3f(1.5, -1.13, 0.59);

	// separators
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

	// ******************WHEELS******************
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

void CALLBACK MoveLeft(void)
{
	x = x - 0.1;
	angle = angle + 10;
}
void CALLBACK MoveRight(void)
{
	x = x + 0.1;
	angle = angle - 10;
}
void CALLBACK MoveUp(void)
{
	y = y + 0.1;
}
void CALLBACK MoveDown(void)
{
	y = y - 0.1;
}
void CALLBACK RotateUp(void)
{
	alfa = alfa + 20;
}
void CALLBACK RotateDown(void)
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
	auxInitWindow("Super car");
	myinit();
	auxKeyFunc(AUX_LEFT, MoveLeft);
	auxKeyFunc(AUX_RIGHT, MoveRight);
	auxKeyFunc(AUX_UP, MoveUp);
	auxKeyFunc(AUX_DOWN, MoveDown);
	auxMouseFunc(AUX_LEFTBUTTON, AUX_MOUSEDOWN, RotateUp);
	auxMouseFunc(AUX_RIGHTBUTTON, AUX_MOUSEDOWN, RotateDown);

	auxReshapeFunc(myReshape);
	auxMainLoop(display);
	return(0);
}