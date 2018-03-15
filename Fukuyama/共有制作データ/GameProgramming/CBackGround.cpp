#include "CBackGround.h"
CTexture mTexture;
#define AAA m_image.m_Left < DISPLAY_LEFT
#define GGG  AAA/DISPLAY_LEFT

C_BackGround::C_BackGround()
:C_Object(E_BG, eUDP_Map, eDWP_Map, 0, 0, -450)
{
	mTexture.Load("Asphalt&Sky.tga");
	m_image.SetVertex(-600, 600, -450, 450); 
}

void C_BackGround::Update(){
	Scroll(&m_Position, m_Scroll);
	if (m_image.m_Left < DISPLAY_LEFT){
		mTexture.DrawImage(m_image.m_Left - DISPLAY_LEFT, m_image.m_Right + 1200, m_image.m_Bottom, m_image.m_Top, 0, 1200, 900, 0);
	}
}
void C_BackGround::Draw(){
	Rect(&m_image, &m_Position);
	mTexture.DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 0, 1200, 900, 0);
}