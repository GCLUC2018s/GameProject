#include "CGo.h"
#include "../CBB/CBB.h"

CGo::CGo(bool end_flag) : CObjectBase(eID_UI,eU_UI,eD_UI)
{
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("GO"));
	m_img.SetSize(GO_SIZ_X, GO_SIZ_Y);
	//m_rect = CRect(GO_SIZ_X / 2 + 64, 0, GO_SIZ_X, GO_SIZ_Y + 300);
	m_pos3D = CVector3D(GO_POS_X + m_scroll.x, 300,0);
	m_wave_flag = false;
	m_end_flag = end_flag;
}

CGo::~CGo()
{
	m_wave_flag = true;
	m_sc_flag_x = false;
	if (m_end_flag) {
		new CBB(0, 5, false);
	}
}

void CGo::Update()
{
	m_pos3D += m_vec3D;
	m_a += GO_TIME;
	m_vec3D.y = sin(m_a);
	if (m_end_flag) {
		if (m_pos3D.x + 300 - m_scroll.x < SCREEN_WIDTH) {
			SetKill();
		}
	}
	else {
		if (m_pos3D.x + GO_SIZ_X - m_scroll.x < 0) {
			SetKill();
		}
	}

	CheckOverlap();
}
