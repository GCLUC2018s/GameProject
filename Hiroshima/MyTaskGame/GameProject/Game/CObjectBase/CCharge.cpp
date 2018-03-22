#include "CCharge.h"
#include "CBress.h"


CCharge::CCharge(CVector2D pos){
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Effect_charge"));
	m_pos2D = pos;
	m_img.SetCenter(120, 120);
	m_img.SetPos(m_pos2D);
	CheckOverlap();
}

void CCharge::Update(){
	if (m_img.GetIndex() == 10) {
		new CBress(m_pos2D);
		SetKill();
	}
	m_img.ChangeAnimation(0, false);
	m_img.UpdateAnimation();
	CheckOverlap();
}

void CCharge::Draw(){
		m_img.SetPos(m_pos2D.x, m_pos2D.y - m_scroll.y);
		m_img.Draw();
}
