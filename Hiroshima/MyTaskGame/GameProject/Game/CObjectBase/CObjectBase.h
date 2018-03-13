#ifndef CHARABASE_GUARD
#define CHARABASE_GUARD

#include "../GameProject/Task/CTask.h"
#include "../GameProject/stdafx.h"

class CObjectBase : public CTask
{
protected:
	CAnimImage	m_img;		//�摜�I�u�W�F�N�g
	CVector2D	m_pos2D;		//���W
	CVector2D	m_vec2D;		//�ړ���
	CVector3D	m_pos3D;		//���W
	CVector3D	m_vec3D;		//�ړ���
	CRect	m_rect;			//�����蔻��p�Z�`
	bool	m_flipH;		//���]�t���O
	bool	m_move;
	int		m_type;
	float	m_color;		//�F
	static CVector2D m_scroll;
	int m_hp;  //�̗�
	int m_at;  //�U����
	int m_state; //���
	//���
	enum {
		eIdol,			//�ҋ@
		eAttack,		//�U��
		eKnockBack,    //�m�b�N�o�b�N
		eFall,			//�|���
		eMove,         //�ړ�
	};
public:
	CObjectBase(int id, int updatePrio, int drawPrio);
	//~CCharaBase();

	/*!
	@brief	�l���w��l�܂ŁA�w��l���㏸������
	@param	v_Price_UF	[in] �����l
	@param	v_Price_UE	[in] �ő�l
	@param	a			[in] ���l
	@retval	����
	**/
	float Price_Up(float v_Price_UF, float v_Price_UE, float a)
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
	float Price_Down(float v_Price_DF, float v_Price_DE, float a)
	{
		if (v_Price_DF > v_Price_DE)
			v_Price_DF -= a;
		else v_Price_DF = v_Price_DE;

		return v_Price_DF;
	}

private:
	//�`�施��
	virtual void Draw();
};


#endif // !CHARABASE_GUARD
