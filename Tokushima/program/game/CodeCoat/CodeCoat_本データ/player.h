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
const int ANIM_COUNT = 14;			//キャラの画像枚数
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
const float KNIFE_RAD = 2500;	//ナイフによる攻撃範囲
const float PLAYER_COLLISION = 30;//主人公の当たり判定半径
const int ANIM_RATE = 6;//アニメーションの再生速度

const float GRAVITY = 78.0f;		//重力
const float JUMP_POWER = 1150.0f;	//ジャンプ力

/*
const int MOVERATE = 7;
const float JUMP_POWER = 1200.0f;	//750.0f
const float GRAVITY = 60.0f;		//30.0f
const float JUMP_FORWARD = 100.0f;	//200.0f
const int ANIM_RATE = 6;
const int ANIM_M_NUMBER = 6;
const int ANIM_NUMBER = 2;
*/
class CKnifestats{	//後々銃弾用にタスクを作る
public:
	BOOL m_living;
	BOOL m_turn;
	CVector3D pos;

};

//追加、プレイヤーの描画の切り替えに使用、後々使う
enum Ptype{
	Move = 0, Jump = 8, Stand = 13
};

//バフ管理の構造体
struct SBuff{
	float m_speedup;
	float m_score_ratio;
};

class CPlayerControl : public CTask{
private:
	CItemData m_Equipment[EQUIPMENT_COUNT];			//装備保存欄
	CKnifestats knives[MAX_KNIVES];					//同時発射可能数
	int m_heroimg[ANIM_COUNT + HEAL_ANIM_COUNT];	//主人公の画像枚数
	int m_heroUpperimg[ANIM_COUNT];								//主人公の上半身画像(仮)
	int m_heroLowerimg[ANIM_COUNT];								//主人公の下半身画像(仮)
	int m_shadowimg;								//主人公の影画像
	float m_gear;									//スクロールの移動倍率
	CVector3D m_BodyPos;							//上半身の座標
	CVector3D m_ShadowPos;							//影の座標	分けている理由：当たり判定をとるため
	int m_attack_time;								//攻撃間隔調整変数
	Ptype m_upper_playerstate;						//プレイヤーの状態
	Ptype m_lower_playerstate;
	bool m_live;									//生きているか
	float m_jumppower;								//ジャンプ力
	bool m_jumping;									//ジャンプしているか
	BOOL m_purge;									//パージしているか
	int m_upper_animcounter;						//アニメーションが何番目か:上半身
	int m_lower_animcounter;						//アニメーションが何番目か:下半身
	int m_upper_ac;
	int m_lower_ac;
	SBuff m_buff;
public:
	CPlayerControl();
	~CPlayerControl();
	void Update();
	void Draw();
	float getMoveAmount();							//スクロール量の返却関数
	CVector3D getBodyPos(){ return m_BodyPos; };	//timer.cppで必要なため作らせてもらった
	void setEquipment(CItemData* item);
	void setDeath(){ m_live = false; }
	bool getlive(){ return m_live; }
	CItemData *getEquipment(int slot){ return &m_Equipment[slot]; }
	Ptype* getPlayerState(){ return &m_lower_playerstate; }
};


BOOL IsBKeyTrigger(int key);
BOOL IsCkeyTrigger(int key);
BOOL IsKeyTrigger(int key, int chk);
#endif __PLAYER_H__