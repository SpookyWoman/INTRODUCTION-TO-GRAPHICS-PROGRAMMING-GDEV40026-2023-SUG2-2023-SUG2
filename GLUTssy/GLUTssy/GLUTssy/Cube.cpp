#include "Cube.h"
#include <iostream>     // std::cout
#include <fstream>      // std::ifstream

using namespace std;

/*Vertex Cube::vertices[] = {1, 1, 1,  -1, 1, 1,  -1,-1, 1,      // v0-v1-v2 (front)
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

Color Cube::colors[] = { 1, 1, 1,   1, 1, 0,   1, 0, 0,      // v0-v1-v2 (front)
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
				0, 1, 0,   0, 1, 1,   0, 0, 1 };    // v6-v5-v4*/

/*Vertex Cube::indexedVertices[] = {1, 1, 1,  -1, 1, 1,  // v0,v1,
				-1,-1, 1,   1,-1, 1,   // v2,v3
				1,-1,-1,   1, 1,-1,    // v4,v5
				-1, 1,-1,   -1,-1,-1 }; // v6,v7

Color Cube::indexedColors[] = { 1, 1, 1,   1, 1, 0,   // v0,v1,
				1, 0, 0,   1, 0, 1,   // v2,v3
				0, 0, 1,   0, 1, 1,   // v4,v5
				0, 1, 0,   0, 0, 0 }; //v6,v7

GLushort Cube::indices[] = { 0, 1, 2,  2, 3, 0,      // front
				0, 3, 4,  4, 5, 0,      // right
				0, 5, 6,  6, 1, 0,      // top
				1, 6, 7,  7, 2, 1,      // left
				7, 4, 3,  3, 2, 7,      // bottom
				4, 7, 6,  6, 5, 4 };    // back*/

Vertex* Cube::indexedVertices = nullptr;
Color* Cube::indexedColors = nullptr;
GLushort* Cube::indices = nullptr;

int Cube::numVertices = 0;
int Cube::numColors = 0;
int Cube::numIndices = 0;



//float _position.x = x;
//float _position.y = y;
//float _position.z = z;

void Cube::Draw()
{
	glTranslatef(_position.x, _position.y, _position.z);
	glRotatef(_rotation, 0.0f, 1.0f, 0.0f);

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, indexedVertices);
	glColorPointer(3, GL_FLOAT, 0, indexedColors);

	glPushMatrix();
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_SHORT, indices);
	glPopMatrix();

	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);

	/*glPushMatrix();

	glBegin(GL_TRIANGLES);
	for (int i = 0; i < 36; i++)
	{
		glColor3fv(&indexedColors[indices[i]].r);
		glVertex3fv(&indexedVertices[indices[i]].x);
	}*/

	/*if ((indexedVertices != nullptr) && (indexedColors != nullptr) && (indices != nullptr))
	{
		
		glBegin(GL_TRIANGLES);
		for (int i = 0; i < 36; i++)
		{
			glColor3fv(&indexedColors[indices[i]].r);
			//glVertex3f(indexedVertices[i].x, indexedVertices[i].y, indexedVertices[i].z);
			glVertex3fv(&indexedVertices[indices[i]].x);
		}
		glEnd();
	}
	
	glPopMatrix();*/

	

}

bool Cube::Load(char* path)
{
	std::ifstream inFile;
	inFile.open(path);
	if (!inFile.good())
	{
		std::cerr << "Can't open text file " << path << std::endl;
		return false;
	}

	

	

	inFile >> numVertices;
	indexedVertices = new Vertex[numVertices];
	for (int i = 0; i < numVertices; i++)
	{
		//TODO Use inFile to populate the indexedVertices array
		inFile >> indexedVertices[i].x; // etc
		inFile >> indexedVertices[i].y;
		inFile >> indexedVertices[i].z;
	}


	inFile >> numColors;
	//TODO: Load Color information
	indexedColors = new Color[numColors];
	for (int i = 0; i < numColors; i++)
	{
		//TODO Use inFile to populate the indexedColors array
		inFile >> indexedColors[i].r;
		inFile >> indexedColors[i].g;
		inFile >> indexedColors[i].b;// etc
	}
	inFile >> numIndices;
	//TODO: Load Indices information
	indices = new GLushort[numIndices];
	for (int i = 0; i < numIndices; i++)
	{
		//TODO Use inFile to populate the indices array
		inFile >> indices[i]; // etc
	}
	inFile.close();

	return true;
}

void Cube::Update()
{
	_rotation += 0.1f;
}

Cube::Cube(float x, float y, float z)
{
	_position.x =/* (((rand() % 400) / 10.0f) - 20.0f);*/x;
	_position.y = /*(((rand() % 200) / 10.0f) - 10.0f);*/y;
	_position.z = /*(((rand() % 1000) / 10.0f));*/z;
	_rotation = .0f;
}

Cube::~Cube()
{

}

/*void Cube::DrawPolygon()
{
	glPushMatrix();
	glTranslatef(0.0f, 0.0f, -5.0f);
	glRotatef(rotation * 1.5, 1.0f, 0.0f, 0.0f);

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
	}

	glPopMatrix();
}

void Cube::DrawHexagon()
{
	glPushMatrix();
	glTranslatef(0.0f, 0.0f, -5.0f);
	glRotatef(rotation, rotation * 1.0f, rotation * 0.0f, rotation * 0.0f);

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
	}

	glPopMatrix();
}

void Cube::Drawtriangle()
{
	glPushMatrix();
	glTranslatef(0.0f, 0.0f, -5.0f);
	glRotatef(rotation * 99, 1.0f, 0.0f, 0.0f);

	/*glBegin(GL_POLYGON); //starts to draw a polygon
	{
		glColor4f(0.5f, 1.0f, 0.5f, 1.0f);
		glVertex2f(0, 0.5); //define the first point of the polygon,top left
		//glVertex2f(0.75, 0.5); //next point, top right
		glColor4f(0.5f, 0.5f, 1.0f, 1.0f);
		glVertex2f(0.75, -0.5); //bottom right
		glVertex2f(-0.75, -0.5); //last point of the polygon, bottom left
		glEnd(); // defines the end of the draw
	}

	glPopMatrix();
}

void Cube::DrawCube()

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

void Cube::DrawCubeArray()
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
}*/