#include "scroll.h"
#include "../CKey.h"

//�X�N���[���̊�_�����l�𒴂��Ă�����X�N���[������B
void C_Scroll::Scroll(float left,float right){

	if ((m_id != E_UI) && m_Right >= SCROLL_POINT){
		//�X�N���[���̊�_�����l���傫���Ȃ�ƃX�N���[������
		if (CKey::Push(VK_RIGHT)){
			right -= PLAYER_SPEED;
			left -= PLAYER_SPEED;
		}
	}
	else if (m_id == E_UI){};
}