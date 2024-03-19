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
}