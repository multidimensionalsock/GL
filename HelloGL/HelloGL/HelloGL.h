#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL\freeglut.h"
#include "GLUTCallbacks.h"
#define REFRESHRATE 16

struct Vector3 {
	float x;
	float y;
	float z;
};

struct Camera {
	Vector3 eye;
	Vector3 centre;
	Vector3 up;
};

struct Color{
	GLfloat r, g, b;
};

struct Vertex{
	GLfloat x, y, z;
};


class HelloGL {
public:
	HelloGL(int argc, char* argv[]);
	~HelloGL(void);
	void Display();
	void DrawPolygon1();
	void DrawCubeArray();
	void Update();
	void Keyboard(unsigned char key, int x, int y);

private:
	float rotation;
	Camera* camera;
	static Vertex vertices[];
	static Color colors[];
};
