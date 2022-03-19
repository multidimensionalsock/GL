#include "Planet.h"


Planet::Planet(Mesh* mesh, Texture2D* texture, std::string name, int size, int x, int y, int z, int orbit, int sundistance) : SceneObject(mesh, texture)
{
	_mesh = mesh;
	_texture = texture;
	_name = name;
	_size = size;
	_position.x = x;
	_position.y = y;
	_position.z = z;
	_rotation = 0.5f;
	_factLocation = nullptr;
	_orbit = orbit;
	_distanceFromTheSun = sundistance;
	GetSpeed();
	SetMaterial();
}

Planet::~Planet() 
{

}

void Planet::Draw()
{
	SetMaterial();
	glMaterialfv(GL_FRONT, GL_AMBIENT, &(_material->Ambient.x));
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, _texture->GetID());
	glTranslatef(_position.x, _position.y, _position.z);
	glRotatef(_rotation, 1.0f, 0.0f, 0.0f);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);
	glTexCoordPointer(2, GL_FLOAT, 0, _mesh->TexCoords);
	glVertexPointer(3, GL_FLOAT, 0, _mesh->Vertices);
	glNormalPointer(GL_FLOAT, 0, _mesh->Normals);

	glPushMatrix();
	glDrawElements(GL_TRIANGLES, _mesh->IndexCount, GL_UNSIGNED_SHORT, _mesh->Indices);
	glPopMatrix();

	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);
}

void Planet::Update()
{
	_rotation += 0.1f;
	glMaterialf(GL_FRONT, GL_SHININESS, _material->Shininess);
}

void Planet::SetRotation(float Rotation)
{

}

void Planet::SetMaterial()
{
	_material = new Material();
	_material->Ambient.x = 0.8; _material->Ambient.y = 0.05; _material->Ambient.z = 0.05; _material->Ambient.w = 1.0;
	_material->Diffuse.x = 0.8; _material->Diffuse.y = 0.05; _material->Diffuse.z = 0.05; _material->Diffuse.w = 1.0;
	_material->Specular.x = 1.0; _material->Specular.y = 1.0; _material->Specular.z = 1.0; _material->Specular.w = 1.0;
	_material->Shininess = 100.0f;
}

void Planet::GetSpeed()
{
	int r = _distanceFromTheSun;
	float c = 2 * 3.1415 * r;
	float day = c / _orbit;
	float hour = day / 24;
	int minute = hour / 60;
	_speed = minute;
}