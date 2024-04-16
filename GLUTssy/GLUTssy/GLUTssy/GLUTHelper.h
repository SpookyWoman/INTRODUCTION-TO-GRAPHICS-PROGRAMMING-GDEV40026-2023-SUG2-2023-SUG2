#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL\freeglut.h"
#include "GlutCallbacks.h"
#include <cmath>
//#define Vector3
//#define Camera

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

#define REFRESHRATE 16

class GLUTHelper
{
public:
	GLUTHelper(int argc, char* argv[]);

	~GLUTHelper(void);

	void Display();

	void DrawPolygon();

	void Drawtriangle();

	void DrawHexagon();

	void Update();

	void Keyboard(unsigned char key, int x, int y);

	void DrawCube();

	void DrawCubeArray();

	void DrawIndexedCube();

	static Vertex vertices[];

	static Color colors[];

	static Vertex indexedVertices[];

	static Color indexedColors[];
	
	static GLushort indices[];


	Camera* camera;


private:
	float rotation;

};

