#include "CPlayer.h"

CPlayer::CPlayer():CBase(eTagPlayer){
}

CPlayer::~CPlayer(){
}

void CPlayer::Update(){
	if (HOLD_RIGHT) {
		m_pos.x += 2;
	}
}
