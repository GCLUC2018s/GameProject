#include "COage.h"

COage::COage(CVector3D * pos) :CItemBase(pos) {
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("UI"));
	m_img.SetRect(0, 256, 64, 320);
	m_img.SetSize(64, 64);
	m_rect = CRect(0, 0, 64, 64);
	m_rect_F = m_rect;
}

COage::~COage() {

}
