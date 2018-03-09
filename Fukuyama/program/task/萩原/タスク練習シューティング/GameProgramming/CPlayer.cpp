#include "CPlayer.h"
#include "windows.h"
#include "Cdefine.h"
#include "CKey.h"
#include "CPlayerBullet.h"
#include "CTaskManager.h"

void CPlayer::Init(){
	//î≠éÀä¥äoÇÃèâä˙âª
	fire = FIREINTERVAL;
}

void CPlayer::Draw(){
	tPlayer.DrawImage(mLeft, mRight, mBottom, mTop, 0, 32, 32, 0);
}

void CPlayer::Update(){
	if (fire > 0){
		--fire;
	}

	if (CKey::Push('A')){
		mLeft -= SPEED;
		mRight -= SPEED;
	}
	if (CKey::Push('D')){
		mLeft += SPEED;
		mRight += SPEED;
	}
	if (CKey::Push('W')){
		mBottom += SPEED;
		mTop += SPEED;
	}
	if (CKey::Push('S')){
		mBottom -= SPEED;
		mTop -= SPEED;
	}
	if (CKey::Push(VK_RETURN)){
		//íeÇÃê∂ê¨
		if (fire <= 0){
			PlayerBullet = new CPlayerBullet();
			PlayerBullet->Init();
			PlayerBullet->SetVertex(mLeft, mRight, mBottom, mTop);
			CTaskManager::GetInstance()->Add(PlayerBullet);
			fire = FIREINTERVAL;
		}
	}
}

