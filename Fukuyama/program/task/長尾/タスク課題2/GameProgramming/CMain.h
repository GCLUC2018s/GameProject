#pragma once
#include "glut.h"
#include "CPlayer.h"

#define W_H		800 //Window幅
#define W_V		600 //Window高さ

class CMain {
	int		mState;
public:
	//シーン識別子
	CMain() : mState(0) {}
	//シーンへのポインタ
	~CMain(){
	}
	CPlayer *mPlayer;
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

