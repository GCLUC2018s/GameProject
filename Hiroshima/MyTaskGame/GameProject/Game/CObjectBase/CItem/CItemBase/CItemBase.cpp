#include "CItemBase.h"
#define ITEM_HOSEI 151

CItemBase::CItemBase(CVector3D * pos) :CObjectBase(eID_Item, eU_Item, eD_Object) 
{
	m_pos3D = *pos;
	m_vec3D.y = -20;
	m_vec3D.x = Utility::Rand(-50, 50) / 10;
	m_vec3D.z = Utility::Rand(-50, 50) / 10;
	m_get = false;
	m_time = 0;
}

CItemBase::~CItemBase()
{
}

void CItemBase::Update()
{
	m_pos3D += m_vec3D;
	if (m_pos3D.y < 0) {
		m_vec3D.y += GRAVITY;
	}else {
		m_vec3D.x = 0;
		m_vec3D.y = 0;
		m_vec3D.z = 0;
	}
	if (m_pos3D.x < 50) {
		m_pos3D.x = 50;
	}
	if (m_pos3D.z > 0) {
		m_pos3D.z = 0;
	}
	if (m_pos3D.z < -400) {
		m_pos3D.z = -400;
	}

	if (m_get)
		Vanush();
}

void CItemBase::Draw()
{
	m_img.SetColor(m_color.x, m_color.y, m_color.z, m_color.w);
	m_img.SetFlipH(m_flipH);
	m_img.SetPos(-12 + m_pos3D.x - m_pos3D.z / 7 - m_scroll.x, 450 + ITEM_HOSEI + m_pos3D.y + m_pos3D.z / 2 - m_scroll.y);
	m_img.Draw();
	//Utility::DrawQuad(CVector2D(-12 + m_pos3D.x - m_pos3D.z / 7 - m_scroll.x + m_rect.m_left, 450 + ITEM_HOSEI + m_pos3D.y + m_pos3D.z / 2 - m_scroll.y + m_rect.m_top), CVector2D(m_rect.m_right - m_rect.m_left, m_rect.m_bottom - m_rect.m_top), CVector4D(1, 0, 0, 0.3));
	//Utility::DrawQuad(CVector2D(-12 + m_pos3D.x - m_pos3D.z / 7 - m_scroll.x + m_rect_F.m_left, 450 + ITEM_HOSEI + m_pos3D.y + m_pos3D.z / 2 - m_scroll.y + m_rect_F.m_top), CVector2D(m_rect_F.m_right - m_rect_F.m_left, m_rect_F.m_bottom - m_rect_F.m_top), CVector4D(0, 0, 1, 0.2));
}

void CItemBase::Hit(CObjectBase * t)
{
	if (t->GetID() == eID_Player&& m_get == false) {
		SOUND("SE_ITEM")->Play(false);
		m_time = 0;
		m_get = true;
	}
}

void CItemBase::Vanush()
{
	m_time++;
	m_color.w -= 0.01;
	m_pos3D.y -= 0.2;
	if (m_time % 5 == 0)m_flipH = !m_flipH;
	if (m_color.w < 0) SetKill();
}
