#ifndef C_OBJECT_H
#define C_OBJECT_H

#include "../task/CTask.h"
#include "CVector3.h"
#include "../draw/CRectangle.h"

class C_Object :public CTask{
public:
	//�R���X�g���N�^��id�ƃv���C�I���e�B�̐ݒ�ƃ����o�[�̏�����
	C_Object(int id, int updatePrio, int drawPrio, float posx, float posy, float posz)
		:CTask(id, updatePrio, drawPrio)
		, init(false)
		, m_Position(posx, posy, posz)
		, m_Speed(0.0f, 0.0f, 0.0f)
		, m_Gravity(0.0f,-9.8f,0.0f)
	{}
	bool init;  //Init��ʂ������ǂ���
	void Init();
	C_Vector3 m_Position;  //���W���Ǘ�
	static float m_Scroll;  //�X�N���[����_
protected:
	C_Rectangle m_image;  //�����o�[�ϐ��ɂ���
	C_Vector3 m_Speed;  //���x���Ǘ�
	C_Vector3 m_Gravity;  //�d��
	void Rect(C_Rectangle* m_image,const C_Vector3* pos);  //�|�W�V�����̏ꏊ��C_Rectangle�\��
	void Scroll(C_Vector3 *m_pos,float m_Scroll);     //�X�N���[�����������܂�
};
#endif