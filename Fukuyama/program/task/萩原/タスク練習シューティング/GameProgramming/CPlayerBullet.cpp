#include "CPlayerBullet.h"
#include "Cdefine.h"
#include "CMain.h"

void CPlayerBullet::Draw(){
	tPlayerBullet.DrawImage(mLeft, mRight, mBottom, mTop, 0, 32, 32, 0);
}

void CPlayerBullet::Update(){
	mBottom+=BULLET_SPEED;
	mTop+=BULLET_SPEED;

	if (mBottom > W_V/2){
		SetKill();
	}
}