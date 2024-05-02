#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL\freeglut.h"
#include "GlutCallbacks.h"
#include <cmath>
#include "Cube.h"
//#define Vector3
//#define Camera

#define NUM_CUBES 100000
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

	//static Vertex vertices[];

	//static Color colors[];

	//static Vertex indexedVertices[];

	//static Color indexedColors[];
	
	//static GLushort indices[];


	Camera* camera;

	Cube* cube[NUM_CUBES];


private:
	float rotation;

};

