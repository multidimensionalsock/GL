#pragma once
#include "GLUTCallbacks.h"
#include "Structures.h"
#include <iostream>
#include <fstream>
#include <string>
#include "SceneObject.h"

class Planet : public SceneObject 
{
	private:
		std::string _name;
		int _size;
		std::string** _factLocation; //set to null
		int _orbit;
		int _speed;
		int _distanceFromTheSun;
		float angleOfRotation;
		Vector3 _position;
		GLfloat _rotation;
		Material* _material;
		int div;

	public:
		Planet(Mesh* mesh, Texture2D* texture, std::string name, int size, int x, int y, int z, int orbit, int sundistance);
		~Planet();
		void Draw();
		void Update();
		void SetRotation(float Rotation);
		void SetMaterial();
		int GetSize() { return _size; };
		void GetSpeed();
		void PlanetOrbit();
};

