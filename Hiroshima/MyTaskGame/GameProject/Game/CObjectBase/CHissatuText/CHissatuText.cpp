#include "CHissatuText.h"

CHissatuText::CHissatuText() : CObjectBase(eID_UI, eU_UI, eD_UI)
{
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Hissatu"));
	m_img2 = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Hissatu"));
	m_img.SetRect(0, 0, 197, 197);
	m_img2.SetRect(197, 0, 197 * 2, 197);
	m_img.SetSize(197, 197);
	m_img2.SetSize(197, 197);
	m_img.SetCenter(197 / 2, 197 / 2);
	m_img2.SetCenter(197 / 2, 197 / 2);
	m_img.SetPos(SCREEN_WIDTH / 2 - 300, SCREEN_HEIGHT / 2);
	m_img2.SetPos(SCREEN_WIDTH / 2 + 300, SCREEN_HEIGHT / 2);
	m_color.w = 0;
	m_color.x = -1.5;
	m_time = 0;

}

CHissatuText::~CHissatuText()
{
}

void CHissatuText::Update()
{
	m_color.w += 0.05;
	m_color.x += 0.05;
	if (m_color.w > 0.85 && m_color.w < 0.90)SOUND("SE_KAKERA")->Play(false);
	if (m_color.x > 0.85 && m_color.x < 0.90)SOUND("SE_KAKERA")->Play(false);
	if (!m_deathblow)SetKill();
	CheckOverlap();
}

void CHissatuText::Draw()
{
	m_img.SetColor(1, 1, 1, m_color.w);
	m_img2.SetColor(1, 1, 1, m_color.x);
	m_img.Draw();
	m_img2.Draw();
}
