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

	pl = dynamic_cast<CPlayer*>(CTaskManager::GetInstance()->GetTask(eID_Player));
	boss = dynamic_cast<CBoss*>(CTaskManager::GetInstance()->GetTask(eID_Boss));

	if (pl) m_pl_hp_base = PLAYER_HP;
	if (boss)m_boss_hp_base = BOSS_HP;
}

void CHPBar::Update()
{
	if (pl) {
		m_pl_hp = pl->GetHP();
	}
	if (boss) {
		m_boss_hp = boss->GetHP();
		CheckOverlap();
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
	m_img_PLbar.SetSize(180 * (m_pl_hp / m_pl_hp_base), 20);
	m_img_PLbar.SetRect(0, 0, 180 * (m_pl_hp / m_pl_hp_base), 20);
	m_img.Draw();
	m_img_PLbase.Draw();
	m_img_PLbar.Draw();
}

void CHPBar::Boss_Hp_Draw()
{
	m_img_Bossbar.SetRect(0, 0, 950 * (m_boss_hp / m_boss_hp_base), 50);
	m_img_Bossbar.SetSize(950 * (m_boss_hp / m_boss_hp_base), 50);
	m_img_Bossbase.Draw();
	m_img_Bossbar.Draw();
}
