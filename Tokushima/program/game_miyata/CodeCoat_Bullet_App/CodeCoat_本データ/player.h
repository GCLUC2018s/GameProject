//--------------------------
//player.h 6/14
///--------------------------

#ifndef __PLAYER_H__
#define __PLAYER_H__

//ヘッダーファイル
#include <DxLib.h>
#include "CharaData.h"
#include "myLib.h"
#include "map.h"
#include "item.h"
#include "Task\CTask.h"

//定数
const int ANIM_COUNT = 38;			//キャラの画像枚数
const int HEAL_ANIM_COUNT = 18;		//回復アイテム取得時のキャラ画像枚数
const int MOVEING_RANGE_DOWN = 590;		//下の移動限界範囲
const int MOVEING_RANGE_UP = 300;		//上の移動限界範囲
const int MOVEING_RANGE_LEFT = -25;		//左の移動限界範囲
const int MOVEING_RANGE_RIGHT = 1255;	//右の移動限界範囲
const int PLAYER_HEIGHT_SIZE = 30;		//主人公の当たり判定：縦サイズ
const int PLAYER_WIDE_SIZE = 50;		//主人公の当たり判定：幅サイズ
const float START_POSX = 50;			//主人公のスタート位置：x座標
const float START_POSY = 200;			//主人公のスタート位置：y座標
const int MAX_KNIVES = 4;				//同時に射撃できる数
const int PLAYER_LOWER_SIZE = 60;//下半身の位置
const int PLAYER_SHADOW_POS = 150;//影の位置
const float P_SPEED = 270.0f;	 //主人公の基本速度
const float BASE_SCR_SPEED = 150;//画面スクロールの基本速度
const int ONE_GEAR_SPACE = 320;//1280を4で割った値
const int EQUIPMENT_COUNT = 3; //装備欄の数

class CKnifestats{	//後々銃弾用にタスクを作る
public:
	BOOL m_living;
	BOOL m_turn;
	CVector2D pos;

};

//追加、プレイヤーの描画の切り替えに使用、後々使う
enum Ptype{
	Stand, Move = 2, Jump = 14, Climb = 16, Push = 18,
	Iron_cover = 22, Pipe = 26, Pump = 30, Lever = 33,
	Dolly = 36
};

class CPlayerControl : public CTask{
private:
	CItemData m_Equipment[EQUIPMENT_COUNT];			//装備保存欄
	CKnifestats knives[MAX_KNIVES];					//同時発射可能数
	int m_heroimg[ANIM_COUNT + HEAL_ANIM_COUNT];	//主人公の画像枚数
	int m_heroUpperimg;								//主人公の上半身画像(仮)
	int m_heroLowerimg;								//主人公の下半身画像(仮)
	int m_shadowimg;								//主人公の影画像
	int m_knifeimg;									//発射物の画像、いらないかも
	float m_gear;									//スクロールの移動倍率
	CVector2D m_BodyPos;							//上半身の座標
	CVector2D m_ShadowPos;							//影の座標	分けている理由：当たり判定をとるため
	int m_attack_time;
public:
	CPlayerControl();
	~CPlayerControl();
	void Update();
	void Draw();
	float getMoveAmount();							//スクロール量の返却関数
	CVector2D getBodyPos(){ return m_BodyPos; };	//timer.cppで必要なため作らせてもらった
	void setEquipment(CItemData* item);
};



BOOL IsBKeyTrigger(int key);
BOOL IsCkeyTrigger(int key);
BOOL IsKeyTrigger(int key, int chk);
#endif __PLAYER_H__