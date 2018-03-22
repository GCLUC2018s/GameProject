#ifndef CSCENEGAME_H
#define CSCENEGAME_H

#include"task\CTask.h"
#include"draw\CTexture.h"
#include "chara/C_Player.h"
#include "CBackGround.h"
#include "object\CManhole.h"
#include "object\CDrum.h"
#include"CEnemy.h"

class CSceneGame :public CTask{
public:
	CSceneGame(){
		Drum = new C_Drum();
		Manhole = new C_Manhole();
		Player = new C_Player();
		Enemy = new CEnemy();
		Enemy->Init();
		BackGround = new C_BackGround();
		i_iconShadow.SetVertex(-585, -495, -435, -434);
		i_Icon.SetVertex(-585, -495, -435, -345);
		Icon.Load("image/under/under_spray_icon.tga");
	}

	C_Rectangle i_iconShadow;
	C_Rectangle i_Icon;   //スプレーのアイコン
	CTexture Icon;      //スプレーアイコンのテクスチャー
	C_Player* Player;
	CEnemy* Enemy;
	C_BackGround* BackGround;
	C_Manhole* Manhole;
	C_Drum* Drum;
	CTexture mTexture;
	CTexture mTexture2;
	int m_PawsCount;
	int GameScene;
	void Init();
	void Update();
	void Draw();
};

#endif