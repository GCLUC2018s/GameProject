#include "CCutIn.h"

CCutIn::CCutIn() :CObjectBase(0, eU_Back, eD_UI)
{
	SOUND("SE_KKN")->Play(false);
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("CutIn"));
	m_img.SetSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	m_pos3D.x = SCREEN_WIDTH;
	m_color.w = 0.0;
}

CCutIn::~CCutIn()
{
}

void CCutIn::Update()
{
	m_pos3D.x = Price_Down(m_pos3D.x, 0, 100);
	if (m_pos3D.x > 0)
		m_color.w += 0.1;
	else
		m_color.w -= 0.1;

	if (m_color.w < -1.0) SetKill();
}
