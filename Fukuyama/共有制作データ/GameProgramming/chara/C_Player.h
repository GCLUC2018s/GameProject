#ifndef CPLAYER_H
#define CPLAYER_H

#include "scroll.h"

#define PLAYER_SCROLL ((100-SCROLL_PERCENTAGE)/100)*1200    //プレイヤーとスクロール基準点の距離
#define PLAYER_START_BOTTOM -135               //プレイヤーの初期位置（下）←上下位置調整は下のみ変更してください。
#define PLAYER_START_TOP (PLAYER_START_BOTTOM+135)          //プレイヤーの初期位置（上）
#define PLAYER_START_RIGHT (-PLAYER_SCROLL)          //プレイヤーの初期位置（右）
#define PLAYER_START_LEFT (PLAYER_START_RIGHT-90)       //プレイヤーの初期位置（左）

class C_Player :public C_Scroll{
protected:
	C_Player(){

		//IDとプライオリティを設定します
		C_Player::CTask(E_PLAYER, eUDP_Player, eDWP_Player);
		//プレイヤーのサイズ
		SetVertex(PLAYER_START_LEFT, PLAYER_START_RIGHT, PLAYER_START_BOTTOM, PLAYER_START_TOP);
	}
public:
	void Update();
	void Draw();
};

#endif