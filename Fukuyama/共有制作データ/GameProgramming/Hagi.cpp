#include"Hagi.h"

void Hagi::Init(){
	//プレイヤーのインスタンスを作成
	Player = new C_Player();
	//Player->CTask::CTask(E_PLAYER, eUDP_Player, eDWP_Player);
	Player->Init();
	CTaskManager::GetInstance()->Add((CTask*)Player);
}

void Hagi::Update(){
	C_Player::Update();
}

void Hagi::Draw(){
	C_Player::Draw();
}