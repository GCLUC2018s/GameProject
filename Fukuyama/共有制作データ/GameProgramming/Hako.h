#ifndef HAKO_H
#define HAKO_H

#include"task\CTask.h"
#include"draw\CTexture.h"
#include "chara/C_Player.h"
#include"CEnemy.h"

class Hako :public CTask{
public:
	Hako(){
		Player = new C_Player();
	}
	CEnemy *Enemy;
	C_Player* Player;
	CTexture mTexture;
	CTexture mTexture2;
	//int m_EnemyInterval;
	//int m_EnemyCount; //フィールド上の敵の数
	int m_Paws;
	int GameScene;
	void Init();
	void Update();
};

#endif