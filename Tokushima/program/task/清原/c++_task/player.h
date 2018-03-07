#ifndef PLAYER_H
#define PLAYER_H

#include "task.h"

class Player :public Task{
	virtual void update();
};

#endif PLAYER_H