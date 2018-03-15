#ifndef CPLAYER_H
#define CPLAYER_H

#include "../draw/scroll.h"
#include <stdio.h>
#include "../object/C_Object.h"

#define PLAYER_LR_SPEED SCROLL_SPEED     //プレイヤーの左右移動速度
#define PLAYER_UD_SPEED 4     //プレイヤーの上下移動速度
#define RUN_ANIME_INTERVAL 8   //アニメーション1枚当たりのフレーム数
#define RUN_ANIME_FRAME 6    //走りアニメの絵の数
#define RUN_ANIME RUN_ANIME_INTERVAL*RUN_ANIME_FRAME    //アニメーション用変数を回す上限
#define JUMP_FIRST_SPEED 10    //ジャンプの初速

class C_Player :public C_Object{
public:
	C_Player() 
		:C_Object(E_PLAYER, eUDP_Player, eDWP_Player,0,0,0)
		, m_Turn(E_RIGHT)
		, m_Jump(E_NJUMP)
		, m_Anime(0)        //アニメーションカウンタの初期化
		, i_JumpPoint(0,0,0)
	{
		m_image.m_Enabled = true;
		//プレイヤーのサイズ
		m_image.SetVertex(0, 90, 0, 135);
		//キャラクターアニメーション画像の読み込み
		i_Chara_Motion_1.Load("image/chara/chara_motion_1_16bit.tga");
		i_Chara_Motion_2.Load("image/chara/chara_motion_2_16bit.tga");
		printf("%f\n%f\n%f\n%f\n", m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top);

		m_Speed.y = JUMP_FIRST_SPEED; //ジャンプの初速を設定します。
	}
	//プレイヤーの向きフラグ
	enum TURN_TAG{
		E_RIGHT,    //右向き
		E_LEFT,     //左向き
	};

	//プレイヤーのジャンプフラグ
	enum JUMP_TAG{
		E_JUMP,      //ジャンプ中
		E_NJUMP,     //ジャンプ中ではない
	};

	//テクスチャーのインスタンス宣言
	CTexture i_Chara_Motion_1;
	CTexture i_Chara_Motion_2;
	C_Vector3 i_JumpPoint;
	int m_Anime;            //アニメーション管理変数
	int m_Anime_Taiki;      //アニメーション管理変数
	int m_Turn;             //右を向いているか左を向いているか
	int m_Jump;             //ジャンプしているかしていないのか
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