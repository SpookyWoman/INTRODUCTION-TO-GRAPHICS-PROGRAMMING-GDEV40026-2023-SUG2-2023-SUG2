#pragma once
//#include "GLUTHelper.h"
struct Vector3 {
	float x, y, z;
};

struct Camera {
	Vector3 pos, center, up;
	// camera position is pos
	// center is the target position that the camera is looking at
	//up is up
};

struct Color
{
	GLfloat r, g, b;
};

struct Vertex
{
	GLfloat	x, y, z;
};