#include "CGimmick.h"
/*

����ҁ@�͖�

*/

CGimmick::CGimmick(CVector3D *pos) :CObjectBase(0, eU_Gimmick, eD_Gimmick) {
	m_img.SetSize(30, 200);
	m_pos3D = *pos;
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
	CheckOverlap();
}