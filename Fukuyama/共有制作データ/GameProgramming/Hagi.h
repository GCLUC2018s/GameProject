#ifndef HAGI_H
#define HAGI_H
#include"task/CTask.h"
#include "chara/C_Player.h"

class Hagi :public CTask{
public:
	//プレイヤーのインスタンスを宣言します
	C_Player *Player;
	void Init();
};
#endif