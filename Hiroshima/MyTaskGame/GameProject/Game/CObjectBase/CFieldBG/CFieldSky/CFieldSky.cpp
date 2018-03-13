#include "CFieldSky.h"

CFieldSky::CFieldSky() : CObjectBase(0,eUDP_Map,eDWP_Map){
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Sky"));
	m_img.SetSize(4000, 950);
	m_img.SetCenter(0, 230);
}

CFieldSky::~CFieldSky(){

}

void CFieldSky::Update(){

}
