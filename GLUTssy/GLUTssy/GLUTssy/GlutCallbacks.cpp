#include "GlutCallbacks.h"
#include "GLUTHelper.h"

namespace GlutCallbacks
{
	namespace
	{

		GLUTHelper* helper = nullptr;

	}

	void Init(GLUTHelper* gl)
	{
		helper = gl;
	}
	void Display()
	{

		if (helper != nullptr)
		{
			helper->Display();
		}
	}

	void Timer(int preferredRefresh)
	{
		int updateTime = glutGet(GLUT_ELAPSED_TIME);
		helper->Update();
		updateTime = glutGet(GLUT_ELAPSED_TIME) - updateTime;
		glutTimerFunc(preferredRefresh - updateTime, GlutCallbacks::Timer, preferredRefresh);
	}

	void Keyboard(unsigned char key, int x, int y)
	{
		helper->Keyboard(key, x, y);
	}
}