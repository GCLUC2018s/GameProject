#ifndef SCROLL_H
#define SCROLL_H

#include "../draw/CRectangle.h"

class C_Scroll :public C_Rectangle{
protected:
	C_Scroll(){
		//ID,
		C_Scroll::CTask(E_SCROLL, eUDP_Camera, eDWP_Map);
		//�X�N���[���̊�_���쐬���܂�
		SetVertex(0, 1, 0, 1);
	};
public:
	C_Scroll* pm_scroll;
	void Scroll(float left,float right);
};

#endif