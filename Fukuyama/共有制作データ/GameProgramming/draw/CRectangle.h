#ifndef CRECTANGLE_H
#define CRECTANGLE_H

#include "CTexture.h"
#include "../task/CTask.h"
#include "windows.h"
#include "../CKey.h"
#include "time.h"
#include "random"

#define W_H		1200 //Window��
#define W_V		900 //Window����
#define DISPLAY_BOTTOM -(W_V/2)    //�f�B�X�v���C�̉��[
#define DISPLAY_TOP W_V/2          //�f�B�X�v���C�̏�[
#define DISPLAY_LEFT -(W_H/2)      //�f�B�X�v���C�̍��[
#define DISPLAY_RIGHT W_H/2        //�f�B�X�v���C�̉E�[
#define SCROLL_PERCENTAGE 60   //�X�N���[���̊�_�i����Ńp�[�Z���g���Z�j
#define SCROLL_POINT 480   //�L�����ƃX�N���[���̋���
#define SCROLL_SPEED 6

#define Z_FirstPotision1 DISPLAY_BOTTOM+120 //�M�~�b�N�����o���ʒu�ݒ�1
#define Z_FirstPotision2 DISPLAY_TOP-390 //�M�~�b�N�����o���ʒu�ݒ�2
#define Zpos_SetPos_Center (Z_FirstPotision1+Z_FirstPotision2)/2 //���S�o��
#define Zpos_SetPos_Up (Zpos_SetPos_Center+Z_FirstPotision2)/2//��o��
#define Zpos_SetPos_Down (Zpos_SetPos_Center+Z_FirstPotision1)/2//���o��
#define TestSpeed 3 //�M�~�b�N�m�F�p�ړ��}�N��

class C_Rectangle{
protected:
	//���E�|�W�V����
	float m_PotisionX(float m_H);

	//�㉺�|�W�V����
	float m_PotisionY(float m_V);

public:
	C_Rectangle()
		:m_wide(0)
		,m_high(0)
		,m_Left(0)
		,m_Right(0)
		,m_Bottom(0)
		,m_Top(0)
	{}

	float m_wide, m_high;
	float m_Left, m_Right, m_Bottom, m_Top;
	float m_Adjust;
	void Render();
	void SetVertex(float left, float right, float bottom, float top);
	bool m_Enabled;
};

#endif