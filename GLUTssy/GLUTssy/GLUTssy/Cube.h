#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL\freeglut.h"
#include "Structures.h"

class Cube
{
private:
	static Vertex* indexedVertices;
	static Color* indexedColors;
	static GLushort* indices;
	Vector3 _position;
	


public:
	Cube();
	~Cube();

	void Draw();
	void Update();

	static int numVertices, numColors, numIndices;
	static bool Load(char* path);

	GLfloat _rotation;
};
