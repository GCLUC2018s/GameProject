#include "scroll.h"

//�X�N���[���̊�_�����l�𒴂��Ă�����X�N���[������B
void C_Scroll::Scroll(float left, float right){

	//id��UI�łȂ��Ȃ�X�N���[�����܂�
	if (m_Right >= SCROLL_POINT){
		//�X�N���[���̊�_�����l���傫���Ȃ�ƃX�N���[������
		if (CKey::Push(VK_RIGHT)){
			right -= SCROLL_SPEED;
			left -= SCROLL_SPEED;
		}
	}
}
