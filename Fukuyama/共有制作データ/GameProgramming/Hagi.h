#ifndef HAGI_H
#define HAGI_H
#include"task/CTask.h"
#include "chara/C_Player.h"

class Hagi :public CTask{
public:
	Hagi(){
		//�v���C���[�̃C���X�^���X���쐬
		Player = new C_Player();
	}
	//�v���C���[�̃C���X�^���X��錾���܂�
	C_Player *Player;
<<<<<<< HEAD
	void Update();
	void Draw();
=======
	void Init();
>>>>>>> 9e6ac9599803c436e33464c8b2ecadeed50fff5f
};
#endif