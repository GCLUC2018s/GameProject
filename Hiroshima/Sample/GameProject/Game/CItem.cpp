#include "CItem.h"

/*

êßçÏé“Å@òZé‘Å@

*/


CItem::CItem(CVector2D pos):CBase(eTagUI){
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Item"));
	m_pos = pos;
	m_img.SetSize(40, 40);
	m_img.SetRect(0, 384, 64, 448);
}

CItem::~CItem(){

}

void CItem::Update(){

}