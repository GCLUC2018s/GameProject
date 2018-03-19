#include "CMahouzin.h"

CMahouzin::CMahouzin() : CObjectBase(eID_UI,eU_UI,eD_Ground) {
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Mahouzin"));
	m_img.SetSize(64, 30);
}

CMahouzin::~CMahouzin()
{
}

void CMahouzin::UPdate()
{
}
