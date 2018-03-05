#include "CEnemy.h"
#include "CBullet.h"
#include "CMap.h"
#include "../Global.h"
#include "CEffect.h"
#include "CItem.h"

CEnemy::CEnemy(CVector2D pos) : CBase(eTagEnemy) {
	m_img = CAnimImage(g_image[eImageEnemy01], enemy01AnimData, 256, 256);
	m_img.SetRect(0, 0, 256, 256);
	m_img.SetSize(256, 256);
	m_pos = pos;
	m_rect = CRect(80, 90, 160, 230);
	m_state = 0;
	m_cnt = 0;
	m_bull_cnt = 0;
	m_body = MASK_ENEMY;
}
void CEnemy::Update() {
	m_old_pos = m_pos;
	m_pos.y += m_vec.y;
	m_vec.y += GRAVITY;


	switch (m_state) {
	case 0:
		m_cnt++;
		m_pos.x += 4;
		m_img.ChangeAnimation(1);
		if (WallCheck()) {
			m_cnt = 0;
			m_state = 1;
			m_flipH = true;
			g_list.push_back(new CBullet(1, m_pos + CVector2D(128, 128), CVector2D(8, 0)));
		//	if (m_cnt == 60) {
		//		m_state = 2;
		//	}
		}
		break;
	case 1:
		m_cnt++;
		m_pos.x -= 4;
		m_img.ChangeAnimation(1);
		if (WallCheck()) {
			m_cnt = 0;
			m_state = 0;
			m_flipH = false;
			g_list.push_back(new CBullet(1, m_pos + CVector2D(128, 128), CVector2D(-8, 0)));
		}
	//	if (m_cnt == 60) {
	//		m_state = 3;
	//	}
		break;
	case 2:
		m_img.ChangeAnimation(1);
			g_list.push_back(new CBullet(1, m_pos + CVector2D(128, 128), CVector2D(-8, 0)));
			g_list.push_back(new CBullet(1, m_pos + CVector2D(128, 128), CVector2D(-6, -6)));
			g_list.push_back(new CBullet(1, m_pos + CVector2D(128, 128), CVector2D(0, -8)));
			g_list.push_back(new CBullet(1, m_pos + CVector2D(128, 128), CVector2D(6, -6)));
			g_list.push_back(new CBullet(1, m_pos + CVector2D(128, 128), CVector2D(8, 0)));
			g_list.push_back(new CBullet(1, m_pos + CVector2D(128, 128), CVector2D(-6, 6)));
			g_list.push_back(new CBullet(1, m_pos + CVector2D(128, 128), CVector2D(0, 8)));
			g_list.push_back(new CBullet(1, m_pos + CVector2D(128, 128), CVector2D(6, 6)));
			m_state = 0;
			m_cnt = 0;
		break;
	case 3:
		m_img.ChangeAnimation(1);
			g_list.push_back(new CBullet(1, m_pos + CVector2D(128, 128), CVector2D(-8, 0)));
			g_list.push_back(new CBullet(1, m_pos + CVector2D(128, 128), CVector2D(-6, -6)));
			g_list.push_back(new CBullet(1, m_pos + CVector2D(128, 128), CVector2D(0, -8)));
			g_list.push_back(new CBullet(1, m_pos + CVector2D(128, 128), CVector2D(6, -6)));
			g_list.push_back(new CBullet(1, m_pos + CVector2D(128, 128), CVector2D(8, 0)));
			g_list.push_back(new CBullet(1, m_pos + CVector2D(128, 128), CVector2D(-6, 6)));
			g_list.push_back(new CBullet(1, m_pos + CVector2D(128, 128), CVector2D(0, 8)));
			g_list.push_back(new CBullet(1, m_pos + CVector2D(128, 128), CVector2D(6, 6)));
			m_state = 1;
			m_cnt = 0;
		break;
	}
	m_img.UpdateAnimation();

	int x, y;
	if (WallCheck(&x) != 0) {
		m_pos.x = x;
	}
	if (FloorCheck(&y) != 0) {
		m_pos.y = y;
		m_vec.y = 0;
	}
}

void CEnemy::HitCallback(CBase* b) {
	m_active = false;
	//ƒAƒCƒeƒ€
	g_list.push_back(new CItem(m_pos + CVector2D(128, 128)));
}