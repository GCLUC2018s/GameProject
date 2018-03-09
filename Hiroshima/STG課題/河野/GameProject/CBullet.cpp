#include "CBullet.h"

CImage b_img;
CVector2D b_pos;
CVector2D b_vec;

CBullet::CBullet(CVector2D pos):CTask(1, 1, 1){
	b_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("date"));
	b_vec = CVector2D(4, 4);
	b_img.SetRect(0, 288, 16, 304);
	b_img.SetSize(32, 32);
	b_pos = pos;
}

void CBullet::Update(){
	b_pos.y -= b_vec.y;
}

void CBullet::Draw(){
	b_img.SetPos(b_pos);
	b_img.Draw();
}
