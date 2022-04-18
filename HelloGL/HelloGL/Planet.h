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
		float _orbit;
		float _speed;
		int _distanceFromTheSun;
		double angleOfRotation;
		Vector3 _position;
		GLfloat _rotation;
		Material* _material;
		int _time;

	public:
		Planet(Mesh* mesh, Texture2D* texture, std::string name, int size, int x, int y, int z, int orbit, int sundistance);
		~Planet();
		void Draw();
		void Update();
		void PlanetOrbit();
		void SetRotation(float Rotation);
		void SetMaterial();
		int GetSize() { return _size; };
		void GetSpeed();
		
};

