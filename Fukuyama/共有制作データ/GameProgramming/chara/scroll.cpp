#include "scroll.h"
#include "../CKey.h"

#define PLAYER_SPEED 3     //プレイヤーの移動速度
#define SCROLL_PERCENTAGE 60   //スクロールの基準点（左基準でパーセント換算）
#define SCROLL_POINT W_H/100*SCROLL_PERCENTAGE-(W_H/2)   //スクロールの基準点の横座標

//スクロールの基準点が一定値を超えていたらスクロールする。
void C_Scroll::Scroll(float left,float right){

	//操作用の分（キャラに実装予定）
	/*
	if (CKey::Push(VK_RIGHT)){
		m_Right += PLAYER_SPEED;
		m_Left += PLAYER_SPEED;
	}
	if (CKey::Push(VK_LEFT)){
		m_Right -= PLAYER_SPEED;
		m_Left -= PLAYER_SPEED;
	}
	*/

	//スクロールの基準点が一定値より大きくなるとスクロールする
		if (CKey::Push(VK_RIGHT)){
			right += PLAYER_SPEED;
			left += PLAYER_SPEED;
		}
}