#include "CKakera.h"

CKakera::CKakera(CVector3D * pos) :CObjectBase(0, eU_Item, eD_Object) {
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Kakera"));
	m_img.SetSize(32, 32);
	m_pos3D = *pos;

}

CKakera::~CKakera() {

}

void CKakera::Update() {

}
void CKakera::Draw() {

}