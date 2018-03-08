#include "CPlayer.h"

/*

êßçÏé“Å@òZé‘Å@

*/

CPlayer::CPlayer():CBase(eTagPlayer){
	m_vec = CVector2D(10, 10);
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Player"));
	m_img.SetSize(256,256);
	m_img.SetFlipH(m_flipH);
	m_punch = false;
}

CPlayer::~CPlayer(){
}

void CPlayer::Update() {
	m_move = false;
	m_squat = false;
	m_punch = false;
	if (HOLD_X) {
		m_squat = true;
		m_anim = 3;
	}
	if (!m_squat) {
		if (HOLD_UP) {
			m_pos.y -= m_vec.y;
			m_move = true;
			m_anim = 1;
		}
		if (HOLD_DOWN) {
			m_pos.y += m_vec.y;
			m_move = true;
			m_anim = 1;
		}
		if (HOLD_RIGHT) {
			m_pos.x += m_vec.x;
			m_move = true;
			m_flipH = false;
			m_anim = 1;
		}
		if (HOLD_LEFT) {
			m_pos.x -= m_vec.x;
			m_move = true;
			m_flipH = true;
			m_anim = 1;
		}
		if (PUSH_C) {
			m_punch = true;
			m_anim = 4;
			m_pos.x++;

		}
	}else{
		m_anim = 0;
	}
	//if (PUSH_Z) {

	//}
	

	m_img.ChangeAnimation(m_anim);
	if (m_anim == 4 && m_img.GetIndex() == 3) {
		m_anim = 0;
	}
	if (m_squat&&m_img.GetCount() == 1) {

	}
	else {
		m_img.UpdateAnimation();
	}
}

void CPlayer::Draw(){
	m_img.SetFlipH(!m_flipH);
	m_img.SetPos(m_pos - m_scroll);
	m_img.Draw();
}
