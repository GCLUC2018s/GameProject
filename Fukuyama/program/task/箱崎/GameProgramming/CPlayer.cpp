#include"CPlayer.h"
#include"windows.h"
#include"glut.h"
void CPlayer::Init(){
	CRectangle::SetVertex(-25, 25, -250, -200);
	mTexture.Load("ki.tga");
	CRectangle::SetTexture(&mTexture, 0, 160, 160, 0);
}
void CPlayer::Update(){
	CRectangle::Update();
	if (GetKeyState('W') & 0x8000){
		mTop++;
		mBottom++;
	}
	if (GetKeyState('A') & 0x8000){
		mLeft--;
		mRight--;
	}
	if (GetKeyState('S') & 0x8000){
		mTop--;
		mBottom--;
	}
	if (GetKeyState('D') & 0x8000){
		mLeft++;
		mRight++;
	}
}
void CPlayer::Draw(){
	CRectangle::Render();
}