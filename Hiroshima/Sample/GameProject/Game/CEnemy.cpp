#include "CEnemy.h"
/*

����ҁ@��

*/
CEnemy::CEnemy(CVector2D pos) :CBase(eTagEnemy) {
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Enemy"));
	
	m_pos=pos;
	
}

CEnemy::~CEnemy() {
}

void CEnemy::Update() {

	if (m_pos.x < 0) {
		m_flipH = true;
	}

	if (m_pos.x > 1280-213) {
		m_flipH = false;
	}

	if (m_flipH) {
		m_pos.x += 5;
	}
	else {
		m_pos.x -= 5;
	}
	

	/*m_img.ChangeAnimation(0);
	m_img.UpdateAnimation();*/
}

void CEnemy::Draw() {
	m_img.SetPos(m_pos);
	m_img.SetSize(213, 256);
	m_img.SetRect(0, 0, 512, 512);
	m_img.Draw();
}


//���̓z�Ǝ������͂����ꂼ��main.cpp�ɂ���̂ł���ɂ�����㏑�����Ă����Ă��������B
//ADD_RESOURCE("Enemy", CAnimImage::LoadImage("zako_daruma_motion.png"));
//ENE = new CEnemy(CVector2D(500, 450));