#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL\freeglut.h"
#include "GlutCallbacks.h"
#define REFRESHRATE 16

class GLUTHelper
{
public:
	GLUTHelper(int argc, char* argv[]);

	~GLUTHelper(void);

	void Display();

	void DrawPolygon();

	void Update();

private:
	float rotation;

};

