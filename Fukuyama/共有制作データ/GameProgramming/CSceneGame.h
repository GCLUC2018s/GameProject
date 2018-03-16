#ifndef CSCENEGAME_H
#define CSCENEGAME_H

#include"task\CTask.h"
#include"draw\CTexture.h"
#include "chara/C_Player.h"
#include "CBackGround.h"

class CSceneGame :public CTask{
public:
	CSceneGame(){
		Player = new C_Player();
		BackGround = new C_BackGround();
	}
	C_Player* Player;
	C_BackGround* BackGround;
	CTexture mTexture;
	CTexture mTexture2;
	int m_PawsCount;
	int GameScene;
	void Init();
	void Update();
};

#endif