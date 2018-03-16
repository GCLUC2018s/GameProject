#ifndef ColorBall_H
#define ColorBall_H

#include "../draw/CRectangle.h"
#include "C_Object.h"
#include "../chara/C_Player.h"

#define INITIAL_VELOCITY 10  //�J���[�{�[���̏���

class C_ColorBall:public C_Object{
	C_ColorBall() 
	:C_Object(E_OBJ, eUDP_Object, eDWP_Object,0,0,0)
	, i_InitialSpeed(0,0,0)
	{
		m_Position =C_Player::m_Playerpos;     //�J���[�{�[���̐����ʒu���v���C���[�Ɠ������܂�
		//�J���[�{�[���̏����ʒu�̒���
		if (Player->m_Turn==E_RIGHT)
		m_Position.x += 45;
	}
public:
	C_Vector3 i_InitialSpeed();
};

#endif