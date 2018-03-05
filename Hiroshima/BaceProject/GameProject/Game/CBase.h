#pragma once
#include "../stdafx.h"
#include "../imageResource.h"
#include <list>

#define MASK_PLAYER		1
#define MASK_ENEMY		2
#define MASK_BULLET_P	4
#define MASK_BULLET_E	8

/*
	�Q�[�����̃I�u�W�F�N�g��
	��{�N���X
*/

enum {
	eTagPlayer,
	eTagEnemy,
	eTagBullet,
	eTagEffect,
	eTagSlash,
	eTagBomb,
	eTagBlood,
	eTagShotHit,
	eTagSmoke,
	eTagItem,
	eTagMap,
	eTagUI
};

class CBase {
protected:
	CAnimImage	m_img;		//�摜�I�u�W�F�N�g
	CVector2D	m_pos;		//���W
	CVector2D	m_old_pos;	//���W	
	CVector2D	m_vec;		//�ړ���
	CRect	m_rect;			//�����蔻��p�Z�`
	bool	m_flipH;		//���]�t���O
	bool	m_active;		//�����t���O
	int		m_body;			//�Փ˃}�X�N
	int		m_mask;			//�Փ˃}�X�N
	int		m_tag;			//�I�u�W�F�N�g�̎��
	static CVector2D m_scroll;

public:
	CBase(int tag);
	virtual ~CBase();
	//�X�V����
	virtual void Update();
	//�`�施��
	virtual void Draw();
	//�����t���O�̎擾
	bool GetActive(){
		return m_active;
	}

	int GetTag() {
		return m_tag;
	}

	//�I�u�W�F�N�g�ǂ����̓����蔻��
	static void HitCheck(CBase* b1, CBase* b2);
	//���������Ƃ��ɌĂ΂��֐�
	virtual void HitCallback(CBase* b);

	//�}�b�v�Ƃ̏Փ�
	int WallCheck(int *bx = nullptr);
	int FloorCheck(int *by = nullptr);

};

extern std::list<CBase*> g_list;