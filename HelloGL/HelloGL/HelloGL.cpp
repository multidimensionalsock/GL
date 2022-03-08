#include "HelloGL.h"
#include "GLUTCallbacks.h"
#include "Structures.h"
#include "Cube.h"
#include "MeshLoader.h"

HelloGL::HelloGL(int argc, char* argv[]) {
	rotation = 0.0f;
	
	InitGL(argc, argv); //glut or GL
	InitObjects(); //creating objects

	glutMainLoop(); //put nothing after this
}

void HelloGL::Display() {
	glClear(GL_COLOR_BUFFER_BIT);

	for (int i = 0; i < 200; i++) {
		cube[i]->Draw();
		cube[i]->Update();
	}

	glFlush();
	glutSwapBuffers(); // double buffering
}

HelloGL::~HelloGL(void) {
	delete camera;
}

void HelloGL::Update() {
	glLoadIdentity();
	gluLookAt(camera->eye.x, camera->eye.y, camera->eye.z, 
		camera->centre.x, camera->centre.y, camera->centre.z, 
		camera->up.x, camera->up.y, camera->up.z);
	glTranslatef(0.0f, 0.0f, -5.0f);
	rotation += 0.5f;
	//Sleep(10);
	if (rotation >= 360.0f)
		rotation = 0.0f;

	glutPostRedisplay();
}

void HelloGL::Keyboard(unsigned char key, int x, int y) {
	if (key == 'd')
		rotation += 0.5f;
	if (key = 'a') {
		camera->eye.z += 0.1f; // zoom in
	}
}

void HelloGL::InitObjects() {
	camera = new Camera();
	camera->eye.x = 0.0f; camera->eye.y = 0.0f; camera->eye.z = 1.0f;
	camera->centre.x = 0.0f, camera->centre.y = 0.0f, camera->centre.z = 0.0f;
	camera->up.x = 0.0f; camera->up.y = 1.0f; camera->up.z = 0.0f;

	Mesh* cubeMesh = MeshLoader::Load((char*)"cube.txt");

	for (int i = 0; i < 200; i++) {
		//cube[i] = new Cube(cubeMesh, 0.0f, 0.0f, 0.0f);

		//cube[i] = new Cube(cubeMesh, 0.0f, 0.0f, 0.0f);
		cube[i] = new Cube(cubeMesh, ((rand() % 400) / 10.0f) - 20.0f, ((rand() % 200) / 10.0f) - 10.0f, (rand() % 1000) / 10.0f);
		/*cube[i] = new Cube(((rand() % 400) / 10.0f) - 20.0f,
			((rand() % 200) / 10.0f) - 10.0f,
			(rand() % 1000) / 10.0f);*/
	}
}
void HelloGL::InitGL(int argc, char* argv[]) {

	GLUTCallbacks::Init(this);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE); // double buffering
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(100, 100); // aspect ratio (max point onaxis is now 100 x and y not 1)
	glutCreateWindow("simple openGL program");
	glutKeyboardFunc(GLUTCallbacks::Keyboard);
	glutDisplayFunc(GLUTCallbacks::Display);
	glutTimerFunc(REFRESHRATE, GLUTCallbacks::Timer, REFRESHRATE);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, 800, 800);
	gluPerspective(45, 1, 0, 1000); //field of view, aspect ratio, near clipping distance, far clipping distance
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
}