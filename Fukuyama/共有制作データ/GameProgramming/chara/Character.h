#ifndef CHARACTER_H
#define CHARACTER_H

#include "scroll.h"

class C_Character :public C_Scroll{
protected:
	C_Character(){
		//ID,
		C_Character::CTask(E_SCROLL, eUDP_Camera, eDWP_Map);
		//スクロールの基準点を作成します
		SetVertex(0, 1, 0, 1);
	}
public:
	C_Character* mp_Collision;
};

#endif