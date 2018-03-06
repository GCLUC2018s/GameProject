#include "CEnemy.h"
/*

»ìÒ@Â–Ø

*/
CEnemy::CEnemy(CVector2D pos) :CBase(eTagEnemy) {
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Enemy"));
	m_img.SetSize(213, 256);
	m_pos=pos;
}

CEnemy::~CEnemy() {
}

void CEnemy::Update() {
	m_img.ChangeAnimation(0);
	m_img.UpdateAnimation();
}