#include "CGimmick.h"
/*

êªçÏé“Å@âÕñÏ

*/

CGimmick::CGimmick(CVector3D *pos) :CObjectBase(0, eU_Gimmick, eD_Object) {
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Fire"));
	m_pos3D = *pos;
	m_rect = CRect(0, 0, 204, 245);
	m_img.SetSize(100, 200);
}

CGimmick::~CGimmick(){
}

void CGimmick::Update(){
	m_img.ChangeAnimation(0);
	m_img.UpdateAnimation();
	CheckOverlap();
}

void CGimmick::Draw(){
	m_img.SetPos(m_pos3D.x - m_scroll.x, 550 + m_pos3D.y + m_pos3D.z - m_scroll.y);
	m_img.Draw();
}
