#include "scroll.h"
#include "../CKey.h"

#define PLAYER_SPEED 3     //�v���C���[�̈ړ����x
#define SCROLL_PERCENTAGE 60   //�X�N���[���̊�_�i����Ńp�[�Z���g���Z�j
#define SCROLL_POINT W_H/100*SCROLL_PERCENTAGE-(W_H/2)   //�X�N���[���̊�_�̉����W

//�X�N���[���̊�_�����l�𒴂��Ă�����X�N���[������B
void C_Scroll::Scroll(float left,float right){

	//����p�̕��i�L�����Ɏ����\��j
	/*
	if (CKey::Push(VK_RIGHT)){
		m_Right += PLAYER_SPEED;
		m_Left += PLAYER_SPEED;
	}
	if (CKey::Push(VK_LEFT)){
		m_Right -= PLAYER_SPEED;
		m_Left -= PLAYER_SPEED;
	}
	*/

	//�X�N���[���̊�_�����l���傫���Ȃ�ƃX�N���[������
		if (CKey::Push(VK_RIGHT)){
			right += PLAYER_SPEED;
			left += PLAYER_SPEED;
		}
}