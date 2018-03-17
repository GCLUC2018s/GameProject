#include "CFieldCloud.h"

CFieldCloud::CFieldCloud(const bool flag) : CObjectBase(0,eU_Map,eD_Cloud){
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Cloud"));
	m_img.SetSize(GROUND_WIDTH, GROUND_HEIGHT);
	m_img.SetCenter(0, GROUND_HEIGHT - SCREEN_HEIGHT);
	//if (flag)
	//	//‚P–‡–Ú
	//	m_pos3D = CVector3D(0, 0, 0);
	//else
	//	//‚Q–‡–Ú
	//	m_pos3D = CVector3D(GROUND_WIDTH, 0, 0);
}

CFieldCloud::~CFieldCloud(){
}
void CFieldCloud::Draw()
{
	m_img.SetPos(m_pos3D.x - m_scroll.x / 8, m_pos3D.y - m_scroll.y / 8);
	m_img.Draw();
}

