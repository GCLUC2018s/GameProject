#ifndef SCROLL_H
#define SCROLL_H

#include "../draw/CRectangle.h"

#define PLAYER_LR_SPEED 3     //�v���C���[�̍��E�ړ����x
#define PLAYER_UD_SPEED 1     //�v���C���[�̏㉺�ړ����x
#define SCROLL_PERCENTAGE 60   //�X�N���[���̊�_�i����Ńp�[�Z���g���Z�j
#define SCROLL_POINT W_H/100*SCROLL_PERCENTAGE-(W_H/2)   //�X�N���[���̊�_�̉����W

class C_Scroll :public C_Rectangle{
protected:
	C_Scroll(){
		//ID
		C_Scroll::CTask(E_SCROLL, eUDP_Camera, eDWP_Map);
		//�X�N���[���̊�_���쐬���܂�
		SetVertex(0, 1, 0, 1);
	};
public:
	C_Scroll* pm_scroll;
	void Scroll(float left,float right);
};

#endif