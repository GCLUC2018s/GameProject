#include "CSake.h"

CSake::CSake(CVector3D * pos) :CObjectBase(0, eU_Item, eD_Object) {
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Sake"));
	m_img.SetRect(64, 256, 128, 320);
	m_img.SetSize(64, 64);
	m_rect = CRect(0, 0, 64, 64);
	m_pos3D = *pos;

}

CSake::~CSake() {

}

void CSake::Update() {
}

void CSake::Draw(){

	m_img.SetColor(m_color.x, m_color.y, m_color.z, m_color.w);
	m_img.SetFlipH(m_flipH);

	m_img.SetPos(m_pos3D.x - m_pos3D.z / 7 - m_scroll.x, 450 + m_pos3D.y + m_pos3D.z / 2 - m_scroll.y);
	m_img.Draw();
	Utility::DrawQuad(CVector2D(m_pos3D.x - m_pos3D.z / 7 - m_scroll.x + m_rect.m_left, 450 + m_pos3D.y + m_pos3D.z / 2 - m_scroll.y + m_rect.m_top), CVector2D(m_rect.m_right - m_rect.m_left, m_rect.m_bottom - m_rect.m_top), CVector4D(1, 0, 0, 0.3));
	Utility::DrawQuad(CVector2D(m_pos3D.x - m_pos3D.z / 7 - m_scroll.x + m_rect_F.m_left, 450 + m_pos3D.y + m_pos3D.z / 2 - m_scroll.y + m_rect_F.m_top), CVector2D(m_rect_F.m_right - m_rect_F.m_left, m_rect_F.m_bottom - m_rect_F.m_top), CVector4D(0, 0, 1, 0.2));

}

void CSake::Hit(CTask * t){

}
