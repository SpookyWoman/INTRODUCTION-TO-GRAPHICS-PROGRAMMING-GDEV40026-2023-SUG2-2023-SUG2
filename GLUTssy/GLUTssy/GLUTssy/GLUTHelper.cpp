#include "GLUTHelper.h"

GLUTHelper::GLUTHelper(int argc, char* argv[])
{
	
	// this entire section is filled with just defining things for later use elsewhere
	rotation = 0.0f;
	GlutCallbacks::Init(this);
	camera = new Camera();

	camera->pos.x = 0.0f; camera->pos.y = 0.0f; camera->pos.z = 1.0f;
	camera->center.x = 0.0f; camera->center.y = 0.0f; camera->center.z = 0.0f;
	camera->up.x = 0.0f; camera->up.y = 1.0f; camera->up.z = 0.0f;
	float angle = 0;

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowSize(800, 800);
	glutCreateWindow("Simple OpenGl Porgram of Doom and TERROR!!!");
	glutDisplayFunc(GlutCallbacks::Display);
	glutTimerFunc(REFRESHRATE, GlutCallbacks::Timer, REFRESHRATE);
	glutKeyboardFunc(GlutCallbacks::Keyboard);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, 800, 800);
	gluPerspective(45, 1, 0, 1000);
	glMatrixMode(GL_MODELVIEW);
	glutMainLoop();
	
}

GLUTHelper::~GLUTHelper(void)
{
}

void GLUTHelper::Update()
{
	glLoadIdentity();
	gluLookAt(camera->pos.x, camera->pos.y, camera->pos.z, camera->center.x, camera->center.y, camera->center.z, camera->up.x, camera->up.y, camera->up.z);
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
	
	GLUTHelper::DrawPolygon();
	GLUTHelper::DrawHexagon();
	GLUTHelper::Drawtriangle();

	glFlush(); //flushes the scene drawn to the graphics card
	glutSwapBuffers();

}

void GLUTHelper::Keyboard(unsigned char key, int x, int y)
{

	if (key == 'd')
	{
		//camera->pos.x -= 0.1f;
		angle -= 0.1f;
	}

	if (key == 'a')
	{
		//camera->pos.x += 0.1f;
		angle += 0.1f;
	}
	camera->center.x = camera->pos.x + cos(angle);
	camera->center.y = camera->pos.y + sin(angle);
}

void GLUTHelper::DrawPolygon()
{
	glPushMatrix();
	glTranslatef(0.0f, 0.0f, -5.0f);
	glRotatef(rotation*1.5, 1.0f, 0.0f, 0.0f);

	glutWireDodecahedron();
	/*glBegin(GL_POLYGON); //starts to draw a polygon
	{
		glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
		glVertex2f(-0.75, 0.5); //define the first point of the polygon,top left
		glVertex2f(0.75, 0.5); //next point, top right
		glColor4f(1.0f, 0.0f, 1.0f, 0.0f);
		glVertex2f(0.75, -0.5); //bottom right
		glVertex2f(-0.75, -0.5); //last point of the polygon, bottom left

		glEnd(); // defines the end of the draw
	}*/

	glPopMatrix();
}

void GLUTHelper::DrawHexagon()
{
	glPushMatrix();
	glTranslatef(0.0f, 0.0f, -5.0f);
	glRotatef(rotation, rotation*1.0f, rotation * 0.0f, rotation * 0.0f);

	/*glBegin(GL_POLYGON); //starts to draw a polygon
	{
		glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
		glVertex2f(-0.75, 0.5); //define the first point of the polygon,top left
		glVertex2f(0.75, 0.5); //next point, top right
		glVertex2f(1, 0); //bottom right
		glColor4f(0.0f, 1.0f, 1.0f, 0.0f);
		glVertex2f(0.75, -0.5); //last point of the polygon, bottom left
		glVertex2f(-0.75, -0.5);
		glVertex2f(-1, 0);
		glEnd(); // defines the end of the draw
	}*/

	glPopMatrix();
}

void GLUTHelper::Drawtriangle()
{
	glPushMatrix();
	glTranslatef(0.0f, 0.0f, -5.0f);
	glRotatef(rotation*99, 1.0f, 0.0f, 0.0f);

	/*glBegin(GL_POLYGON); //starts to draw a polygon
	{
		glColor4f(0.5f, 1.0f, 0.5f, 1.0f);
		glVertex2f(0, 0.5); //define the first point of the polygon,top left
		//glVertex2f(0.75, 0.5); //next point, top right
		glColor4f(0.5f, 0.5f, 1.0f, 1.0f);
		glVertex2f(0.75, -0.5); //bottom right
		glVertex2f(-0.75, -0.5); //last point of the polygon, bottom left
		glEnd(); // defines the end of the draw
	}*/

	glPopMatrix();
}

