#include "CPlayer.h"

/*

êßçÏé“Å@òZé‘Å@

*/

CPlayer::CPlayer():CBase(eTagPlayer){
	m_vec = CVector2D(10, 10);
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Player"));
	m_img.SetSize(256,256);
	m_img.SetFlipH(m_flipH);
}

CPlayer::~CPlayer(){
}

void CPlayer::Update() {
	m_move = false;
	m_squat = false;
	m_punch = false;
	if (HOLD_X) {
		m_squat = true;
	}
	if (!m_squat) {
		if (HOLD_UP) {
			m_pos.y -= m_vec.y;
			m_move = true;
		}
		if (HOLD_DOWN) {
			m_pos.y += m_vec.y;
			m_move = true;
		}
		if (HOLD_RIGHT) {
			m_pos.x += m_vec.x;
			m_move = true;
			m_flipH = false;
		}
		if (HOLD_LEFT) {
			m_pos.x -= m_vec.x;
			m_move = true;
			m_flipH = true;
		}
	}
	if (HOLD_C) {
		m_punch = true;
	}
	//if (PUSH_Z) {

	//}

	if (m_move) {
		m_img.ChangeAnimation(eAnimDash);
	}else if (m_squat) {
		m_img.ChangeAnimation(eAnimSquat);
	}/*else if (m_punch) {
		m_img.ChangeAnimation(eAnimPunch);
	}*/else{
		m_img.ChangeAnimation(eAnimIdol);
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
