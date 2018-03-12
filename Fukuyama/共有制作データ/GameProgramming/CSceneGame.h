#ifndef CSCENEGAME_H
#define CSCENEGAME_H
#include"task/CTask.h"
#include "draw\CTexture.h"
#include "windows.h"
class CSceneGame :public CTask{
public:
	int GameScene;
	int m_PawsCount;
	CTexture mTexture;
	CTexture mTexture2;
	void Init();
	void Update();
};
#endif