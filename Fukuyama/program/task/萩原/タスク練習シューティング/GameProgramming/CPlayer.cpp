#include "CPlayer.h"
#include "windows.h"

#define KEY(a) GetKeyState(a)&0x8000
#define SPEED 2

void CPlayer::Draw(){
	tPlayer.DrawImage(mLeft, mRight, mBottom, mTop, 0, 32, 32, 0);
}

void CPlayer::Update(){
	if (KEY('A')){
		mLeft -= SPEED;
		mRight -= SPEED;
	}
	if (KEY('D')){
		mLeft += SPEED;
		mRight += SPEED;
	}
	if (KEY('W')){
		mBottom += SPEED;
		mTop += SPEED;
	}
	if (KEY('S')){
		mBottom -= SPEED;
		mTop -= SPEED;
	}
}

