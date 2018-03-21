#include "COhuda.h"
#include "../GameProject/Game/CObjectBase/CGimmick/CFire.h"

COhuda::COhuda(const CVector3D &pos, bool flipH) :CObjectBase(eID_Bullet, eU_Player, eD_Effect) {
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Bill"));
	m_img.SetRect(0, 128, 128, 256);
	m_img.SetSize(64, 64);
	m_rect = CRect(0, 0, 64, 64);
	m_rect_F = CRect(0, 0, 64, 215);
	m_pos3D = pos;
		m_pos3D.y += 60;
	if (flipH) {
		m_pos3D.x -= 60;
	}
	else {
		m_pos3D.x += 60;
	}
	m_flipH = flipH;
	m_cnt = 0;
	if (m_flipH)
		m_vec3D.x = -15;
	else
		m_vec3D.x = 15;

	//âeê›íË
	m_img_shadow = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Shadow"));
	m_img_shadow.SetSize(64, 16);
	m_img_shadow.SetCenter(0, 16 / 2);

	m_img.ChangeAnimation(0);
}

COhuda::~COhuda(){

}

void COhuda::Update() {
	m_pos3D += m_vec3D;
	m_cnt++;

	m_vec3D.y = sin(m_cnt) * 3;

	if (m_pos3D.x - m_scroll.x < -64 || m_pos3D.x - m_scroll.x > SCREEN_WIDTH)
		SetKill();

	m_img.UpdateAnimation();
	m_rect_F.m_bottom = 215 - m_pos3D.y;
	CheckOverlap();
}

void COhuda::Draw(){
	m_img.SetPos(m_pos3D.x - m_pos3D.z / 7 - m_scroll.x, 450 + m_pos3D.y + m_pos3D.z / 2 - m_scroll.y);
	m_img.SetFlipH(m_flipH);
	m_img_shadow.SetColor(1, 1, 1, m_color.w + (m_pos3D.y * 0.001));
	m_img_shadow.SetPos(m_pos3D.x - m_pos3D.z / 7 - m_scroll.x, 450 + m_rect_F.m_bottom + m_pos3D.y + m_pos3D.z / 2 - m_scroll.y);
	m_img_shadow.Draw();
	m_img.Draw();

}

void COhuda::Hit(CObjectBase * t)
{
	if (t->GetID() == eID_Enemy) {
		new CFire(t);
		SetKill();
	}
}
