#ifndef CHARABASE_GUARD
#define CHARABASE_GUARD

#define GRAVITY 1.2f

#include "../GameProject/Task/CTask.h"
#include "../GameProject/Task/CTaskManager.h"
#include "../GameProject/stdafx.h"
#include "../GameProject/ImageResource.h"

/*

����@�{��

*/


class CObjectBase : public CTask
{
protected:
	CAnimImage	m_img;		//�摜�I�u�W�F�N�g
	CVector2D	m_pos2D;		//���W
	CVector2D	m_vec2D;		//�ړ���
	CVector3D	m_pos3D;		//���W
	CVector3D	m_vec3D;		//�ړ���
	CRect	m_rect_F;		//����ւ�����p�Z�`
	CRect	m_rect;			//�����蔻��p�Z�`
	bool	m_flipH;		//���]�t���O
	bool	m_move;
	int		m_type;	
	static CVector2D m_scroll;	//�X�N���[���l
	static bool m_wave_flag;	//��wave���Ȃ�true�B�G�S�ł�������false�ɂ��āA�X�N���[���J�n
	static 	bool m_sc_flag_x;	//�v���C���[�����������Ƃɂ��X�N���[���t���O�Btrue�Ȃ�v���C���[�̓����͎~�܂�
	int m_hp;  //�̗�
	int m_at;  //�U����
	int m_state; //���
	CColorRGBA m_color;	//�F
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
	//���W�擾
	CVector3D GetPos() {
		return m_pos3D;
	};
	//�x�N�g���擾
	CVector3D GetVec() {
		return m_vec3D;
	};
	//�x�N�g���Z�b�g
	void SetVec(CVector3D &vec) {
		m_vec3D = vec;
	};
	//��`�擾
	CRect GetRect() {
		return m_rect;
	};
	////����ւ��p��`�擾
	//CRect *GetRect_F() {
	//	return &m_rect_F;
	//};

	//�d�Ȃ�m�F
	void CheckOverlap() {
		if(m_pos3D.z <= 0){
			CTaskManager::GetInstance()->ChangeDrawPrio(this, SCREEN_HEIGHT + m_pos3D.z);
		}
	};
	//��Ԋm�F
	int GetState() {
		return m_state;
	};
	//�X�N���[���l���擾

	////�`�揇�ʓ���ւ�
	//void SwapDrawPriority(CObjectBase *t);

	////�`�揇���`�F�b�N�֐�
	//void CheckOverlapAll();
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
	//�`�施��
	virtual void Draw();
	//�����蔻��
	void HitCheck(CTask * t1, CTask * t2);
	//�����������̏���
	virtual void Hit(CObjectBase *t);
	////�d�Ȃ�m�F
	//void CheckOverlap(CObjectBase *t1, CObjectBase *t2);
};


#endif // !CHARABASE_GUARD
