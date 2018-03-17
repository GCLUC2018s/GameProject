#include "COhuda.h"

COhuda::COhuda(CVector3D * pos, bool * flipH) :CItemBase(pos) {
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Ohuda"));
	m_img.SetRect(0, 128, 128, 256);
	m_img.SetSize(64, 64);
	m_rect = CRect(0, 0, 64, 64);
	m_flipH = *flipH;
}

COhuda::~COhuda(){

}

void COhuda::Update(){
	m_pos3D += m_vec3D;
	if (m_flipH)
		m_vec3D.x = -10;
	else
		m_vec3D.x = 10;

//	m_img.ChangeAnimation(eAnimItemBill);
	m_img.UpdateAnimation();

}

void COhuda::Hit(CObjectBase * t)
{
}
