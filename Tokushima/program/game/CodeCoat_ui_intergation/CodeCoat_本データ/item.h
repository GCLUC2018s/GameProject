#ifndef __ITEM_H__
#define __ITEM_H__

//�w�b�_�[�t�@�C��
#include <DxLib.h>
#include <list>
#include "myLib.h"
#include "Task\CTask.h"

using namespace std;

//�萔
const int ITEMCOUNT = 8;		//�A�C�e���̉摜��
const int ITEM_CHIPSIZE = 200;	//�A�C�e���̉摜�T�C�Y
const float ITEM_CENTER = 100.0f;//�A�C�e���̒��S����o��
const float ITEM_COLLISION =100;//�A�C�e���̓����蔻�蔼�a

//�쐬�O�ɕK�v�v�f�̂܂Ƃ�
/*
�N���X�Ɏ�������v�f
�����̎��
�ϋv�x�������͎��Ԃ��������
�摜
���W

�A�C�e���̉摜���g���Ƃ���
�P�DUI
����l���Ɏ������Ă��鑕�����̏��������čs���Ă��炤
�Q�D�t�B�[���h
���G���j���Ɉ��m���ŏo��
enemy�̊֐��̕��ŃA�C�e�����o��������֐����~����

player
���ԍ��A�ϐ���A�摜��UI�ɓn�����߂ɕK�v
enemy
���Ȃ�
NPC
���ԍ��A�摜�A�ϐ����
UI
���摜

------------------------------------------------------------------------------------------------------
�K�v�Ȋ֐�
CItemData pickupItem(CVector2D pos);	//�����ɍ��W������ƍ��W�����ɂ���A�C�e����Ԃ��l�ɂ���
CItemData BuyBuild(ItemName name);	//�����ɔԍ�������Ƃ��̔ԍ��̃A�C�e���̏���Ԃ�
void makeBuild(CVector2D pos, ItemName name);�@�@//�����̔ԍ��ƍ��W�����X�g�ɒǉ�����  �G�����񂾂Ƃ��Ɏg���@���W�Ɏw�肵���A�C�e����z�u����
------------------------------------------------------------------------------------------------------
*/

//�A�C�e���̎��
enum ItemType{WEAPON = 0,ARMOR,ITEM};	

//�A�C�e���̖��O
enum ItemName{NONE = -1, KNIFE = 0, PISTOL, SHOTTOGAN, RIFLE, STABARMOR, BULLETARMOR, SCOREBOOST, SPEEDUP };	

//��l���Ƀf�[�^��n���p�̃N���X(��)
class CItemData{
public:
	CItemData();
	ItemType m_type;
	int m_img;
	ItemName m_name;
	int m_useful;			//�h��̏ꍇ�͑ϋv�l�A�A�C�e���̏ꍇ�͎c�莞�Ԃ�����
	int m_attack_rate;
};

class CIdata : public CTask{
private:
	CVector3D m_pos;					//���W
	ItemType m_type;					//�A�C�e���̎��		
	ItemName m_name;					//�A�C�e���̖��O
//	bool m_IsKill;						����Ȃ��\���F��
//	bool m_live;						����Ȃ��\���F��
	int m_useful;						//�F�X�ȗv�f�Ƃ��Ďg���ϐ�(��@�e�F�c�e���@�h��F�ϋv�l�@�A�C�e���F���ʎ���)
public:
	void Update();
	void Draw();
	CIdata(CVector3D* pos, int num);
	~CIdata();
	CVector3D GetPos()const{ return m_pos; }
	ItemName GetName()const{ return m_name; }
	ItemType GetType()const{ return m_type; }
};

#endif __ITEM_H__