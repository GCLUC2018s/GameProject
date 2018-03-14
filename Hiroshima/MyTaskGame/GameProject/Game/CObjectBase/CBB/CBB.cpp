#include "CBB.h"
#include "../GameProject/Task/CTaskManager.h"

CBB::CBB(const int time) :CObjectBase(0, eU_Back, eD_UI)
{
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Tip"));
	m_img.SetSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	//CTaskManager::GetInstance()->SetPause(eID_Player, true);
	m_color = CColorRGBA(0, 0, 0, 1);
	m_cnt = 0;
	m_time = time;
}

CBB::~CBB()
{
	//終わったらエネミー生成
	CTaskManager::GetInstance()->SetPause(eID_Player, false);
	SOUND("BGM_Main")->Play(true);
}

void CBB::Update()
{
	m_img.SetColor(0, 0, 0, m_color.w);
	if (m_color.w > 0.7) {
		m_color.w -= 0.05;
	}
	else {
		m_cnt++;
		if (m_cnt > m_time) {
			m_color.w -= 0.05;
		}
	}
	if (m_color.w < -1.0) {
		SetKill();
	}
}
