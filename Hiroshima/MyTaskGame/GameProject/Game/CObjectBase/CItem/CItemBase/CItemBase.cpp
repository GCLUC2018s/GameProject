#include "CItemBase.h"
#define ITEM_HOSEI 224

CItemBase::CItemBase(CVector3D * pos) :CObjectBase(eID_Item, eU_Item, eD_Object) 
{
	m_pos3D = *pos;
	m_rect = CRect(0, 0, 20, 20);
	m_rect_F = m_rect;
}

CItemBase::~CItemBase()
{
}

void CItemBase::Update()
{
}

void CItemBase::Draw()
{
	m_img.SetColor(m_color.x, m_color.y, m_color.z, m_color.w);
	m_img.SetFlipH(m_flipH);
	m_img.SetPos(m_pos3D.x - m_pos3D.z / 7 - m_scroll.x, 450 + ITEM_HOSEI + m_pos3D.y + m_pos3D.z / 2 - m_scroll.y);
	m_img.Draw();
	Utility::DrawQuad(CVector2D(m_pos3D.x - m_pos3D.z / 7 - m_scroll.x + m_rect.m_left, 450 + ITEM_HOSEI + m_pos3D.y + m_pos3D.z / 2 - m_scroll.y + m_rect.m_top), CVector2D(m_rect.m_right - m_rect.m_left, m_rect.m_bottom - m_rect.m_top), CVector4D(1, 0, 0, 0.3));
	Utility::DrawQuad(CVector2D(m_pos3D.x - m_pos3D.z / 7 - m_scroll.x + m_rect_F.m_left, 450 + ITEM_HOSEI + m_pos3D.y + m_pos3D.z / 2 - m_scroll.y + m_rect_F.m_top), CVector2D(m_rect_F.m_right - m_rect_F.m_left, m_rect_F.m_bottom - m_rect_F.m_top), CVector4D(0, 0, 1, 0.2));
}

void CItemBase::Hit(CObjectBase * t)
{
	printf("hit [%d]\n", t->GetID());
	//if (t->GetID() == eID_Player) {
	//	SetKill();
	//}
}