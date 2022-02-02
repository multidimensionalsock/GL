#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL\freeglut.h"
#include "GLUTCallbacks.h"


class HelloGL {
public:
	HelloGL(int argc, char* argv[]);
	~HelloGL(void);
	void Display();
	void DrawPolygon1();
	void DrawPolygon2();
	void DrawPolygon3();
};
