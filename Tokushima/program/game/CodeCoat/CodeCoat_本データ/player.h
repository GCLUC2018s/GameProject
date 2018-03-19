//--------------------------
//player.h 6/14
///--------------------------

#ifndef __PLAYER_H__
#define __PLAYER_H__

//�w�b�_�[�t�@�C��
#include <DxLib.h>
#include "myLib.h"
#include "map.h"
#include "item.h"
#include "Task\CTask.h"

//�萔
const int ANIM_COUNT = 14;			//�L�����̉摜����
const int HEAL_ANIM_COUNT = 18;		//�񕜃A�C�e���擾���̃L�����摜����
const int MOVEING_RANGE_DOWN = 640;		//���̈ړ����E�͈�
const int MOVEING_RANGE_UP = 430;		//��̈ړ����E�͈�
const int MOVEING_RANGE_LEFT = -25;		//���̈ړ����E�͈�
const int MOVEING_RANGE_RIGHT = 1150;	//�E�̈ړ����E�͈�
const int PLAYER_HEIGHT_SIZE = 30;		//��l���̓����蔻��F�c�T�C�Y
const int PLAYER_WIDE_SIZE = 50;		//��l���̓����蔻��F���T�C�Y
const float START_POSX = 50;			//��l���̃X�^�[�g�ʒu�Fx���W
const float START_POSZ = 200;			//��l���̃X�^�[�g�ʒu�Fz���W
const int MAX_KNIVES = 4;				//�����Ɏˌ��ł��鐔
const float PLAYER_LOWER_SIZE = 75.0f;//�����蔻��(����)����o���p
const float PLAYER_CENTER = 83.0f;
const int PLAYER_SHADOW_HEIGHT_POS = 170;//�e�̈ʒu�F�c
const int PLAYER_SHADOW_WIDTH_POS = 53;//�e�̈ʒu�F��
const float P_SPEED = 270.0f;	 //��l���̊�{���x
const float BASE_SCR_SPEED = 75;//��ʃX�N���[���̊�{���x
const int ONE_GEAR_SPACE = 160;//1280��8�Ŋ������l
const int EQUIPMENT_COUNT = 3; //�������̐�
const float KNIFE_RAD = 2500;	//�i�C�t�ɂ��U���͈�
const float PLAYER_COLLISION = 30;//��l���̓����蔻�蔼�a
const int ANIM_RATE = 6;//�A�j���[�V�����̍Đ����x

const float GRAVITY = 78.0f;		//�d��
const float JUMP_POWER = 1150.0f;	//�W�����v��

/*
const int MOVERATE = 7;
const float JUMP_POWER = 1200.0f;	//750.0f
const float GRAVITY = 60.0f;		//30.0f
const float JUMP_FORWARD = 100.0f;	//200.0f
const int ANIM_RATE = 6;
const int ANIM_M_NUMBER = 6;
const int ANIM_NUMBER = 2;
*/
class CKnifestats{	//��X�e�e�p�Ƀ^�X�N�����
public:
	BOOL m_living;
	BOOL m_turn;
	CVector3D pos;

};

//�ǉ��A�v���C���[�̕`��̐؂�ւ��Ɏg�p�A��X�g��
enum Ptype{
	Move = 0, Jump = 8, Stand = 13
};

//�o�t�Ǘ��̍\����
struct SBuff{
	float m_speedup;
	float m_score_ratio;
};

class CPlayerControl : public CTask{
private:
	CItemData m_Equipment[EQUIPMENT_COUNT];			//�����ۑ���
	CKnifestats knives[MAX_KNIVES];					//�������ˉ\��
	int m_heroimg[ANIM_COUNT + HEAL_ANIM_COUNT];	//��l���̉摜����
	int m_heroUpperimg[ANIM_COUNT];								//��l���̏㔼�g�摜(��)
	int m_heroLowerimg[ANIM_COUNT];								//��l���̉����g�摜(��)
	int m_shadowimg;								//��l���̉e�摜
	float m_gear;									//�X�N���[���̈ړ��{��
	CVector3D m_BodyPos;							//�㔼�g�̍��W
	CVector3D m_ShadowPos;							//�e�̍��W	�����Ă��闝�R�F�����蔻����Ƃ邽��
	int m_attack_time;								//�U���Ԋu�����ϐ�
	Ptype m_upper_playerstate;						//�v���C���[�̏��
	Ptype m_lower_playerstate;
	bool m_live;									//�����Ă��邩
	float m_jumppower;								//�W�����v��
	bool m_jumping;									//�W�����v���Ă��邩
	BOOL m_purge;									//�p�[�W���Ă��邩
	int m_upper_animcounter;						//�A�j���[�V���������Ԗڂ�:�㔼�g
	int m_lower_animcounter;						//�A�j���[�V���������Ԗڂ�:�����g
	int m_upper_ac;
	int m_lower_ac;
	SBuff m_buff;
public:
	CPlayerControl();
	~CPlayerControl();
	void Update();
	void Draw();
	float getMoveAmount();							//�X�N���[���ʂ̕ԋp�֐�
	CVector3D getBodyPos(){ return m_BodyPos; };	//timer.cpp�ŕK�v�Ȃ��ߍ�点�Ă������
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