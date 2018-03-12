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
		//キャラクターアニメーション画像の読み込み
		i_Chara_Motion_1.Load("../image/chara_motion_1.tga");
		i_Chara_Motion_2.Load("../image/chara_motion_2.tga");
		//IDとプライオリティを設定します
		C_Player::CTask(E_PLAYER, eUDP_Player, eDWP_Player);
		//プレイヤーのサイズ
		SetVertex(PLAYER_START_LEFT, PLAYER_START_RIGHT, PLAYER_START_BOTTOM, PLAYER_START_TOP);
		//プレイヤーの初期向き
		m_Turn = E_RIGHT;
	}
public:
	enum TURN_TAG{
		E_RIGHT,
		E_LEFT,
	};

	CTexture i_Chara_Motion_1;
	CTexture i_Chara_Motion_2;
	int m_Anime;            //アニメーション管理変数
	int m_Anime_s;          //アニメーション秒数管理
	int m_Anime_Taiki;      //アニメーション管理変数
	int m_Anime_Taiki_s;    //アニメーション秒数管理(待機)
	int m_Turn;             //右を向いているか左を向いているか
	void Init();
	void Update();
	void Draw();
};

#endif