#pragma once
#include "../stdafx.h"
#include "../Global.h"
#include <list>

/*
�Q�[�����̃I�u�W�F�N�g��
��{�N���X
*/

enum {
	eTagPlayer,
};

class CBase {
protected:
	CAnimImage	m_img;		//�摜�I�u�W�F�N�g
	CVector2D	m_pos;		//���W
	CVector2D	m_vec;		//�ړ���
	CRect	m_rect;			//�����蔻��p�Z�`
	bool	m_flipH;		//���]�t���O
	bool	m_active;		//�����t���O
	int		m_cnt;			//����
	int		m_state;
	bool	m_move;
	int		m_type;
	int		m_changeanim_num;//�A�j���[�V�����i���o�[
	float	m_color;		//�F
	static CVector2D m_scroll;


public:
	CBase(int tag);
	virtual ~CBase();
	//�X�V����
	virtual void Update();
	//�`�施��
	virtual void Draw();
	//�����t���O�̎擾
	bool GetActive() {
		return m_active;
	}

	//�����t���O�̐ݒ�
	void SetActive(bool f) {
		m_active = f;
	}
	CVector2D GetPos() {
		return m_pos;
	}
	//�A�j���[�V�����i���o�[���擾
	int GetAnimNum() {
		return m_changeanim_num;
	}

	//���������Ƃ��ɌĂ΂��֐�
	virtual void HitCallback(CBase* b);


};

extern std::list<CBase*> g_list;
