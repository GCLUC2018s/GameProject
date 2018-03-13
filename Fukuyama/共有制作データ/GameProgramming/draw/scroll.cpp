#include "scroll.h"

//スクロールの基準点が一定値を超えていたらスクロールする。
void C_Scroll::Scroll(float left, float right){

	//idがUIでないならスクロールします
	if (m_Right >= SCROLL_POINT){
		//スクロールの基準点が一定値より大きくなるとスクロールする
		if (CKey::Push(VK_RIGHT)){
			right -= SCROLL_SPEED;
			left -= SCROLL_SPEED;
		}
	}
}
