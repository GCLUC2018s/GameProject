#include "COhuda.h"

COhuda::COhuda(CVector3D * pos, bool * flipH):CObjectBase(0,eU_Item,eD_Item){
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Ohuda"));
	m_img.SetSize(64, 64);
	m_flipH = *flipH;
	m_pos3D = *pos;
	
}

COhuda::~COhuda(){

}

void COhuda::Update(){
	m_pos3D += m_vec3D;
	if (m_flipH)
		m_vec3D.x = -10;
	else
		m_vec3D.x = 10;

	m_img.ChangeAnimation(eAnimItemBill);
	m_img.UpdateAnimation();

}
