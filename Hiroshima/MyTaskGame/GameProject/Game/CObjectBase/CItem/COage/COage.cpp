#include "COage.h"
#include "../GameProject/Game/CObjectBase/CPlayer/CPlayer.h"

COage::COage(CVector3D * pos) :CItemBase(pos) {
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("UI"));
	m_img.SetRect(0, 256, 64, 320);
	m_img.SetSize(64, 64);
	m_rect = CRect(0, 0, 64, 64);
	m_rect_F = m_rect;
}

COage::~COage() {

}

void COage::Action(CObjectBase * a) {
	CPlayer* PL = dynamic_cast<CPlayer*>(a);
	PL->SetHP(5);
	m_score += 5;
}

