#pragma once

#include "glut.h"
<<<<<<< HEAD
#include"Nagao.h"
#include"Hagi.h"
#include"Hako.h"
#include"CSceneGame.h"
=======
#include"draw/CTexture.h"
#define W_H		1200 //Window•
#define W_V		900 //Window‚‚³
>>>>>>> 189d1420510f60b31020b8a715577dba1d0dd30f

class CMain {
	int		mState;
	int GameScene;
	int m_Mode;
	int m_PawsCount;
public:
	CTexture mTexture;
	CTexture mTexture2;
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

