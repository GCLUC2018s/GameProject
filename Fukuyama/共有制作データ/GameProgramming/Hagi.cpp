#include"Hagi.h"

void Hagi::Update(){
	C_Player::Update();
	Test->Update();
	//Test->m_Scroll = Player->m_Scroll;
}

void Hagi::Draw(){
	C_Player::Draw();
	Test->Draw();
}