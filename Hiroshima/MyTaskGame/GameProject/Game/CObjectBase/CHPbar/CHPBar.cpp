#include "CHPBar.h"
#include "../CPlayer/CPlayer.h"
#include "../CEnemy/CBoss.h"
#include "../GameProject/Task/CTaskManager.h"

CHPBar::CHPBar(const bool &boss_flag) : CObjectBase(eID_UI, eU_UI, eD_UI)
{
	m_boss_flag = boss_flag;
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("HP_Icon_PL"));
	m_img_Bossbase = *dynamic_cast<CAnimImage*>(GET_RESOURCE("HP_Bar_Boss_Base"));
	m_img_Bossbar = *dynamic_cast<CAnimImage*>(GET_RESOURCE("HP_Bar_Boss"));
	m_img_PLbase = *dynamic_cast<CAnimImage*>(GET_RESOURCE("HP_Bar_PL_Base"));
	m_img_PLbar = *dynamic_cast<CAnimImage*>(GET_RESOURCE("HP_Bar_PL"));
	//setsize
	m_img.SetSize(90, 90);
	m_img_Bossbase.SetSize(950, 50);
	m_img_Bossbar.SetSize(950, 50);
	m_img_PLbase.SetSize(180, 20);
	m_img_PLbar.SetSize(180, 20);
	//setpos
	m_img.SetPos(108, 14);
	m_img_PLbase.SetPos(118, 96);
	m_img_PLbar.SetPos(118, 96);
	m_img_Bossbase.SetPos(156, 650);
	m_img_Bossbar.SetPos(156, 650);
}

void CHPBar::Update()
{
	CPlayer * pl = dynamic_cast<CPlayer*>(CTaskManager::GetInstance()->GetTask(eID_Player));
	CBoss * boss = dynamic_cast<CBoss*>(CTaskManager::GetInstance()->GetTask(eID_Boss));
	if (pl) {
		m_pl_hp = pl->GetHP();
		m_img_PLbar.SetSize(180 * (m_pl_hp / 10), 20);
		m_img_PLbar.SetRect(0, 0, 180 * (m_pl_hp / 10), 20);
	}
	if (boss) {
		m_boss_hp = boss->GetHP();
		m_img_Bossbar.SetRect(0, 0, 950 * (m_boss_hp / 100), 50);
		m_img_Bossbar.SetSize(950 * (m_boss_hp / 100), 50);
	}
}

void CHPBar::Draw()
{
	if (m_boss_flag) {
		//É{ÉX
		Boss_Hp_Draw();
	}
	else {
		//PL
		PL_Hp_Draw();
	}
}

void CHPBar::PL_Hp_Update()
{
}

void CHPBar::Boss_Hp_Update()
{
}

void CHPBar::PL_Hp_Draw()
{
	m_img.Draw();
	m_img_PLbase.Draw();
	m_img_PLbar.Draw();
}

void CHPBar::Boss_Hp_Draw()
{
	m_img_Bossbase.Draw();
	m_img_Bossbar.Draw();
}
