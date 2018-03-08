#include "CPlayer.h"
#include "../stdafx.h"
#include "../Global.h"

CImage p_img;
CVector2D p_pos;
CVector2D p_vec;

CPlayer::CPlayer(){
	p_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("date"));
	p_vec = CVector2D(4, 4);
	p_pos = CVector2D(400, 480);
}

void CPlayer::Update() {
	if (HOLD_UP) {
		p_pos.y -= p_vec.y;
	}
	if (HOLD_DOWN) {
		p_pos.y += p_vec.y;
	}
	if (HOLD_RIGHT) {
		p_pos.x += p_vec.x;
	}
	if (HOLD_LEFT) {
		p_pos.x -= p_vec.x;
	}
};
void CPlayer::Draw() {
	p_img.SetRect(0, 0, 64, 64);
	p_img.SetSize(128, 128);
	p_img.SetPos(p_pos.x, p_pos.y);
	p_img.Draw();
}