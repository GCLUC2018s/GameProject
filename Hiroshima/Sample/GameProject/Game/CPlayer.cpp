#include "CPlayer.h"

CPlayer::CPlayer():CBase(eTagPlayer){
	m_vec = CVector2D(3, 3);
}

CPlayer::~CPlayer(){
}

void CPlayer::Update(){
		m_move = false;
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
	}
	if (HOLD_LEFT) {
		m_pos.x -= m_vec.x;
		m_move = true;
	}
	if (m_move){
		m_changeanim_num = 1;
	}else {
		m_changeanim_num = 0;
	}
	

}
