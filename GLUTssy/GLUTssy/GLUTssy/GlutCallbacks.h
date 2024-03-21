#pragma once
class GLUTHelper;

namespace GlutCallbacks
{
	void Init(GLUTHelper* gl);

	void Display();

	void Timer(int preferredRefresh);

	void Keyboard(unsigned char key, int x, int y);
};

