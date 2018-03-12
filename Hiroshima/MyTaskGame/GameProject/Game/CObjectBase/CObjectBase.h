#ifndef CHARABASE_GUARD
#define CHARABASE_GUARD

#include "../GameProject/Task/CTask.h"

class CObjectBase : public CTask
{
protected:
	CAnimImage	m_img;		//�摜�I�u�W�F�N�g
	CVector2D	m_pos;		//���W
	CVector2D	m_vec;		//�ړ���
	CRect	m_rect;			//�����蔻��p�Z�`
	bool	m_flipH;		//���]�t���O
	bool	m_active;		//�����t���O
	bool	m_move;
	int		m_type;
	float	m_color;		//�F
	static CVector2D m_scroll;
public:
	CObjectBase();
	//~CCharaBase();

private:
	//�`�施��
	virtual void Draw();

};

#endif // !CHARABASE_GUARD
