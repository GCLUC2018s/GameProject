#include "CBullet.h"
#include "CMAP.h"
#include "../Global.h"
#include "CEffect.h"


CBullet::CBullet(int type, CVector2D pos, CVector2D vec): CBase(eTagBullet) {
	m_img = CAnimImage(g_image[eImageBullet], bullet_anim_Data, 32, 32);
	m_img.SetSize(32, 32);
	m_pos = pos;
	m_vec = vec;
	m_type = type;
	if (m_type == 0) {
		m_rect = CRect(5, 5, 27, 27);
		m_mask = MASK_ENEMY;
	}else {
		m_rect = CRect(0, 0, 32, 32);
		m_mask = MASK_PLAYER;
	}
}

CBullet::~CBullet() {

}

void CBullet::Update() {
	m_old_pos = m_pos;
	if (m_pos.x > MAP_WIDTH * MAP_TIP_SIZE || m_pos.x < -32 || m_pos.y < -32) {
		m_active = false;
	}
	m_pos += m_vec;
	m_img.ChangeAnimation(m_type);
	m_img.UpdateAnimation();
	if (WallCheck() != 0) {
		g_list.push_back(new CEffectSmoke(m_pos));
		g_list.push_back(new CEffectBomb(m_pos));
		m_active = false;
	}
}

void CBullet::HitCallback(CBase* b) {
	m_active = false;
	g_list.push_back(new CEffectBomb(m_pos));
}