#include "COhuda.h"

COhuda::COhuda(CVector3D * pos, bool * flipH) :CObjectBase(eID_Player, eU_Player, eD_Object) {
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Bill"));
	m_img.SetRect(0, 128, 128, 256);
	m_img.SetSize(64, 64);
	m_rect = CRect(0, 0, 64, 64);
	m_pos3D = *pos;
	m_flipH = *flipH;
	m_cnt = 0;
}

COhuda::~COhuda(){

}

void COhuda::Update(){
	m_pos3D += m_vec3D;
	m_cnt++;

	if (m_flipH)
		m_vec3D.x = -15;
	else
		m_vec3D.x = 15;

	m_vec3D.y = sin(m_cnt) * 3;

	if (m_pos3D.x < -100 || GROUND_WIDTH < m_pos3D.x)
		SetKill();

	m_img.ChangeAnimation(0);
	m_img.UpdateAnimation();

}

void COhuda::Draw(){
	m_img.SetPos(m_pos3D.x - m_pos3D.z / 7 - m_scroll.x + 70, 450 + 30 + m_pos3D.y + m_pos3D.z / 2 - m_scroll.y);
	m_img.Draw();
}

void COhuda::Hit(CObjectBase * t)
{
}
