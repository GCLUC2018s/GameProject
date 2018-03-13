#include "CFieldGround.h"

CFieldGround::CFieldGround():CObjectBase(0,eU_Map,eD_Map){
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Ground"));
	m_img.SetSize(4000, 950);
	m_img.SetCenter(0, 230);

}

CFieldGround::~CFieldGround(){

}

void CFieldGround::Update(){

}
