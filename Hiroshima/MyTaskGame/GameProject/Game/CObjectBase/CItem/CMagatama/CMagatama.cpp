#include "CMagatama.h"
#include "../GameProject/Game/CObjectBase/CMahouzin/CMahouzin.h"

CMagatama::CMagatama() :CObjectBase(eID_Magatama, eU_Item, eD_Object) {
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("UI"));
	m_img.SetRect(0, 0, 128, 128);
	m_img.SetSize(128, 128);
	m_cnt = 0;
}

CMagatama::~CMagatama() {

}

void CMagatama::Update()
{
	if (PUSH_Q) {
		if (m_cnt >= 10) SetAttack();
		else SOUND("SE_BB")->Play(false);
	}
}

void CMagatama::Draw()
{
	m_img.SetRect(128 * m_cnt, 0, 128 + 128 * m_cnt, 128);
	m_img.SetColor(m_color.x, m_color.y, m_color.z, m_color.w);
	m_img.SetPos(m_pos3D.x, m_pos3D.y);
	m_img.Draw();
}

void CMagatama::Hit(CObjectBase * t) {
	if (m_cnt < 10)
		m_cnt++;
}

void CMagatama::SetAttack()
{
	//‚±‚Ì’†‚Å–‚–@w‚ðŒÄ‚ÔB
	//Žè‡‚Í
	/*
	m_cnt‚ª10ˆÈã‚È‚ç0‚É–ß‚·
	‚»‚ÌŒã•KŽE‹Z‚ðŒÄ‚Ô

	*/
	m_cnt = 0;
	new CMahouzin();
	SOUND("SE_KKN")->Play(false);
	//ƒJƒbƒgƒCƒ“”­“®
	//•KŽE‹Z”­“®
}

