#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL\freeglut.h"
#include "GLUTCallbacks.h"
#include "Structures.h"
#include <iostream>
#include <fstream>
#include <string>
#include "SceneObject.h"

class Cube : public SceneObject 
{
	private:
		//static Vertex* indexedVertices;
		//static Color* indexedColors;
		//static GLushort* indices; // inbuilt typedef 16 bit unsigned int
		//static int numVertices, numColors, numIndices;
		
		GLfloat _rotation;
		Vector3 _position;
		//Mesh* _mesh;

	public:
		Cube(Mesh* mesh, Texture2D* texture, float x, float y, float z);
		~Cube();
		void Draw();
		void Update();
		void SetRotation(float Rotation);
		//static bool Load(char* path);
};

