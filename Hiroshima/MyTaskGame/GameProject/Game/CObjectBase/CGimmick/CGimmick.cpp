#include "CGimmick.h"
/*

êªçÏé“Å@âÕñÏ

*/

CGimmick::CGimmick(CVector2D *pos){
	m_img.SetSize(30, 200);
	m_pos = *pos;
	m_rect = CRect(0, 0, 30, 200);
	m_cnt = 1;
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Fire"));
}

CGimmick::~CGimmick(){
}

void CGimmick::Update(){
	m_cnt++;
	if (m_cnt <= 49) {
		m_img.ChangeAnimation(0);
		m_img.UpdateAnimation();
	}else{
		if (m_cnt == 129)
			m_cnt = 0;
	}
}