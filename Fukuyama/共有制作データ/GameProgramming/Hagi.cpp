#include"Hagi.h"

<<<<<<< HEAD
void Hagi::Update(){
	C_Player::Update();
}

void Hagi::Draw(){
	C_Player::Draw();
=======
void Hagi::Init(){
	//�v���C���[�̃C���X�^���X���쐬
	Player = new C_Player();
	//������
	Player->Init();
>>>>>>> 9e6ac9599803c436e33464c8b2ecadeed50fff5f
}