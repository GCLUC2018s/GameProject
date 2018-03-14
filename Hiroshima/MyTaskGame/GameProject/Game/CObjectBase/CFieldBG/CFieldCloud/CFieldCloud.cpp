#include "CFieldCloud.h"

CFieldCloud::CFieldCloud() : CObjectBase(0,eU_Map,eD_Map){
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Cloud"));
	m_img.SetSize(GROUND_WIDTH, GROUND_HEIGHT);
	m_img.SetCenter(0, GROUND_HEIGHT - SCREEN_HEIGHT);
}

CFieldCloud::~CFieldCloud()
{
}

void CFieldCloud::Update()
{
}
