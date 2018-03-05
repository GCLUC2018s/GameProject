#include "CBase.h"

CVector2D CBase::m_scroll(0, 0);
std::list<CBase*> g_list;

CBase::CBase(int tag) {
	m_pos = CVector2D(0, 0);
	m_vec = CVector2D(0, 0);
	m_flipH = false;
	m_active = true;
	m_color = 0;
	m_type = 0;
	m_move = false;
}
CBase::~CBase() {

}

//çXêVñΩóﬂ
void CBase::Update() {

}
//ï`âÊñΩóﬂ
void CBase::Draw() {
	m_img.SetFlipH(m_flipH);
	m_img.SetPos(m_pos - m_scroll);
	m_img.Draw();
}


void CBase::HitCallback(CBase* b) {
	m_active = false;
}

