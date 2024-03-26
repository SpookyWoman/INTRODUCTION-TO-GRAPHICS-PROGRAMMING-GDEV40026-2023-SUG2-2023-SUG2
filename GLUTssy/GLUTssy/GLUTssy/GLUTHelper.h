#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL\freeglut.h"
#include "GlutCallbacks.h"
//#define Vector3
//#define Camera

struct Vector3 {
	float x, y, z;
};

struct Camera {
	Vector3 eye, center, up;
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

	Camera* camera;


private:
	float rotation;

};

