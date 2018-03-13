#include"Hagi.h"

<<<<<<< HEAD
void Hagi::Update(){
	C_Player::Update();
}

void Hagi::Draw(){
	C_Player::Draw();
=======
void Hagi::Init(){
	//プレイヤーのインスタンスを作成
	Player = new C_Player();
	//初期化
	Player->Init();
>>>>>>> 9e6ac9599803c436e33464c8b2ecadeed50fff5f
}