#ifndef HAGI_H
#define HAGI_H
#include"task/CTask.h"
#include "chara/C_Player.h"
#include "task/CTaskManager.h"

class Hagi{
public:
	Hagi(){
		//�v���C���[�̃C���X�^���X���쐬
		Player = new C_Player();
		Test = new C_Test();
	}
	//�v���C���[�̃C���X�^���X��錾���܂�
	C_Test *Test;
	C_Player *Player;
	void Update();
};
#endif