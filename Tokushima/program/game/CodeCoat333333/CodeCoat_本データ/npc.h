//--------------------------
//player.h 6/14
///--------------------------

#ifndef __NPC_H__
#define __NPC_H__

//�w�b�_�[�t�@�C��
#include <DxLib.h>
#include "myLib.h"
#include "item.h"
#include "Task\CTask.h"

//�萔
const int ANIM_COUNT = 3;
const int MOVEING_RANGE_DOWN = 640;		//���̈ړ����E�͈�
const int MOVEING_RANGE_UP = 430;		//��̈ړ����E�͈�
const int MOVEING_RANGE_LEFT = -25;		//���̈ړ����E�͈�
const int MOVEING_RANGE_RIGHT = 1150;	//�E�̈ړ����E�͈�
const float START_POSX = 50;			//��l���̃X�^�[�g�ʒu�Fx���W
const float START_POSZ = 200;			//��l���̃X�^�[�g�ʒu�Fz���W
const int PLAYER_SHADOW_HEIGHT_POS = 170;//�e�̈ʒu�F�c
const int EQUIPMENT_COUNT = 3; //�������̐�
const int ANIM_RATE = 6;//�A�j���[�V�����̍Đ����x

class CNpc : public CTask{
private:
	int m_shadowimg;								//npc�̉e�摜
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