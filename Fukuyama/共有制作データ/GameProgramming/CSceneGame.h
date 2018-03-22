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
		i_iconShadow.SetVertex(-585, -495, -435, -434);
		i_Icon.SetVertex(-585, -495, -435, -345);
		GameOver.Load("image/bg/GAMEOVER/GAMEOVER.tga");
		Icon.Load("image/under/under_spray_icon.tga");
		Title.Load("image/bg/start/Title.tga");
		
	}

	C_Rectangle i_iconShadow;
	C_Rectangle i_Icon;   //スプレーのアイコン
	CTexture Icon;      //スプレーアイコンのテクスチャー
	CTexture Title;       //タイトルのテクスチャー
	C_Player* Player;
	CTexture GameOver;
	CEnemy* Enemy;
	C_BackGround* BackGround;
	C_Drum* Drum;
	CTexture mTexture;
	CTexture mTexture2;
	int m_EnemyInterval;
	int m_EnemyCount; //フィールド上の敵の数

	int m_PawsCount;
	int GameScene;
	void Init();
	void Update();
	void Draw();
};

#endif