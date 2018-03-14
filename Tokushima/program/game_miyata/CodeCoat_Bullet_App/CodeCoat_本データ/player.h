//--------------------------
//player.h 6/14
///--------------------------

#ifndef __PLAYER_H__
#define __PLAYER_H__

//�w�b�_�[�t�@�C��
#include <DxLib.h>
#include "CharaData.h"
#include "myLib.h"
#include "map.h"
#include "item.h"
#include "Task\CTask.h"

//�萔
const int ANIM_COUNT = 38;			//�L�����̉摜����
const int HEAL_ANIM_COUNT = 18;		//�񕜃A�C�e���擾���̃L�����摜����
const int MOVEING_RANGE_DOWN = 590;		//���̈ړ����E�͈�
const int MOVEING_RANGE_UP = 300;		//��̈ړ����E�͈�
const int MOVEING_RANGE_LEFT = -25;		//���̈ړ����E�͈�
const int MOVEING_RANGE_RIGHT = 1255;	//�E�̈ړ����E�͈�
const int PLAYER_HEIGHT_SIZE = 30;		//��l���̓����蔻��F�c�T�C�Y
const int PLAYER_WIDE_SIZE = 50;		//��l���̓����蔻��F���T�C�Y
const float START_POSX = 50;			//��l���̃X�^�[�g�ʒu�Fx���W
const float START_POSY = 200;			//��l���̃X�^�[�g�ʒu�Fy���W
const int MAX_KNIVES = 4;				//�����Ɏˌ��ł��鐔
const int PLAYER_LOWER_SIZE = 60;//�����g�̈ʒu
const int PLAYER_SHADOW_POS = 150;//�e�̈ʒu
const float P_SPEED = 270.0f;	 //��l���̊�{���x
const float BASE_SCR_SPEED = 150;//��ʃX�N���[���̊�{���x
const int ONE_GEAR_SPACE = 320;//1280��4�Ŋ������l
const int EQUIPMENT_COUNT = 3; //�������̐�

class CKnifestats{	//��X�e�e�p�Ƀ^�X�N�����
public:
	BOOL m_living;
	BOOL m_turn;
	CVector2D pos;

};

//�ǉ��A�v���C���[�̕`��̐؂�ւ��Ɏg�p�A��X�g��
enum Ptype{
	Stand, Move = 2, Jump = 14, Climb = 16, Push = 18,
	Iron_cover = 22, Pipe = 26, Pump = 30, Lever = 33,
	Dolly = 36
};

class CPlayerControl : public CTask{
private:
	CItemData m_Equipment[EQUIPMENT_COUNT];			//�����ۑ���
	CKnifestats knives[MAX_KNIVES];					//�������ˉ\��
	int m_heroimg[ANIM_COUNT + HEAL_ANIM_COUNT];	//��l���̉摜����
	int m_heroUpperimg;								//��l���̏㔼�g�摜(��)
	int m_heroLowerimg;								//��l���̉����g�摜(��)
	int m_shadowimg;								//��l���̉e�摜
	int m_knifeimg;									//���˕��̉摜�A����Ȃ�����
	float m_gear;									//�X�N���[���̈ړ��{��
	CVector2D m_BodyPos;							//�㔼�g�̍��W
	CVector2D m_ShadowPos;							//�e�̍��W	�����Ă��闝�R�F�����蔻����Ƃ邽��
	int m_attack_time;
public:
	CPlayerControl();
	~CPlayerControl();
	void Update();
	void Draw();
	float getMoveAmount();							//�X�N���[���ʂ̕ԋp�֐�
	CVector2D getBodyPos(){ return m_BodyPos; };	//timer.cpp�ŕK�v�Ȃ��ߍ�点�Ă������
	void setEquipment(CItemData* item);
};



BOOL IsBKeyTrigger(int key);
BOOL IsCkeyTrigger(int key);
BOOL IsKeyTrigger(int key, int chk);
#endif __PLAYER_H__