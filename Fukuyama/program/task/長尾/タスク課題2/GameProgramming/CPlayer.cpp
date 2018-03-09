#include "CPlayer.h"
#define KEY(a) GetKeyState(a)&0x8000
//#include "random"
//float Erand = rand()%GLUT_WINDOW_WIDTH;
void CPlayer::Init(){
	mTexture.Load("Player.tga");
	mTexture.DrawImage(mLeft, mRight, mBottom, mTop, 0, 32, 32, 0);
	SetVer(-16, 16, -16, 16);
}
void CPlayer::Update(){
	if (KEY('W')){
		mTop += 3;
		mBottom += 3;
	}
	if (KEY('A')){
		mLeft -= 3;
		mRight -= 3;
	}
	if (KEY('S')){
		mBottom -= 3;
		mTop -= 3;
	}
	if (KEY('D')){
		mLeft += 3;
		mRight += 3;
	}
}
void CPlayer::Draw(){
	mEnabled = true;
	CRectangle::Render();
}