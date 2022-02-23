#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL\freeglut.h"
#include "GLUTCallbacks.h"
#include "Structures.h"

class Cube{
	private:
		static Vertex indexedVertices[];
		static Color indexedColors[];
		static GLushort indices[]; // inbuilt typedef 16 bit unsigned int
		GLfloat _rotation;
		Vector3 _position;

	public:
		Cube(float x, float y, float z);
		~Cube();
		void Draw();
		void Update();
		void SetRotation(float Rotation);
};

