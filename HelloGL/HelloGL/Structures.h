#pragma once

#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL\freeglut.h"

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

struct Color {
	GLfloat r, g, b;
};

struct Vertex {
	GLfloat x, y, z;
};

struct TexCoord {
	GLfloat u, v;
};

struct Mesh {
	Vertex* Vertices;
	Vector3* Normals;
	GLushort* Indices;
	TexCoord* TexCoords;
	int VertexCount, NormalCount, IndexCount, TexCoordsCount;
};

struct Vector4 {
	float x, y, z, w;
};

struct Lighting {
	Vector4 Ambient;
	Vector4 Diffuse;
	Vector4 Specular;
};

struct Material {
	Vector4 Ambient;
	Vector4 Diffuse;
	Vector4 Specular;
	GLfloat Shininess;
};