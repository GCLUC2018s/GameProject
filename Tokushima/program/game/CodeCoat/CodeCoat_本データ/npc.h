//--------------------------
//npc.h 6/14
///--------------------------

#ifndef __NPC_H__
#define __NPC_H__

//�w�b�_�[�t�@�C��
#include <DxLib.h>
#include "myLib.h"
#include "item.h"
#include "Task\CTask.h"

//�萔
const int N_ANIM_COUNT = 3;
/*const int MOVEING_RANGE_DOWN = 640;		//���̈ړ����E�͈�
const int MOVEING_RANGE_UP = 430;		//��̈ړ����E�͈�
const int MOVEING_RANGE_LEFT = -25;		//���̈ړ����E�͈�
const int MOVEING_RANGE_RIGHT = 1150;	//�E�̈ړ����E�͈�*/
const float N_START_POSX = 50;			//��l���̃X�^�[�g�ʒu�Fx���W
const float N_START_POSZ = 200;			//��l���̃X�^�[�g�ʒu�Fz���W
const int NPC_SHADOW_HEIGHT_POS = 170;//�e�̈ʒu�F�c
const int SELL_COUNT = 3; //�������̐�
const int N_ANIM_RATE = 6;//�A�j���[�V�����̍Đ����x
const int N_MOVEING_SPEED = 380.0f;//npc�̈ړ����x

class CNpc : public CTask{
private:
	int m_shadowimg;								//npc�̉e�摜
	int m_bodyimg[N_ANIM_COUNT];
	CVector3D m_pos;
	bool m_live;
	CItemData m_sell_item[SELL_COUNT];
	bool m_shop_flag;
	bool m_dash_flag;
public:
	CNpc();
	~CNpc();
	void Update();
	void Draw();
	void setDeath(){ m_live = false; }
	bool getlive(){ return m_live; }
	bool getShopFlag(){ return m_shop_flag; }
};

#endif __NPC_H__