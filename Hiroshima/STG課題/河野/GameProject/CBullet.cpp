#include "CBullet.h"


CBullet::CBullet(CVector2D pos):CTask(1, 1, 1){
	b_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("date"));
	b_vec = CVector2D(14, 14);
	b_img.SetRect(0, 288, 16, 304);
	b_img.SetSize(32, 32);
	b_pos = CVector2D(pos.x + 14,pos.y);
}

void CBullet::Update(){
	b_pos.y -= b_vec.y;
	if (b_pos.y + 32 < 0) {
		SetKill();
	}
}

void CBullet::Draw(){
	b_img.SetPos(b_pos);
	b_img.Draw();
}
