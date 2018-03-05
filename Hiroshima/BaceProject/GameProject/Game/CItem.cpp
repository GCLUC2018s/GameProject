#include "CItem.h"

CItem::CItem(CVector2D pos) : CBase(eTagItem) {
	m_img = CAnimImage(g_image[eImageItem], Item01AnimData, 32, 32);
	m_img.SetSize(32, 32);
	m_pos = pos;
	m_rect = CRect(0, 0, 32, 32);
	m_mask = MASK_PLAYER;
}
CItem::~CItem() {

}
void CItem::Update() {
	m_img.ChangeAnimation(0);
	m_img.UpdateAnimation();
}