#ifndef PLAYER_GUARD
#define PLAYER_GUARD

#include"../GameProject/Task/CTask.h"

class CPlayer :public CTask {
public:
	CPlayer();
	void Update();
};

#endif//PLAYER_GUARD