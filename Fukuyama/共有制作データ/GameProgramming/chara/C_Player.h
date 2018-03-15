#ifndef CPLAYER_H
#define CPLAYER_H

#include "../draw/scroll.h"
#include <stdio.h>
#include "../object/C_Object.h"

#define PLAYER_LR_SPEED SCROLL_SPEED     //プレイヤーの左右移動速度
#define PLAYER_UD_SPEED 5     //プレイヤーの上下移動速度

class C_Player :public C_Object{
public:
	C_Player() 
		:C_Object(E_PLAYER, eUDP_Player, eDWP_Player,0,0,0)
		,m_Anime(0)           //アニメーションカウンタの初期化
		, m_Anime_s(0)
		, m_Turn(E_RIGHT)
	{
		m_image.m_Enabled = true;
		//プレイヤーのサイズ
		m_image.SetVertex(0, 90, 0, 135);
		//キャラクターアニメーション画像の読み込み
		i_Chara_Motion_1.Load("image/chara/chara_motion_1.tga");
		i_Chara_Motion_2.Load("image/chara/chara_motion_2_16bit.tga");
		printf("%f\n%f\n%f\n%f\n", m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top);
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
	virtual void Update();
	virtual void Draw();
};

class C_Test :public C_Object{
public:
	C_Test()
		:C_Object(E_PLAYER, eUDP_Player, eDWP_Player,0,0,-450)
		, m_Anime(0)           //アニメーションカウンタの初期化
		, m_Anime_s(0)
	{
		m_image.m_Enabled = true;
		//プレイヤーのサイズ
		m_image.SetVertex(-600, 600, -450, -330);

	}
	int m_Anime;            //アニメーション管理変数
	int m_Anime_s;          //アニメーション秒数管理
	int m_Anime_Taiki;      //アニメーション管理変数
	int m_Anime_Taiki_s;    //アニメーション秒数管理(待機)
	int m_Turn;             //右を向いているか左を向いているか
	virtual void Update();
	virtual void Draw();
};

#endif