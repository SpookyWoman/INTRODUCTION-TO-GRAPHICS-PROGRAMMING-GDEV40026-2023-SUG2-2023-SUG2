#include "GLUTHelper.h"
Vertex GLUTHelper::vertices[] = { 1, 1, 1,  -1, 1, 1,  -1,-1, 1,      // v0-v1-v2 (front)
				-1,-1, 1,   1,-1, 1,   1, 1, 1,      // v2-v3-v0

				1, 1, 1,   1,-1, 1,   1,-1,-1,      // v0-v3-v4 (right)
				1,-1,-1,   1, 1,-1,   1, 1, 1,      // v4-v5-v0

				1, 1, 1,   1, 1,-1,  -1, 1,-1,      // v0-v5-v6 (top)
				-1, 1,-1,  -1, 1, 1,   1, 1, 1,      // v6-v1-v0

				-1, 1, 1,  -1, 1,-1,  -1,-1,-1,      // v1-v6-v7 (left)
				-1,-1,-1,  -1,-1, 1,  -1, 1, 1,      // v7-v2-v1

				-1,-1,-1,   1,-1,-1,   1,-1, 1,      // v7-v4-v3 (bottom)
				1,-1, 1,  -1,-1, 1,  -1,-1,-1,      // v3-v2-v7

				1,-1,-1,  -1,-1,-1,  -1, 1,-1,      // v4-v7-v6 (back)
				-1, 1,-1,   1, 1,-1,   1,-1,-1 };    // v6-v5-v4

Color GLUTHelper::colors[] = { 1, 1, 1,   1, 1, 0,   1, 0, 0,      // v0-v1-v2 (front)
				1, 0, 0,   1, 0, 1,   1, 1, 1,      // v2-v3-v0

				1, 1, 1,   1, 0, 1,   0, 0, 1,      // v0-v3-v4 (right)
				0, 0, 1,   0, 1, 1,   1, 1, 1,      // v4-v5-v0

				1, 1, 1,   0, 1, 1,   0, 1, 0,      // v0-v5-v6 (top)
				0, 1, 0,   1, 1, 0,   1, 1, 1,      // v6-v1-v0

				1, 1, 0,   0, 1, 0,   0, 0, 0,      // v1-v6-v7 (left)
				0, 0, 0,   1, 0, 0,   1, 1, 0,      // v7-v2-v1

				0, 0, 0,   0, 0, 1,   1, 0, 1,      // v7-v4-v3 (bottom)
				1, 0, 1,   1, 0, 0,   0, 0, 0,      // v3-v2-v7

				0, 0, 1,   0, 0, 0,   0, 1, 0,      // v4-v7-v6 (back)
				0, 1, 0,   0, 1, 1,   0, 0, 1 };    // v6-v5-v4

Vertex GLUTHelper::indexedVertices[] = { 1, 1, 1,  -1, 1, 1,  // v0,v1,
				-1,-1, 1,   1,-1, 1,   // v2,v3
				1,-1,-1,   1, 1,-1,    // v4,v5
				-1, 1,-1,   -1,-1,-1 }; // v6,v7

Color GLUTHelper::indexedColors[] = { 1, 1, 1,   1, 1, 0,   // v0,v1,
				1, 0, 0,   1, 0, 1,   // v2,v3
				0, 0, 1,   0, 1, 1,   // v4,v5
				0, 1, 0,   0, 0, 0 }; //v6,v7

GLushort GLUTHelper::indices[] = { 0, 1, 2,  2, 3, 0,      // front
				0, 3, 4,  4, 5, 0,      // right
				0, 5, 6,  6, 1, 0,      // top
				1, 6, 7,  7, 2, 1,      // left
				7, 4, 3,  3, 2, 7,      // bottom
				4, 7, 6,  6, 5, 4 };    // back


GLUTHelper::GLUTHelper(int argc, char* argv[])
{
	
	// this entire section is filled with just defining things for later use elsewhere
	rotation = 0.0f;
	GlutCallbacks::Init(this);
	camera = new Camera();

	//camera->pos.x = 0.0f; camera->pos.y = 0.0f; camera->pos.z = 1.0f;
	camera->pos.x = 5.0f; camera->pos.y = 5.0f; camera->pos.z = -5.0f;
	camera->center.x = 0.0f; camera->center.y = 0.0f; camera->center.z = 0.0f;
	camera->up.x = 0.0f; camera->up.y = 1.0f; camera->up.z = 0.0f;
	float angle = 0;
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);

	
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
	
	//GLUTHelper::DrawPolygon();
	//GLUTHelper::DrawHexagon();
	//GLUTHelper::Drawtriangle();
	//GLUTHelper::DrawCube();
	//GLUTHelper::DrawCubeArray();
	GLUTHelper::DrawIndexedCube();

	glFlush(); //flushes the scene drawn to the graphics card
	glutSwapBuffers();

}

