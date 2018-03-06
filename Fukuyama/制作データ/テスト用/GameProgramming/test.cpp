#include "test.h"
#include "CCollision.h"
#define KEY(a) GetKeyState(a)&0x8000
test2 tes2;
void test::Init(){
	tes2.SetVer(-120, 120, 100, 120);
	SetVer(-30, 30, -30, 30);
}
void test::Update(){
	if (KEY('W')){
		mTop+=5;
		mBottom+=5;
	}
	if (KEY('A')){
		mLeft-=5;
		mRight-=5;
	}
	if (KEY('S')){
		mBottom-=5;
		mTop-=5;
	}
	if (KEY('D')){
		mLeft+=5;
		mRight+=5;
	}
	if (CCollision::CollisionX(this, tes2)){
		mLeft += mAjust;
		mRight += mAjust;
	}
	 if (CCollision::CollisionY(this, tes2)){
		mTop += mAjust;
		mBottom += mAjust;
	}
}
void test::Render(){
	tes2.mEnabled = true;
	tes2.RectRender();
	mEnabled = true;
	RectRender();
}