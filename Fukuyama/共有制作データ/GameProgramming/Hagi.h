#ifndef HAGI_H
#define HAGI_H
#include"task/CTask.h"
#include "chara/C_Player.h"
#include "task/CTaskManager.h"

class Hagi{
public:
	Hagi(){
		//プレイヤーのインスタンスを作成
		Player = new C_Player();
		Test = new C_Test();
	}
	//プレイヤーのインスタンスを宣言します
	C_Test *Test;
	C_Player *Player;
	void Update();
};
#endif