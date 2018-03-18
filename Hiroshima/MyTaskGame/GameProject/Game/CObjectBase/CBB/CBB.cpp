#include "CBB.h"
#include "../GameProject/Task/CTaskManager.h"
#include "../CMainText/CMainText.h"
#include "../GameProject/Game/CScene/CSceneManager.h"

#define BB_COL_PA 0.7 //どの濃さで止めるか。
#define BB_COL_DOWN 0.05 //どれくらいずつ減らすか

CBB::CBB(const int time, const int flag, const bool flagin) :CObjectBase(0, eU_System, eD_UI)
{
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Tip"));
	m_img.SetSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	m_img.SetPos(0, 0);
	m_color = CColorRGBA(0, 0, 0, 1);
	m_cnt = 0;
	m_time = time;
	m_flag = flag;
	m_flag_In = flagin;
	if(m_flag == 1)
		new CMainText();
}

CBB::~CBB()
{
	switch (m_flag)
	{
	case 1:
		//終わったらエネミー生成
		CTaskManager::GetInstance()->SetPause(eID_Player, false);
		CTaskManager::GetInstance()->SetPause(eID_Enemy, false);
		CTaskManager::GetInstance()->SetPause(eID_Gimmick, false);
		CTaskManager::GetInstance()->SetPause(eID_Magatama, false);
		SOUND("BGM_Main")->Play(true);
		break;
	case 2:
		NEW_SCENE(eEnd)
		break;
	default:
		break;
	}
}

void CBB::Update()
{
	if (m_flag != 0) {
		CTaskManager::GetInstance()->SetPause(eID_Player, true);
		CTaskManager::GetInstance()->SetPause(eID_Enemy, true);
		CTaskManager::GetInstance()->SetPause(eID_Gimmick, true);
		CTaskManager::GetInstance()->SetPause(eID_Magatama, true);
	}
	
	if (m_flag_In) {
		if (m_color.w > BB_COL_PA) {
			//フェードイン(アウト)処理
			m_color.w -= BB_COL_DOWN - 0.03;
		}
		else {
			m_cnt++;
			if (m_cnt > m_time) {
				//指定秒間表示したら、フェードアウトし始める
				m_color.w -= BB_COL_DOWN - 0.03;
			}
		}
		if (m_color.w < -2.0) {
			SetKill();
		}
	}
	else {
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
	CheckOverlap();
}

void CBB::Draw()
{
	if (m_flag_In)
		m_img.SetColor(m_color.x, m_color.y, m_color.z, 1.0 - m_color.w);
	else
		m_img.SetColor(m_color.x, m_color.y, m_color.z, m_color.w);
	m_img.Draw();

}
