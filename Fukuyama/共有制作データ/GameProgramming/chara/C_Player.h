#ifndef CPLAYER_H
#define CPLAYER_H

#include "../draw/CRectangle.h"
<<<<<<< HEAD
#include "../draw/scroll.h"
#include <stdio.h>

#define PLAYER_LR_SPEED SCROLL_SPEED     //プレイヤーの左右移動速度
#define PLAYER_UD_SPEED 5     //プレイヤーの上下移動速度

class C_Player :public C_Rectangle{
public:
	C_Player() :C_Rectangle(E_PLAYER, eUDP_Player, eDWP_Player)
	{
		m_Enabled = true;
		//アニメーションカウンタの初期化
		m_Anime = 0;
		m_Anime_s = 0;
		//プレイヤーのサイズ
		SetVertex(0, 90, 0, 135);
		//キャラクターアニメーション画像の読み込み
		i_Chara_Motion_1.Load("image/chara/chara_motion_1.tga");
		i_Chara_Motion_2.Load("image/chara/chara_motion_2_16bit.tga");
		printf("%f\n%f\n%f\n%f\n", m_Left, m_Right, m_Bottom, m_Top);
		m_Turn = E_RIGHT;
	}
=======

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

>>>>>>> 9e6ac9599803c436e33464c8b2ecadeed50fff5f
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
<<<<<<< HEAD
	virtual void Update();
	virtual void Draw();
=======
	void Init();
	void Update();
	void Draw();
>>>>>>> 9e6ac9599803c436e33464c8b2ecadeed50fff5f
};

#endif