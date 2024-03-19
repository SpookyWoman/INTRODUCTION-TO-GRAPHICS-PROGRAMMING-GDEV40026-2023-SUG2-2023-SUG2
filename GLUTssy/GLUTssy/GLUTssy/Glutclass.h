#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL\freeglut.h"
#include "GlutCallbacks.h"

class Glutclass
{
public:
	Glutclass(int argc, char* argv[]);

	~Glutclass(void);

	void Display();
};