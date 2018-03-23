#include "CBB.h"
#include "../GameProject/Task/CTaskManager.h"
#include "../CMainText/CMainText.h"
#include "../GameProject/Game/CScene/CSceneManager.h"


CBB::CBB(const int &time, const int &flag, const bool &in_flag) :CObjectBase(0, eU_System, eD_Null), m_contn("HG行書体",50)
{
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Tip"));
	m_img.SetSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	m_color = CColorRGBA(0, 0, 0, 1);
	m_cnt = 0;
	m_time = time;
	m_flag = flag;
	m_in_flag = in_flag;
	if(m_flag == 1)
		new CMainText();
	if (m_flag == 3) {
		MusicStop();
		SOUND("BGM_GameOver")->Play(true);
	}
}

CBB::~CBB()
{
	//終わったらPause取りやめ
	CTaskManager::GetInstance()->SetPause(eID_Player, false);
	CTaskManager::GetInstance()->SetPause(eID_Enemy, false);
	CTaskManager::GetInstance()->SetPause(eID_Gimmick, false);
	CTaskManager::GetInstance()->SetPause(eID_Magatama, false);
	CTaskManager::GetInstance()->SetPause(eID_HPUI, false);
	switch (m_flag)
	{
	case 1:
		SOUND("BGM_Main")->Play(true);
		break;
	case 2:
		NEW_SCENE(eEnd)
			break;
	case 4:
		if (m_vec3D.y == 0)
			NEW_SCENE(eMain)
		if (m_vec3D.y == 150)
			NEW_SCENE(eGameStart)
		break;
	case 5:
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
	CTaskManager::GetInstance()->SetPause(eID_HPUI, true);

	//コンティニュー
	if (m_flag == 3) {
		if (m_color.w > 0.3) {

			//フェードアウト処理
			m_color.w -= BB_COL_DOWN_2;
		}
		if (PUSH_UP) {
			m_vec3D.y = 0;
			SOUND("SE_Cursor")->Play(false);
		}
		if (PUSH_DOWN) {
			SOUND("SE_Cursor")->Play(false);
			m_vec3D.y = 150;
		}
		if (PUSH_ENTER) {
			SOUND("SE_KKN")->Play(false);
			m_flag = 4;
		}
	}//ゲームオーバー
	else if (m_flag == 4) {
		m_color.w -= BB_COL_DOWN_2;

		if (PUSH_ENTER && m_color.w < -2.0 && m_vec3D.y == 150) {
			m_color.w = -100;
		}
		if (m_color.w < (-2.0 -(m_vec3D.y / 10))) {
			SetKill();
		}
	}
	else {
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
	}
	CheckOverlap();
}




void CBB::Draw()
{
	if (m_in_flag)
		m_img.SetColor(0, 0, 0, m_color.w);
	else
		m_img.SetColor(0, 0, 0, 1.0 - m_color.w);
	m_img.SetPos(0, 0);
	m_img.Draw();
	if (m_flag == 3) {
		m_contn.Draw(SCREEN_WIDTH / 2 - 210, SCREEN_HEIGHT / 2 - 150, 1, 1, 1, "まけるな　葉月…！");
		m_contn.Draw(SCREEN_WIDTH / 2 - 210, SCREEN_HEIGHT / 2, 1, 1, 1, "　　もういちど　");
		m_contn.Draw(SCREEN_WIDTH / 2 - 210, SCREEN_HEIGHT / 2 + 150, 1, 1, 1, "　　あきらめる　");
		m_contn.Draw(SCREEN_WIDTH / 2 - 250, SCREEN_HEIGHT / 2 + m_vec3D.y, 1, 1, 1, "　⇒　　　　　　　");
	}

	if (m_flag == 4 && m_color.w < -0.5 && m_vec3D.y == 150) {
		m_contn.Draw(SCREEN_WIDTH / 2 - 250, SCREEN_HEIGHT / 2, 1, 1, 1, "　 ゲームオーバー　");
	}
}