#include"Hagi.h"

void Hagi::Init(){
	//プレイヤーのインスタンスを作成
	Player = new C_Player();
	//初期化
	Player->Init();
}