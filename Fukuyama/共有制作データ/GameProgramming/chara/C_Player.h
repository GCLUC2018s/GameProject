#ifndef CPLAYER_H
#define CPLAYER_H

#include "scroll.h"

#define PLAYER_SCROLL ((100-SCROLL_PERCENTAGE)/100)*1200

class C_Player :public C_Scroll{
protected:
	C_Player(){
		//ID�ƃv���C�I���e�B��ݒ肵�܂�
		C_Player::CTask(E_PLAYER, eUDP_Player, eDWP_Player);
		//�v���C���[�̃T�C�Y
		//SetVertex(-150,-60,);
	}
public:
	void Update();
};

#endif