#ifndef CPLAYER_H
#define CPLAYER_H

#include "scroll.h"

class C_Player :public C_Rectangle{
public:
	C_Player(){
		//キャラクターアニメーション画像の読み込み
		i_Chara_Motion_1.Load("../image/chara_motion_1.tga");
		i_Chara_Motion_2.Load("../image/chara_motion_2.tga");
		//IDとプライオリティを設定します
		C_Player::CTask(E_SCROLL, eUDP_Player, eDWP_Player);
		//プレイヤーの初期向き
		m_Turn = E_RIGHT;
	}

	//プレイヤーの向きフラグ
	enum TURN_TAG{
		E_RIGHT,
		E_LEFT,
	};

	//テクスチャーのインスタンス宣言
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