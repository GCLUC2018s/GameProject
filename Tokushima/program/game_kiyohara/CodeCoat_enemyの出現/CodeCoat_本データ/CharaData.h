#ifndef __CHARACTER_DATA__
#define __CHARACTER_DATA__

#include "myLib.h"

const int MOVERATE = 7;
const float JUMP_POWER = 1200.0f;	//750.0f
const float GRAVITY = 60.0f;		//30.0f
const float JUMP_FORWARD = 100.0f;	//200.0f
const int ANIM_RATE = 6;
const int ANIM_M_NUMBER = 6;
const int ANIM_NUMBER = 2;
enum ATARIMODE{
	A_GHOST, A_NORMAL, A_HARD, A_MORTAL
	//判定なし、当たれば消滅、耐久力を持つ、不死
};

class edata{
public:
	CVector2D pos;
	int data;
	CVector2D hbmasize;
	CVector2D hbmisize;
};

class CCharaData{
public:
	CVector2D m_pos;
	int m_animcounter;
	int m_ac;				//追加
	int m_playerstate;		//追加
	BOOL m_turn;
	int m_moverate;
	BOOL m_noground;
	BOOL m_jumping;
	float m_jumppower, m_jumpforward;
	CCharaData(){ m_animcounter = 0; m_moverate = 0; m_noground = FALSE; m_jumping = FALSE; m_jumpforward = 0; m_jumppower = 0; };
	~CCharaData(){}

	void setPos(CVector2D pos){
		this->m_pos = pos;
	}
	CVector2D getPos(void)const{
		return m_pos;
	}
};
#endif CHARA_DATA__