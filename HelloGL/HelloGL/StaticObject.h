#pragma once
#include "SceneObject.h"

class StaticObject : public SceneObject {
public:
	StaticObject(Mesh* mesh, float x, float y, float z);
	~StaticObject();
	void Draw();
	void Update();

	Vector3 _position;
};

