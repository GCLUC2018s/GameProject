#ifndef HAGI_H
#define HAGI_H
#include"task/CTask.h"
#include "task/CTaskManager.h"
#include "chara/C_Player.h"

class Hagi :public C_Player{
public:
	//�v���C���[�̃C���X�^���X��錾���܂�
	C_Player *Player;
	void Init();
	void Update();
	void Draw();
};
#endif