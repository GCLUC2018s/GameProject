#include "scroll.h"
#include "../CKey.h"

//スクロールの基準点が一定値を超えていたらスクロールする。
void C_Scroll::Scroll(float left,float right){

	if ((m_id != E_UI) && m_Right >= SCROLL_POINT){
		//スクロールの基準点が一定値より大きくなるとスクロールする
		if (CKey::Push(VK_RIGHT)){
			right -= PLAYER_SPEED;
			left -= PLAYER_SPEED;
		}
	}
	else if (m_id == E_UI){};
}