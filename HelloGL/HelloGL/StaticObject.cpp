#include "StaticObject.h"

StaticObject::StaticObject(Mesh* mesh, float x, float y, float z) : SceneObject(mesh) {
	_position.x = x;
	_position.y = y;
	_position.z = z;
}

StaticObject::~StaticObject() {

}

void StaticObject::Draw() {
	glPushMatrix();

	glTranslatef(_position.x, _position.y, _position.z);

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, _mesh->Vertices);
	glColorPointer(3, GL_FLOAT, 0, _mesh->Colors);

	glPushMatrix();
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_SHORT, _mesh->Indices);
	glPopMatrix();

	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);
	glPopMatrix();
}
void StaticObject::Update() {
}