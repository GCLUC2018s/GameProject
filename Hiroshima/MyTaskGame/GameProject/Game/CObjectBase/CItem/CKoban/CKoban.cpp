#include "CKoban.h"

CKoban::CKoban(CVector3D * pos):CObjectBase(0,eU_Item,eD_Item){
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Koban"));
	m_img.SetRect(0, 320, 32, 352);
	m_img.SetSize(16, 16);
	m_pos3D = *pos;

}

CKoban::~CKoban()
{
}

void CKoban::Update()
{
}
