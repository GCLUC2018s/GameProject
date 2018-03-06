#pragma once

#include "glut.h"

#define W_H		1200 //Window��
#define W_V		900 //Window����

class CMain {
	int		mState;
public:
	CMain() : mState(0) {}

	void MainLoop() {
		switch (mState)
		{
		case 0:
			Init();
			mState = 1;
			break;
		default:
			Update();
			break;
		}
	}
	void Init();
	void Update();

};

