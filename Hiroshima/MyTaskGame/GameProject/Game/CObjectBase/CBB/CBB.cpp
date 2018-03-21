#include "CBB.h"
#include "../GameProject/Task/CTaskManager.h"
#include "../CMainText/CMainText.h"
#include "../GameProject/Game/CScene/CSceneManager.h"


CBB::CBB(const int &time, const int &flag, const bool &in_flag) :CObjectBase(0, eU_System, eD_Null)
{
	m_scroll = CVector2D(0, 0);
	CTaskManager::GetInstance()->SetPause(eID_Player, true);
	CTaskManager::GetInstance()->SetPause(eID_Enemy, true);
	CTaskManager::GetInstance()->SetPause(eID_Gimmick, true);
	CTaskManager::GetInstance()->SetPause(eID_Magatama, true);
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Tip"));
	m_img.SetSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	m_color = CColorRGBA(0, 0, 0, 1);
	m_cnt = 0;
	m_time = time;
	m_flag = flag;
	m_in_flag = in_flag;
	if(m_flag == 1)
		new CMainText();
}

CBB::~CBB()
{
	//終わったらPause取りやめ
	CTaskManager::GetInstance()->SetPause(eID_Player, false);
	CTaskManager::GetInstance()->SetPause(eID_Enemy, false);
	CTaskManager::GetInstance()->SetPause(eID_Gimmick, false);
	CTaskManager::GetInstance()->SetPause(eID_Magatama, false);
	switch (m_flag)
	{
	case 1:
		SOUND("BGM_Main")->Play(true);
		break;
	case 2:
		NEW_SCENE(eBoss)
			break;
	default:
		break;
	}
}

void CBB::Update()
{
	CTaskManager::GetInstance()->SetPause(eID_Player, true);
	CTaskManager::GetInstance()->SetPause(eID_Enemy, true);
	CTaskManager::GetInstance()->SetPause(eID_Gimmick, true);
	CTaskManager::GetInstance()->SetPause(eID_Magatama, true);

	if (m_in_flag) {
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
		if (m_color.w < -0.5) {
			SetKill();
		}
	}
	else {
		if (m_color.w > BB_COL_PA) {

			//フェードアウト処理
			m_color.w -= BB_COL_DOWN_2;
		}
		else {
			m_cnt++;
			if (m_cnt > m_time) {
				//指定秒間表示したら、フェードアウトし始める
				m_color.w -= BB_COL_DOWN_2;
			}
		}
		if (m_color.w < -3.0) {
			SetKill();
		}
	}
	CheckOverlap();
}




void CBB::Draw()
{
	if (m_in_flag)
		m_img.SetColor(0, 0, 0, m_color.w);
	else
		m_img.SetColor(0, 0, 0, 1.0 - m_color.w);
	m_img.SetPos(0,0);
	m_img.Draw();
}