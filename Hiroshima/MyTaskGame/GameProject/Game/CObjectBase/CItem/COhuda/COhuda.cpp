#include "COhuda.h"
#include "../GameProject/Game/CObjectBase/CGimmick/CFire.h"

COhuda::COhuda(CVector3D * pos, bool * flipH) :CObjectBase(eID_Bullet, eU_Bullet, eD_Effect) {
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Bill"));
	m_img.SetRect(0, 128, 128, 256);
	m_img.SetSize(64, 64);
	m_rect = CRect(0, 0, 64, 64);
	m_rect_F = CRect(0, 0, 64, 215);
	m_pos3D = *pos;
	m_pos3D.x += 60;
	m_pos3D.y += 60;
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
	m_rect_F.m_bottom = 215 - m_pos3D.y;
	CheckOverlap();
}

void COhuda::Draw(){
	m_img.SetPos(m_pos3D.x - m_pos3D.z / 7 - m_scroll.x, 450 + m_pos3D.y + m_pos3D.z / 2 - m_scroll.y);
	m_img.Draw();
	Utility::DrawQuad(CVector2D(m_pos3D.x - m_pos3D.z / 7 - m_scroll.x + m_rect.m_left, 450 + m_pos3D.y + m_pos3D.z / 2 - m_scroll.y + m_rect.m_top), CVector2D(m_rect.m_right - m_rect.m_left, m_rect.m_bottom - m_rect.m_top), CVector4D(1, 0, 0, 0.3));
	Utility::DrawQuad(CVector2D(m_pos3D.x - m_pos3D.z / 7 - m_scroll.x + m_rect_F.m_left, 450 + m_pos3D.y + m_pos3D.z / 2 - m_scroll.y + m_rect_F.m_top), CVector2D(m_rect_F.m_right - m_rect_F.m_left, m_rect_F.m_bottom - m_rect_F.m_top), CVector4D(0, 0, 1, 0.2));

}

void COhuda::Hit(CObjectBase * t)
{
	if (t->GetID() == eID_Enemy) {
		new CFire(t);
		SetKill();
	}
}
