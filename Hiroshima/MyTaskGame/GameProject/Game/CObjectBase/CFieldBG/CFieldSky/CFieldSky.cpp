#include "CFieldSky.h"

CFieldSky::CFieldSky() : CObjectBase(0,eU_Map,eD_Map){
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Sky"));
	m_img.SetSize(GROUND_WIDTH, GROUND_HEIGHT);
	m_img.SetCenter(0, GROUND_HEIGHT - SCREEN_HEIGHT);
}

CFieldSky::~CFieldSky(){

}

void CFieldSky::Update(){

}
