#ifndef C_OBJECT_H
#define C_OBJECT_H

#include "../task/CTask.h"
#include "CVector3.h"
#include "../draw/CRectangle.h"

class C_Object :public CTask{
protected:
	//�R���X�g���N�^��id�ƃv���C�I���e�B�̐ݒ�ƃ����o�[�̏�����
	C_Object(int id, int updatePrio, int drawPrio)
		:CTask(id, updatePrio, drawPrio)
		, m_Position(0.0f, 0.0f, 0.0f)
		, m_Speed(0.0f, 0.0f, 0.0f)
		, m_Scroll(m_Position.x+480)
		, m_GetScroll(0.0f)
	{}

	C_Rectangle m_image;  //�����o�[�ϐ��ɂ���
	C_Vector3 m_Position;  //���W���Ǘ�
	C_Vector3 m_Speed;  //���x���Ǘ�
	float m_GetScroll;  //�X�N���[����_�̕ۑ�
	void Rect(C_Rectangle* m_image,C_Vector3* p);  //�|�W�V�����̏ꏊ��C_Rectangle�\��
	void Scroll(C_Vector3 *p);     //�X�N���[�����������܂�
	float m_Scroll;  //�X�N���[����_
};

#endif