void GLUTHelper::Keyboard(unsigned char key, int x, int y)
{

	if (key == 'd')
	{
		camera->pos.x -= 0.1f;
		//camera->pos.y -= 0.1f;
		//angle -= 0.1f;
	}

	if (key == 'a')
	{
		camera->pos.x += 0.1f;
		//camera->pos.y += 0.1f;
		//angle += 0.1f;
	}

	if (key == 'w')
	{
		camera->pos.y -= 0.1f;
		//camera->pos.y += 0.1f;
		//angle -= 0.1f;
	}

	if (key == 's')
	{
		camera->pos.y += 0.1f;
		//camera->pos.y -= 0.1f;
		//angle -= 0.1f;
	}
	//camera->center.x = camera->pos.x + cos(angle);
	//camera->center.y = camera->pos.y + sin(angle);
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

void GLUTHelper::DrawCube()

{

	glBegin(GL_TRIANGLES);

	// face v0-v1-v2

	glColor3f(1, 1, 1);

	glVertex3f(1, 1, 1);

	glColor3f(1, 1, 0);

	glVertex3f(-1, 1, 1);

	glColor3f(1, 0, 0);

	glVertex3f(-1, -1, 1);

	// face v2-v3-v0

	glColor3f(1, 0, 0);

	glVertex3f(-1, -1, 1);

	glColor3f(1, 0, 1);

	glVertex3f(1, -1, 1);

	glColor3f(1, 1, 1);

	glVertex3f(1, 1, 1);

	// face v0-v3-v4

	glColor3f(1, 1, 1);

	glVertex3f(1, 1, 1);

	glColor3f(1, 0, 1);

	glVertex3f(1, -1, 1);

	glColor3f(0, 0, 1);

	glVertex3f(1, -1, -1);

	// face v4-v5-v0

	glColor3f(0, 0, 1);

	glVertex3f(1, -1, -1);

	glColor3f(0, 1, 1);

	glVertex3f(1, 1, -1);

	glColor3f(1, 1, 1);

	glVertex3f(1, 1, 1);

	// face v0-v5-v6

	glColor3f(1, 1, 1);

	glVertex3f(1, 1, 1);

	glColor3f(0, 1, 1);

	glVertex3f(1, 1, -1);

	glColor3f(0, 1, 0);

	glVertex3f(-1, 1, -1);

	// face v6-v1-v0

	glColor3f(0, 1, 0);

	glVertex3f(-1, 1, -1);

	glColor3f(1, 1, 0);

	glVertex3f(-1, 1, 1);

	glColor3f(1, 1, 1);

	glVertex3f(1, 1, 1);

	// face v1-v6-v7

	glColor3f(1, 1, 0);

	glVertex3f(-1, 1, 1);

	glColor3f(0, 1, 0);

	glVertex3f(-1, 1, -1);

	glColor3f(0, 0, 0);

	glVertex3f(-1, -1, -1);

	// face v7-v2-v1

	glColor3f(0, 0, 0);

	glVertex3f(-1, -1, -1);

	glColor3f(1, 0, 0);

	glVertex3f(-1, -1, 1);

	glColor3f(1, 1, 0);

	glVertex3f(-1, 1, 1);

	// face v7-v4-v3

	glColor3f(0, 0, 0);

	glVertex3f(-1, -1, -1);

	glColor3f(0, 0, 1);

	glVertex3f(1, -1, -1);

	glColor3f(1, 0, 1);

	glVertex3f(1, -1, 1);

	// face v3-v2-v7

	glColor3f(1, 0, 1);

	glVertex3f(1, -1, 1);

	glColor3f(1, 0, 0);

	glVertex3f(-1, -1, 1);

	glColor3f(0, 0, 0);

	glVertex3f(-1, -1, -1);

	// face v4-v7-v6

	glColor3f(0, 0, 1);

	glVertex3f(1, -1, -1);

	glColor3f(0, 0, 0);

	glVertex3f(-1, -1, -1);

	glColor3f(0, 1, 0);

	glVertex3f(-1, 1, -1);

	// face v6-v5-v4

	glColor3f(0, 1, 0);

	glVertex3f(-1, 1, -1);

	glColor3f(0, 1, 1);

	glVertex3f(1, 1, -1);

	glColor3f(0, 0, 1);

	glVertex3f(1, -1, -1);

	glEnd();

}

void GLUTHelper::DrawCubeArray()
{
	glPushMatrix();

	glBegin(GL_TRIANGLES);
	for (int i = 0; i < 36; i++)
	{
		//draw code here

		glColor3fv(&colors[i].r);
		glVertex3fv(&vertices[i].x);

	}
	glEnd();

	glPopMatrix();
}

void GLUTHelper::DrawIndexedCube()
{
	glPushMatrix();

	glBegin(GL_TRIANGLES);
	for (int i = 0; i < 36; i++)
	{
		glColor3fv(&indexedColors[indices[i]].r);
		glVertex3fv(&indexedVertices[indices[i]].x);
	}
	glEnd();

	glPopMatrix();

}
