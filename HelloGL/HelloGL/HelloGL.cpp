#include "HelloGL.h"

HelloGL::HelloGL(int argc, char* argv[]) {
	GLUTCallbacks::Init(this);
	glutInit(&argc, argv);
	glutInitWindowSize(800, 800);
	glutCreateWindow("simple openGL program");
	glutDisplayFunc(GLUTCallbacks::Display);
	glutMainLoop(); //put nothing after this
}

void HelloGL::Display() {
	glClear(GL_COLOR_BUFFER_BIT);
	DrawPolygon1();
	DrawPolygon2();
	DrawPolygon3();
	
	glFlush();
}

void HelloGL::DrawPolygon1() {
	glBegin(GL_POLYGON);
	glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
	glVertex2f(-0.75f, 0.5f);
	glVertex2f(-0.2f, 0.5f);
	glVertex2f(-0.1f, -0.5f);
	glVertex2f(-0.75, -0.5f);
	glEnd();
}

void HelloGL::DrawPolygon2() {
	glBegin(GL_POLYGON);
	glColor4f(0.0f, 1.0f, 0.0f, 0.0f);
	glVertex2f(-0.2f, 0.5f);
	glVertex2f(0.2f, 0.5f);
	glVertex2f(0.1, -0.5f);
	glVertex2f(-0.1f, -0.5f);
	glEnd();
}

void HelloGL::DrawPolygon3() {
	glBegin(GL_POLYGON);
	glColor4f(0.0f, 0.0f, 1.0f, 0.0f);
	glVertex2f(0.2f, 0.5f);
	glVertex2f(0.75f, 0.5f);
	glVertex2f(0.75f, -0.5f);
	glVertex2f(0.1f, -0.5f);
	glEnd();
}

HelloGL::~HelloGL(void) {

}
