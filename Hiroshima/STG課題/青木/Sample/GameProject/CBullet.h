#pragma once
#ifndef BULLETGURD
#define BULLETGURD



#include "../GameProject/Task/CTask.h"
#include "../GameProject/Task/CTask.h"

//�v���C���[�N���X
class CBullet :public CTask {
public:
	CBullet(CVector2D pos);
	void Update();
	void Draw();
};

#endif // !BULLETGURD