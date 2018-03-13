#ifndef CSCENEGAME_H
#define CSCENEGAME_H

#include"task\CTask.h"
#include"draw\CTexture.h"
class CSceneGame :public CTask{
public:
	CTexture mTexture;
	CTexture mTexture2;
	int m_PawsCount;
	int GameScene;
	void Init();
	void Update();
};

#endif