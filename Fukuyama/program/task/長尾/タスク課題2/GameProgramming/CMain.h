#pragma once
#include "glut.h"
#include "CPlayer.h"

#define W_H		800 //Window��
#define W_V		600 //Window����

class CMain {
	int		mState;
public:
	//�V�[�����ʎq
	CMain() : mState(0) {}
	//�V�[���ւ̃|�C���^
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

