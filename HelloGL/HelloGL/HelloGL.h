#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL\freeglut.h"
#include "GLUTCallbacks.h"
#include "Structures.h"
#include "SceneObject.h"
#include "Planet.h"

#define REFRESHRATE 16

class HelloGL {
public:
	HelloGL(int argc, char* argv[]);
	~HelloGL(void);
	void Display();
	void Update();
	void Keyboard(unsigned char key, int x, int y);
	void InitObjects();
	void InitLighting();
	void InitGL(int argc, char* argv[]);
	void DrawString(const char* text, Vector3* position, Color* color);

private:
	float rotation;
	Camera* camera;
	Planet* Planets[10];
	Vector4* _lightPosition;
	Lighting* _lightData;
	int planet_slower;
	bool m_delete;
	bool deleted_once;

};
