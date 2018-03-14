#include "CFieldCloud.h"

CFieldCloud::CFieldCloud() : CObjectBase(0,eU_Map,eD_Map){
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Cloud"));
	m_img.SetSize(GROUND_WIDTH, GROUND_HEIGHT);
	m_img.SetCenter(0, GROUND_HEIGHT - SCREEN_HEIGHT);
}

CFieldCloud::~CFieldCloud(){
	new CFieldCloud();
}

void CFieldCloud::Update(){
	m_pos3D = CVector3D(m_scroll.x/1.1, 0, 0);
	if (m_pos3D.x == GROUND_WIDTH) {
		SetKill();
	}
}
