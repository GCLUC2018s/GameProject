#include "CGimmick.h"
/*

êªçÏé“Å@âÕñÏ

*/
TexAnim _fire[] = {
	{ 0,1 },
	{ 1,1 },
	{ 2,1 },
	{ 3,1 },
	{ 4,1 },
	{ 5,1 },
	{ 6,1 },
	{ 7,1 },
	{ 8,1 },
	{ 9,1 },
	{ 10,1 },
	{ 11,1 },
	{ 12,1 },
	{ 13,1 },
	{ 14,1 },
	{ 15,1 },
	{ 16,1 },
	{ 17,1 },
	{ 18,1 },
	{ 19,1 },
	{ 20,1 },
	{ 21,1 },
	{ 22,1 },
	{ 23,1 },
	{ 24,1 },
	{ 25,1 },
	{ 26,1 },
	{ 27,1 },
	{ 28,1 },
	{ 29,1 },
	{ 30,1 },
	{ 31,1 },
	{ 32,1 },
	{ 33,1 },
	{ 34,1 },
	{ 35,1 },
	{ 36,1 },
	{ 37,1 },
	{ 38,1 },
	{ 39,1 },
	{ 40,1 },
	{ 41,1 },
	{ 42,1 },
	{ 43,1 },
	{ 44,1 },
	{ 45,1 },
	{ 46,1 },
	{ 47,1 },
};

TexAnimData fire_data[] = {
	ANIMDATA(_fire),
};
CGimmick::CGimmick(CVector2D pos):CBase(eTagUI){
	m_img.SetSize(30, 200);
	m_pos = pos;
	m_rect = CRect(0, 0, 30, 200);
	ADD_RESOURCE("Fire", CAnimImage::LoadImage("fire.png", fire_data, 30, 200));
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Fire"));

}

CGimmick::~CGimmick(){
}

void CGimmick::Update(){

	m_img.ChangeAnimation(0);
	m_img.UpdateAnimation();
}

/*
//Ç±Ç±Ç©ÇÁ
GM1 = new CGimmick(CVector2D(500, 500));
GM2 = new CGimmick(CVector2D(250, 500));
GM3 = new CGimmick(CVector2D(500, 250));

//Ç±Ç±Ç©ÇÁ
GM1->Draw();
GM2->Draw();
GM3->Draw();

//Ç±Ç±Ç©ÇÁ
GM1->Update();
GM2->Update();
GM3->Update();

//Ç±Ç±Ç©ÇÁ
CBase* GM1;
CBase* GM2;
CBase* GM3;
*/