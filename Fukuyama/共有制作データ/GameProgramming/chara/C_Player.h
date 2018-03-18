#ifndef CPLAYER_H
#define CPLAYER_H

#include "../draw/scroll.h"
#include <stdio.h>
#include "../object/C_Object.h"
#include "../object/CColorBall.h"

#define PLAYER_LR_SPEED SCROLL_SPEED     //プレイヤーの左右移動速度
#define PLAYER_UD_SPEED 4     //プレイヤーの上下移動速度
#define JUMP_FIRST_SPEED 10    //ジャンプの初速
#define JUMP_ANIME 15    //着地モーションの時間
#define THROW_ANIME_INTERVAL 7  //アニメーション1枚当たりのフレーム数
#define THROW_ANIME_FRAME 2    //走りアニメの絵の数
#define THROW_ANIME THROW_ANIME_INTERVAL*THROW_ANIME_FRAME    //アニメーション用変数を回す上限

class C_Player :public C_Object{
public:
	C_Player() 
		:C_Object(E_PLAYER, eUDP_Player, eDWP_Player,0,0,0)
		, m_Anime(0)        //アニメーションカウンタの初期化
		, m_Anime_Jump(50)
		, i_JumpPoint(0,0,0)
	{
		m_image.m_Enabled = true;
		//プレイヤーのサイズ
		m_image.SetVertex(0, 90, 0, 135);
		//影のサイズ
		i_Shadow.SetVertex(0, 60, 0, 135);
		//キャラクターアニメーション画像の読み込み
		i_Chara_Motion_1.Load("image/chara/chara_motion_1_16bit.tga");
		i_Chara_Motion_2.Load("image/chara/chara_motion_2_16bit.tga");
		printf("%f\n%f\n%f\n%f\n", m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top);

		m_Turn = E_RIGHT;
		m_Jump = E_NJUMP;
		m_Throw = E_NTHROW;

		m_Speed.y = JUMP_FIRST_SPEED; //ジャンプの初速を設定します。
		m_Playerpoint = this;
	}
	//テクスチャーのインスタンス宣言
	CTexture i_Chara_Motion_1;
	CTexture i_Chara_Motion_2;
	C_Vector3 i_JumpPoint;
	static C_Player *m_Playerpoint;
	int m_Anime;            //アニメーション管理変数
	int m_Anime_Taiki;      //アニメーション管理変数
	int m_Anime_Jump;       //アニメーション管理変数
	int m_Anime_Throw;       //アニメーション管理変数
	float m_JumpTime;       //ジャンプしてから着地までの時間
	void Jump(C_Vector3& pos, C_Vector3& speed, const C_Vector3& gravity, float deltatime);
	virtual void Update();
	virtual void Draw();
};

class C_Test :public C_Object{
public:
	C_Test()
		:C_Object(E_PLAYER, eUDP_Player, eDWP_Player,0,0,-450)
		, m_Anime(0)           //アニメーションカウンタの初期化
	{
		m_image.m_Enabled = true;
		//プレイヤーのサイズ
		m_image.SetVertex(-600, 600, -450, -330);
	}
	int m_Anime;            //アニメーション管理変数
	int m_Anime_Taiki;      //アニメーション管理変数
	int m_Turn;             //右を向いているか左を向いているか
	virtual void Update();
	virtual void Draw();
};

#endif