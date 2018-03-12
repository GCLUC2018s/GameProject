#include "CFieldSky.h"

CFieldSky::CFieldSky() : CObjectBase(0,eUDP_Map,eDWP_Map){
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Sky"));
	m_img.SetSize(SCREEN_WIDTH, SCREEN_HEIGHT);
}

CFieldSky::~CFieldSky(){

}

void CFieldSky::Update(){

}
