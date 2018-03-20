#include "CSake.h"
#include "../GameProject/Game/CObjectBase/CPlayer/CPlayer.h"

CSake::CSake(CVector3D * pos) :CItemBase(pos) {
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("UI"));
	m_img.SetRect(64, 256, 128, 320);
	m_img.SetSize(64, 64);
	m_rect = CRect(0, 0, 64, 64);
	m_rect_F = m_rect;
}

CSake::~CSake() {

}
void CSake::Action(CObjectBase * a) {
	CPlayer* PL = dynamic_cast<CPlayer*>(a);
	PL->SetHP(5);
}
