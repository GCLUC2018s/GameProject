#include "COage.h"

COage::COage(CVector3D * pos) :CObjectBase(0, eU_Item, eD_Item) {
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Oage"));
	m_img.SetRect(0, 256, 64, 320);
	m_img.SetSize(64, 64);
	m_pos3D = *pos;

}

COage::~COage() {

}

void COage::Update() {

}