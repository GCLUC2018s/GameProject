#ifndef HAGI_H
#define HAGI_H
#include"task/CTask.h"
#include "chara/C_Player.h"
#include "task/CTaskManager.h"

class Hagi :public C_Player{
public:
	Hagi(){
		//�v���C���[�̃C���X�^���X���쐬
		Player = new C_Player();
	}
	//�v���C���[�̃C���X�^���X��錾���܂�
	C_Player *Player;
	void Update();
	void Draw();
};
#endif