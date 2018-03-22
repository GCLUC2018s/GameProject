//--------------------------
//player.h 6/14
///--------------------------

#ifndef __PLAYER_H__
#define __PLAYER_H__

//ヘッダーファイル
#include <DxLib.h>
#include "myLib.h"
#include "map.h"
#include "item.h"
#include "Task\CTask.h"

//定数
const int ANIM_COUNT = 18;			//キャラの画像枚数
const int HEAL_ANIM_COUNT = 18;		//回復アイテム取得時のキャラ画像枚数
const int MOVEING_RANGE_DOWN = 640;		//下の移動限界範囲
const int MOVEING_RANGE_UP = 430;		//上の移動限界範囲
const int MOVEING_RANGE_LEFT = -25;		//左の移動限界範囲
const int MOVEING_RANGE_RIGHT = 1150;	//右の移動限界範囲
const int PLAYER_HEIGHT_SIZE = 30;		//主人公の当たり判定：縦サイズ
const int PLAYER_WIDE_SIZE = 50;		//主人公の当たり判定：幅サイズ
const float START_POSX = 50;			//主人公のスタート位置：x座標
const float START_POSZ = 200;			//主人公のスタート位置：z座標
const int MAX_KNIVES = 4;				//同時に射撃できる数
const float PLAYER_LOWER_SIZE = 75.0f;//当たり判定(腹部)割り出し用
const float PLAYER_CENTER = 83.0f;
const int PLAYER_SHADOW_HEIGHT_POS = 170;//影の位置：縦
const int PLAYER_SHADOW_WIDTH_POS = 53;//影の位置：横
const float P_SPEED = 270.0f;	 //主人公の基本速度
const float BASE_SCR_SPEED = 75;//画面スクロールの基本速度
const int ONE_GEAR_SPACE = 160;//1280を8で割った値
const int EQUIPMENT_COUNT = 3; //装備欄の数
const float PLAYER_COLLISION = 10;//主人公の当たり判定半径
const int ANIM_RATE = 6;//アニメーションの再生速度
const int PLAYER_STATE = 7;

const float SCORE_BUFF = 2.0f;
const float SPEED_BUFF = 150.0f;

const float GRAVITY = 78.0f;		//重力
const float JUMP_POWER = 1150.0f;	//ジャンプ力

//追加、プレイヤーの描画の切り替えに使用、後々使う
enum Ptype{
	Move = 0, Jump = 8, Stand = 13, Attack = 14
};

enum PState{
	P_NORMAL = 0, P_KNIFE, P_PISTOL, P_SHOTTOGAN, P_RIFLE, P_PURGE, P_PURGE_ACTIVE
};

//バフ管理の構造体
struct SBuff{
	float m_speedup;
	int m_sppedup_time;
	int m_speedup_delay;
	float m_score_ratio;
	int m_score_ratio_time;
	int m_score_ratio_delay;
};

class CPlayerControl : public CTask{
private:
	CItemData m_Equipment[EQUIPMENT_COUNT];			//装備保存欄
	int m_heroUpperimg[PLAYER_STATE][ANIM_COUNT];									//主人公の上半身画像(仮)
	int m_heroLowerimg[ANIM_COUNT];								//主人公の下半身画像(仮)
	int m_shadowimg;								//主人公の影画像
	float m_gear;									//スクロールの移動倍率
	CVector3D m_BodyPos;							//上半身の座標
	CVector3D m_ShadowPos;							//影の座標	分けている理由：当たり判定をとるため
	int m_attack_time;								//攻撃間隔調整変数
	Ptype m_upper_playerstate;						//プレイヤーの状態
	Ptype m_lower_playerstate;
	PState m_playerstate;
	bool m_live;									//生きているか
	float m_jumppower;								//ジャンプ力
	bool m_jumping;									//ジャンプしているか
	BOOL m_purge;									//パージしているか
	int m_upper_animcounter;						//アニメーションが何番目か:上半身
	int m_lower_animcounter;						//アニメーションが何番目か:下半身
	int m_upper_ac;
	int m_lower_ac;
	SBuff m_buff;
	float m_flashImgTime;
	bool m_InvincibleFlag;
	float m_duration;
public:
	CPlayerControl();
	~CPlayerControl();
	void Update();
	void Draw();
	void damageFlash(float time);
	float getMoveAmount();							//スクロール量の返却関数
	CVector3D getBodyPos(){ return m_BodyPos; };	//timer.cppで必要なため作らせてもらった
	void setEquipment(CItemData* item);
	void setDeath(){ m_live = false; }
	bool getlive(){ return m_live; }
	CItemData *getEquipment(int slot){ return &m_Equipment[slot]; }
	SBuff *getBuff(){ return &m_buff; };
	Ptype* getPlayerState(){ return &m_lower_playerstate; }
	BOOL getpurge(){ return m_purge; }
	void SetInvincibleFlag(){ m_InvincibleFlag = TRUE; }
	bool getInvinsibleFlag(){ return m_InvincibleFlag; }
};


BOOL IsBKeyTrigger(int key);
BOOL IsCkeyTrigger(int key);
BOOL IsKeyTrigger(int key, int chk);
#endif __PLAYER_H__