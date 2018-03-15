#include "CGimmick2.h"
/*

êªçÏé“Å@âÕñÏ

*/

CGimmick2::CGimmick2(CVector3D *pos) :CObjectBase(0, eU_Gimmick, eD_Object) {
	m_img.SetSize(30, 200);
	m_pos3D = *pos;
	m_cnt = 1;
}

CGimmick2::~CGimmick2() {
}

void CGimmick2::Update() {
	m_cnt++;
	if (m_cnt <= 49) {
		m_img.ChangeAnimation(0);
		m_img.UpdateAnimation();
	}
	else {
		if (m_cnt == 129)
			m_cnt = 0;
	}
	CheckOverlap();
}