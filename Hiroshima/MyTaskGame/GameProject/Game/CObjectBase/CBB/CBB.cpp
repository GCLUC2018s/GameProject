#include "CBB.h"
#include "../GameProject/Task/CTaskManager.h"
#include "../CMainText/CMainText.h"

#define BB_COL_PA 0.7 //どの濃さで止めるか。
#define BB_COL_DOWN 0.05 //どれくらいずつ減らすか

CBB::CBB(const int time, const bool flag) :CObjectBase(0, eU_System, eD_UI)
{
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Tip"));
	m_img.SetSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	m_color = CColorRGBA(0, 0, 0, 1);
	m_cnt = 0;
	m_time = time;
	if(flag)
		new CMainText();
}

CBB::~CBB()
{
	//終わったらエネミー生成
	CTaskManager::GetInstance()->SetPause(eID_Player, false);
	CTaskManager::GetInstance()->SetPause(eID_Enemy, false);
	CTaskManager::GetInstance()->SetPause(eID_Gimmick, false);
	SOUND("BGM_Main")->Play(true);
}

void CBB::Update()
{
	CTaskManager::GetInstance()->SetPause(eID_Player, true);
	CTaskManager::GetInstance()->SetPause(eID_Enemy, true);
	CTaskManager::GetInstance()->SetPause(eID_Gimmick, true);
	m_img.SetColor(0, 0, 0, m_color.w);
	if (m_color.w > BB_COL_PA) {
		//フェードアウト処理
		m_color.w -= BB_COL_DOWN;
	}
	else {
		m_cnt++;
		if (m_cnt > m_time) {
			//指定秒間表示したら、フェードアウトし始める
			m_color.w -= BB_COL_DOWN;
		}
	}
	if (m_color.w < -1.0) {
		SetKill();
	}
}
