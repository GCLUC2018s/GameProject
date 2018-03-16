//--------------------------
//player.h 6/14
///--------------------------

#ifndef __NPC_H__
#define __NPC_H__

//ヘッダーファイル
#include <DxLib.h>
#include "myLib.h"
#include "item.h"
#include "Task\CTask.h"

//定数
const int ANIM_COUNT = 3;
const int MOVEING_RANGE_DOWN = 640;		//下の移動限界範囲
const int MOVEING_RANGE_UP = 430;		//上の移動限界範囲
const int MOVEING_RANGE_LEFT = -25;		//左の移動限界範囲
const int MOVEING_RANGE_RIGHT = 1150;	//右の移動限界範囲
const float START_POSX = 50;			//主人公のスタート位置：x座標
const float START_POSZ = 200;			//主人公のスタート位置：z座標
const int PLAYER_SHADOW_HEIGHT_POS = 170;//影の位置：縦
const int EQUIPMENT_COUNT = 3; //装備欄の数
const int ANIM_RATE = 6;//アニメーションの再生速度

class CNpc : public CTask{
private:
	int m_shadowimg;								//npcの影画像
	int m_bodyimg[ANIM_COUNT];
	CVector3D m_pos;
	bool m_live;
public:
	CNpc();
	~CNpc();
	void Update();
	void Draw();
	void setDeath(){ m_live = false; }
	bool getlive(){ return m_live; }
};

#endif __NPC_H__