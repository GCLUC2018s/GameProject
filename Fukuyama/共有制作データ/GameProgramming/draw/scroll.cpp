#include "scroll.h"

//スクロールの基準点が一定値を超えていたらスクロールする。
void C_Scroll::Scroll(C_Rectangle*p){

	//idがUIでないならスクロールします
	if (m_Scroll >= SCROLL_POINT){
		//スクロールの基準点が一定値より大きくなるとスクロールする
		if (CKey::Push(VK_RIGHT)){
			p->m_Right -= SCROLL_SPEED;
			p->m_Left -= SCROLL_SPEED;
		}
	}
	return;
}
