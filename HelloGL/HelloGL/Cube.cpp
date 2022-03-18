#include "Cube.h"


Cube::Cube(Mesh* mesh, Texture2D* texture, float x, float y, float z) : SceneObject(mesh, texture)
{
	_rotation = 0.0f;
	_mesh = mesh;
	_texture = texture;
	_position.x = x;
	_position.y = y;
	_position.z = z;
}

Cube::~Cube() 
{

}

void Cube::Draw() 
{
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

void Cube::Update() 
{
	_rotation += 0.1f;
}

void Cube::SetRotation(float Rotation) 
{

}

//bool Cube::Load(char* path) {
//	std::ifstream inFile;
//	inFile.open(path);
//	if (!inFile.good()) {
//		std::cerr << "Cant open text file" << path << std::endl;
//		return false;
//	}
//
//	inFile >> numVertices;
//	indexedVertices = new Vertex[numVertices]; 
//	for (int i = 0; i < numVertices; i++){
//		inFile >> indexedVertices[i].x;
//		inFile >> indexedVertices[i].y;
//		inFile >> indexedVertices[i].z;
//	}
//
//	inFile >> numColors;
//	indexedColors = new Color[numColors];
//	for (int i = 0; i < numColors; i++) {
//		inFile >> indexedColors[i].r;
//		inFile >> indexedColors[i].g;
//		inFile >> indexedColors[i].b;
//	}
//
//	inFile >> numIndices;
//	indices = new GLushort[numIndices];
//	for (int i = 0; i < numIndices; i++){
//		inFile >> indices[i];
//	}
//
//	inFile.close();
//	return true;
//}