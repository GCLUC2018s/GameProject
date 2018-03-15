#include "CItem.h"

CItem::CItem(CVector3D * pos):CObjectBase(0,eU_Item,eD_Item){
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Ohuda"));
	m_img.SetRect(0, 0, 128, 128);
	m_img.SetSize(64,64);
	m_pos3D = *pos;
	
}

CItem::~CItem(){

}

void CItem::Update(){

}
