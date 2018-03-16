#include "CBackGround.h"
CTexture mTexturet;
CTexture mTexturet2;
C_BackGround::C_BackGround()
:C_Object(E_BG, eUDP_Map, eDWP_Map, 0, 0, -450)
{
	mTexturet.Load("Asphalt&Sky.tga");
	mTexturet2.Load("Asphalt&Sky.tga");
	m_image.SetVertex(-600, 600, -450, 450); 
}

void C_BackGround::Update(){
	Scroll(&m_Position, m_Scroll);
	mTexturet.DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 0, 1200, 900, 0);
	mTexturet2.DrawImage(m_image.m_Left+600, m_image.m_Right+600, m_image.m_Bottom, m_image.m_Top, 0, 1200, 900, 0);
}
void C_BackGround::Draw(){
	Rect(&m_image, &m_Position);
}