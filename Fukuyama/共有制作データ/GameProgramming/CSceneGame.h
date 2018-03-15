#ifndef CSCENEGAME_H
#define CSCENEGAME_H

#include"task\CTask.h"
#include"draw\CTexture.h"
#include "chara/C_Player.h"

class CSceneGame :public CTask{
public:
	CSceneGame(){
		Player = new C_Player();
	}
	C_Player* Player;
	CTexture mTexture;
	CTexture mTexture2;
	int m_PawsCount;
	int GameScene;
	void Init();
	void Update();
};

#endif