#include "GLUTHelper.h"

GLUTHelper::GLUTHelper(int argc, char* argv[])
{
	GlutCallbacks::Init(this);
	glutInit(&argc, argv);
	glutInitWindowSize(1800, 1800);
	glutCreateWindow("Simple OpenGl Porgram of Doom and TERROR!!!");
	glutDisplayFunc(GlutCallbacks::Display);
	glutMainLoop();
}

GLUTHelper::~GLUTHelper(void)
{
}

void GLUTHelper::Display()
{
}
