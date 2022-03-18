#include "GLUTCallbacks.h"
#include "HelloGL.h"
#include <iostream>

namespace GLUTCallbacks {
	namespace {
		HelloGL* helloGL = nullptr;
	}

	void Init(HelloGL* gl) {
		helloGL = gl;
	}

	void Display() {
		if (helloGL != nullptr) {
			helloGL->Display();
		}
	}

	void Timer(int preferredRefresh) {
		int updateTime = glutGet(GLUT_ELAPSED_TIME);
		helloGL->Update(); 
		updateTime = glutGet(GLUT_ELAPSED_TIME) - updateTime; // working out how long it takes update to run to fix fps to 60
		glutTimerFunc(preferredRefresh - updateTime, GLUTCallbacks::Timer, preferredRefresh);
	}

	void Keyboard(unsigned char key, int x, int y) {
		helloGL->Keyboard(key, x, y);
	}
}