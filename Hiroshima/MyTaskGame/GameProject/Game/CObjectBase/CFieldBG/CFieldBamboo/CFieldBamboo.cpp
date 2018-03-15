#include "CFieldBamboo.h"

CFieldBamboo::CFieldBamboo(const bool flag):CObjectBase(0,eU_Map,eD_Bamboo){
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Bamboo"));
	m_img.SetSize(GROUND_WIDTH, GROUND_HEIGHT);
	m_img.SetCenter(0, GROUND_HEIGHT - SCREEN_HEIGHT);
	//if (flag)
	//	//‚P–‡–Ú
	//	m_pos3D = CVector3D(0, 0, 0);
	//else
	//	//‚Q–‡–Ú
	//	m_pos3D = CVector3D(GROUND_WIDTH, 0, 0);
}

CFieldBamboo::~CFieldBamboo(){
}
void CFieldBamboo::Draw()
{
	m_img.SetPos(m_pos3D.x - m_scroll.x / 1.3, m_pos3D.y - m_scroll.y / 1.1);
	m_img.Draw();
}
