#include "CPlayer.h"

/*

êßçÏé“Å@òZé‘Å@

*/
TexAnim _anim0[] = {
	{ 0,5 },
	{ 1,5 },
	{ 2,5 },
	{ 3,5 },
	{ 4,5 },
	{ 5,5 },
	{ 6,5 },
	{ 7,5 },
	{ 8,5 },
	{ 9,5 },
	{ 10,5 },
	{ 11,5 },
};
TexAnim _anim1[] = {
	{ 52,5 },
	{ 53,5 },
	{ 54,5 },
	{ 55,5 },
	{ 56,5 },
	{ 57,5 },
};

TexAnimData anim_data[] = {
	ANIMDATA(_anim0),
	ANIMDATA(_anim1),
};
CPlayer::CPlayer():CBase(eTagPlayer){
	m_vec = CVector2D(3, 3);
	ADD_RESOURCE("Player", CAnimImage::LoadImage("player1.png", anim_data, 80, 96));
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
