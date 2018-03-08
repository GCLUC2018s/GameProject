#ifndef BASE_GUARD
#define BASE_GUARD

#include "../stdafx.h"
#include "../Global.h"
#include "../ImageResource.h"
#include <list>

/*
�Q�[�����̃I�u�W�F�N�g��
��{�N���X
*/

enum {
	eTagPlayer,
	eTagEnemy,
	eTagUI,
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
	bool	m_squat;
	int		m_type;
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

	//���������Ƃ��ɌĂ΂��֐�
	virtual void HitCallback(CBase* b);

	/*!
	@brief	�l���w��l�܂ŁA�w��l���㏸������
	@param	v_Price_UF	[in] �����l
	@param	v_Price_UE	[in] �ő�l
	@param	a			[in] ���l
	@retval	����
	**/
	float CBase::Price_Up(float v_Price_UF, float v_Price_UE, float a)
	{
		if (v_Price_UF < v_Price_UE)
			v_Price_UF += a;
		else v_Price_UF = v_Price_UE;

		return v_Price_UF;
	}
	/*!
	@brief	�l���w��l�܂ŁA�w��l�����~������
	@param	v_Price_DF	[in] �����l
	@param	v_Price_DE	[in] �ŏ��l
	@param	a			[in] ���l
	@retval	����
	**/
	float CBase::Price_Down(float v_Price_DF, float v_Price_DE, float a)
	{
		if (v_Price_DF > v_Price_DE)
			v_Price_DF -= a;
		else v_Price_DF = v_Price_DE;

		return v_Price_DF;
	}

};

extern std::list<CBase*> g_list;

#endif // !BASE_GUARD