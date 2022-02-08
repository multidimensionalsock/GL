#include "HelloGL.h"
#include "GLUTCallbacks.h"

HelloGL::HelloGL(int argc, char* argv[]) {
	rotation = 0.0f;
	GLUTCallbacks::Init(this);
	glutInit(&argc, argv);
	glutInitWindowSize(800, 800);
	glutCreateWindow("simple openGL program");
	glutDisplayFunc(GLUTCallbacks::Display);
	glutTimerFunc(REFRESHRATE, GLUTCallbacks::Timer, REFRESHRATE);
	glutMainLoop(); //put nothing after this
}

void HelloGL::Display() {
	glClear(GL_COLOR_BUFFER_BIT);

	DrawPolygon1();
	
	glFlush();
}

void HelloGL::DrawPolygon1() {
	glPushMatrix();
	glRotatef(rotation, 1.0f, 1.0f, 1.0f);

	glBegin(GL_POLYGON);
	glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
	glVertex2f(-0.75f, 0.5f);
	glColor4f(0.0f, 1.0f, 0.0f, 0.0f);
	glVertex2f(-0.2f, 0.5f);
	glColor4f(0.0f, 0.0f, 1.0f, 0.0f);
	glVertex2f(-0.1f, -0.5f);
	glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
	glVertex2f(-0.75, -0.5f);
	glEnd();
	glPopMatrix();
}



HelloGL::~HelloGL(void) {

}

void HelloGL::Update() {
	rotation += 0.5f;
	if (rotation >= 360.0f)
		rotation = 0.0f;

	glutPostRedisplay();
}
