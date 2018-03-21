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
#define SET_INTERVAL 180       //カラーボール設置間隔
#define THROW_INTERVAL 60      //カラーボール投擲間隔
#define SPRAY_INTERVAL 600     //スプレーのクールタイム

class C_Player :public C_Object{
public:
	C_Player() 
		:C_Object(E_PLAYER, eUDP_Player, eDWP_Player,0,0,0)
		, i_JumpPoint(0,0,0)
		, m_SetInterval(SET_INTERVAL)
		, m_ThrowInterval(THROW_INTERVAL)
		, m_SprayInterval(SPRAY_INTERVAL)
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

		//状態に応じたステータスを取得
		m_Turn = E_RIGHT;
		m_Jump = E_NJUMP;
		m_Throw = E_NTHROW;
		m_Set = E_NSET;
		m_Spray = E_NSPRAY;

		m_Speed.y = JUMP_FIRST_SPEED; //ジャンプの初速を設定します。
		m_Playerpoint = this;
	}
	static C_Player *m_Playerpoint;
	C_Vector3 i_JumpPoint;
	bool Collision(C_Task*, C_Task*);
protected:
	//テクスチャーのインスタンス宣言
	CTexture i_Chara_Motion_1;
	CTexture i_Chara_Motion_2;
	float m_JumpTime;       //ジャンプしてから着地までの時間
	int m_SetInterval;        //設置間隔
	int m_ThrowInterval;          //投擲間隔
	int m_SprayInterval;          //スプレー使用間隔
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