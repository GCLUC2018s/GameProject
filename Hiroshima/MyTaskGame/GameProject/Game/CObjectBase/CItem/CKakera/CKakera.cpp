#include "CKakera.h"

CKakera::CKakera(CVector3D * pos) :CItemBase(pos) {
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Kakera"));
	m_img.SetSize(64, 64);
	m_rect = CRect(0, 0, 64, 64);
	m_rect_F = m_rect;
}

CKakera::~CKakera() {

}

void CKakera::Hit(CObjectBase * t)
{
	if (t->GetID() == eID_Player&& m_get == false) {
		SOUND("SE_KAKERA")->Play(false);
		m_time = 0;
		m_get = true;
	}
}