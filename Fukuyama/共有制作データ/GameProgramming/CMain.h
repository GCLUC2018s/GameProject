#pragma once

#include "glut.h"
#include"Nagao.h"
#include"Hagi.h"
#include"Hako.h"
#include"CSceneGame.h"
#define W_H		1200 //Windowïù
#define W_V		900 //WindowçÇÇ≥

class CMain {
public:
	int mState;
	int m_Mode;
	int SceneState;
	Nagao *ip_Nagao;
	Hagi *ip_Hagi;
	Hako *ip_Hako;
	CSceneGame *ip_SceneGame;
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

