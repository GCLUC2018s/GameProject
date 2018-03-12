#ifndef CPLAYER_H
#define CPLAYER_H

#include "scroll.h"

#define PLAYER_SCROLL ((100-SCROLL_PERCENTAGE)/100)*1200

class C_Player :public C_Scroll{
protected:
	C_Player(){
		//IDとプライオリティを設定します
		C_Player::CTask(E_PLAYER, eUDP_Player, eDWP_Player);
		//プレイヤーのサイズ
		//SetVertex(-150,-60,);
	}
public:
	void Update();
};

#endif