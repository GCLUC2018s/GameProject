#ifndef HAGI_H
#define HAGI_H
#include"task/CTask.h"
#include "chara/C_Player.h"
#include "task/CTaskManager.h"

class Hagi :public C_Player{
public:
	Hagi(){
		//プレイヤーのインスタンスを作成
		Player = new C_Player();
	}
	//プレイヤーのインスタンスを宣言します
	C_Player *Player;
	void Update();
	void Draw();
};
#endif