#ifndef CPLAYER_H
#define CPLAYER_H

#include "scroll.h"

class C_Player :public C_Scroll{
protected:
	C_Player(){
		C_Player::CTask(E_PLAYER, eUDP_Player, eDWP_Player);
	}
public:
	void Update();
};

#endif