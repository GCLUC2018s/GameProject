#include "scroll.h"

//�X�N���[���̊�_�����l�𒴂��Ă�����X�N���[������B
void C_Scroll::Scroll(C_Rectangle*p){

	//id��UI�łȂ��Ȃ�X�N���[�����܂�
	if (m_Scroll >= SCROLL_POINT){
		//�X�N���[���̊�_�����l���傫���Ȃ�ƃX�N���[������
		if (CKey::Push(VK_RIGHT)){
			p->m_Right -= SCROLL_SPEED;
			p->m_Left -= SCROLL_SPEED;
		}
	}
	return;
}
