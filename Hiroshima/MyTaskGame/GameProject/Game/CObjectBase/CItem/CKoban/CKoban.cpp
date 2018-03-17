#include "CKoban.h"

CKoban::CKoban(CVector3D * pos) :CItemBase(pos) {
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("UI"));
	m_img.SetRect(0, 320, 32, 352);
	m_img.SetSize(20, 20);
}

CKoban::~CKoban(){

}