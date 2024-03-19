#include "GLUTHelper.h"

GLUTHelper::GLUTHelper(int argc, char* argv[])
{
	
	rotation = 0.0f;
	GlutCallbacks::Init(this);
	glutInit(&argc, argv);
	glutInitWindowSize(1800, 1800);
	glutCreateWindow("Simple OpenGl Porgram of Doom and TERROR!!!");
	glutDisplayFunc(GlutCallbacks::Display);
	glutTimerFunc(REFRESHRATE, GlutCallbacks::Timer, REFRESHRATE);
	
	glutMainLoop();
	
}

GLUTHelper::~GLUTHelper(void)
{
}

void GLUTHelper::Update()
{
	glutPostRedisplay();
	rotation += 0.5f;

	if (rotation >= 360.0f)
	{
		rotation = 0.0f;
	}

}

void GLUTHelper::Display()
{
	glClear(GL_COLOR_BUFFER_BIT); //this clears the scene
	
	DrawPolygon();

	glFlush(); //flushes the scene drawn to the graphics card

}

void GLUTHelper::DrawPolygon()
{
	glPushMatrix();
	glRotatef(rotation, 0.0f, 0.0f, -1.0f);

	glBegin(GL_POLYGON); //starts to draw a polygon
	{
		glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
		glVertex2f(-0.75, 0.5); //define the first point of the polygon,top left
		glVertex2f(0.75, 0.5); //next point, top right
		glColor4f(1.0f, 0.0f, 1.0f, 0.0f);
		glVertex2f(0.75, -0.5); //bottom right
		glVertex2f(-0.75, -0.5); //last point of the polygon, bottom left
		glEnd(); // defines the end of the draw
	}

	glPopMatrix();
}

