#pragma once
#ifndef PLAYERGURD
#define PLAYERGURD



#include "../GameProject/Task/CTask.h"
#include "../GameProject/Task/CTask.h"

//�v���C���[�N���X
class CPlayer :public CTask {
public:
	CPlayer();
	void Update();
	void Draw();
};

#endif // !PLAYERGURD