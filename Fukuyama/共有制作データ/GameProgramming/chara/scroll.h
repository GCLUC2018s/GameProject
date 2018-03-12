#ifndef SCROLL_H
#define SCROLL_H

#include "../draw/CRectangle.h"

#define PLAYER_SPEED 3     //プレイヤーの移動速度
#define SCROLL_PERCENTAGE 60   //スクロールの基準点（左基準でパーセント換算）
#define SCROLL_POINT W_H/100*SCROLL_PERCENTAGE-(W_H/2)   //スクロールの基準点の横座標

class C_Scroll :public C_Rectangle{
protected:
	C_Scroll(){
		//ID,
		C_Scroll::CTask(E_SCROLL, eUDP_Camera, eDWP_Map);
		//スクロールの基準点を作成します
		SetVertex(0, 1, 0, 1);
	};
public:
	C_Scroll* pm_scroll;
	void Scroll(float left,float right);
};

#endif