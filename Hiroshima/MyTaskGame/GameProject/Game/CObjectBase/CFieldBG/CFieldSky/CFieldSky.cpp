#include "CFieldSky.h"

CFieldSky::CFieldSky() : CObjectBase(0,eU_Map, eD_Back){
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Sky"));
	m_img.SetSize(GROUND_WIDTH, GROUND_HEIGHT);
	m_img.SetCenter(0, GROUND_HEIGHT - SCREEN_HEIGHT);
	m_img_2 = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Sky_Y"));
	m_img_2.SetSize(GROUND_WIDTH, GROUND_HEIGHT);
	m_img_2.SetCenter(0, GROUND_HEIGHT - SCREEN_HEIGHT);
	m_color.w = 0.0;
}

CFieldSky::~CFieldSky(){

}

void CFieldSky::Update(){
	m_color.w += 0.00001;
}

void CFieldSky::Draw()
{
	m_img.SetPos(m_pos3D.x, m_pos3D.y);
	m_img.Draw();
	m_img_2.SetColor(1, 1, 1, m_color.w);
	m_img_2.SetPos(m_pos3D.x, m_pos3D.y);
	m_img_2.Draw();
}
