#include "CFieldGround.h"

CFieldGround::CFieldGround():CObjectBase(0,eU_Map,eD_Map){
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Ground"));
	m_img.SetSize(GROUND_WIDTH, GROUND_HEIGHT);
	m_img.SetCenter(0, GROUND_HEIGHT - SCREEN_HEIGHT);
	m_rect = CRect(2032, 715, 2424, 1180);
	m_rect_tourou1 = CRect(429, 882, 562, 1138);
	m_rect_tourou2 = CRect(1492, 882, 1625, 1138);
	m_rect_tourou3 = CRect(2878, 882, 3011, 1138);
	m_rect_tourou4 = CRect(3755, 882, 3888, 1138);


}

CFieldGround::~CFieldGround(){

}

void CFieldGround::Update(){

}
