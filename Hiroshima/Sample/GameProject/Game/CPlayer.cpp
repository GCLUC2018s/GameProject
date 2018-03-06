#include "CPlayer.h"

/*

êßçÏé“Å@òZé‘Å@

*/

CPlayer::CPlayer():CBase(eTagPlayer){
	m_vec = CVector2D(3, 3);
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Player"));
	m_img.SetSize(80 * 2, 96 * 2);
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
		m_flipH = false;
	}
	if (HOLD_LEFT) {
		m_pos.x -= m_vec.x;
		m_move = true;
		m_flipH = true;
	}
	if (m_move){
		m_img.ChangeAnimation(1);
	}else {
		m_img.ChangeAnimation(0);
	}
	m_img.UpdateAnimation();

}
