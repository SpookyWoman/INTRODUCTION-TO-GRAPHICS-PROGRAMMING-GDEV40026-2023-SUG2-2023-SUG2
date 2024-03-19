#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL\freeglut.h"
#include "GlutCallbacks.h"

class GLUTHelper
{
public:
	GLUTHelper(int argc, char* argv[]);

	~GLUTHelper(void);

	void Display();

};

