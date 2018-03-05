#include "CBase.h"
#include "CMap.h"

CVector2D CBase::m_scroll(0, 0);
std::list<CBase*> g_list;

CBase::CBase(int tag) {
	m_tag = tag;
	m_pos = CVector2D(0, 0);
	m_vec = CVector2D(0, 0);
	m_flipH = false;
	m_active = true;
	m_body = 0;
	m_mask = 0;
}
CBase::~CBase() {

}

//XV–½—ß
void CBase::Update() {

}
//•`‰æ–½—ß
void CBase::Draw() {
	m_img.SetFlipH(m_flipH);
	m_img.SetPos(m_pos - m_scroll);
	m_img.Draw();
}

void CBase::HitCheck(CBase* b1, CBase* b2) {
	if (((b1->m_mask & b2->m_body) | (b2->m_mask & b1->m_body))== 0) return;
	if ((b1->m_pos.x + b1->m_rect.m_right) > (b2->m_pos.x + b2->m_rect.m_left) &&
		(b1->m_pos.x + b1->m_rect.m_left) < (b2->m_pos.x + b2->m_rect.m_right) &&
		(b1->m_pos.y + b1->m_rect.m_bottom) > (b2->m_pos.y + b2->m_rect.m_top) &&
		(b1->m_pos.y + b1->m_rect.m_top) < (b2->m_pos.y + b2->m_rect.m_bottom)) {
		b1->HitCallback(b2);
		b2->HitCallback(b1);
	}
}

void CBase::HitCallback(CBase* b) {
	m_active = false;
}

int CBase::WallCheck(int *bx) {

	int t = 0;

	int sx = m_rect.m_right - m_rect.m_left;
	int sy = m_rect.m_bottom - m_rect.m_top;
	int h = sy / MAP_TIP_SIZE;
	if (h == 0) h = 1;

	int x, y;
	int iy = m_rect.m_bottom - 1;
	for (int i = 0; i <= h; i++) {
		int ix = m_rect.m_right;
		for (int i = 0; i < 2; i++, ix -= sx) {
			t = g_map->GetTipNo(m_pos.x + ix, m_old_pos.y + iy, &x, &y);
			if (t != 0) {
				if (bx) *bx = MAP_TIP_SIZE * (x + i) - ix - (1 - i * 2);
				return t;
			}
		}
		iy -= MAP_TIP_SIZE;
		if (iy < 1) iy = 1;
	}
	return t;
}

int CBase::FloorCheck(int *by) {
	int t = 0;
	int sx = m_rect.m_right - m_rect.m_left;
	int sy = m_rect.m_bottom - m_rect.m_top;
	int w = sx / MAP_TIP_SIZE;
	if (w == 0) w = 1;
	int ix = m_rect.m_right;
	int x, y;
	for (int i = 0; i <= w; i++) {
		int iy = m_rect.m_bottom;
		for (int i = 0; i < 2; i++, iy -= sy) {
			t = g_map->GetTipNo(m_old_pos.x + ix, m_pos.y + iy, &x, &y);
			if (t != 0) {
				if (by) *by = MAP_TIP_SIZE * (y + i) - iy;
				return t;
			}
		}
		ix -= MAP_TIP_SIZE;
		if (ix < 0) ix = 0;
	}
	return t;
}