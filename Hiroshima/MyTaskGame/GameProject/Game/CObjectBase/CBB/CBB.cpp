#include "CBB.h"
#include "../GameProject/Task/CTaskManager.h"
#include "../CMainText/CMainText.h"
#include "../GameProject/Game/CScene/CSceneManager.h"


CBB::CBB(const int &time, const int &flag, const bool &in_flag) :CObjectBase(0, eU_System, eD_Null), m_contn("HG�s����",50)
{
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
	//�I�������Pause�����
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
	case 4:
		if (m_vec3D.y == 0)
			NEW_SCENE(eMain)
		if (m_vec3D.y == 150)
			NEW_SCENE(eGameStart)
			//�{���̓Q�[���I�[�o�[
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

	if (m_flag != 3) {
		if (m_in_flag) {
			if (m_color.w > BB_COL_PA) {

				//�t�F�[�h�A�E�g����
				m_color.w -= BB_COL_DOWN;
			}
			else {
				m_cnt++;
				if (m_cnt > m_time) {
					//�w��b�ԕ\��������A�t�F�[�h�A�E�g���n�߂�
					m_color.w -= BB_COL_DOWN;
				}
			}
			if (m_color.w < -0.5) {
				SetKill();
			}
		}
		else {
			if (m_color.w > BB_COL_PA) {

				//�t�F�[�h�A�E�g����
				m_color.w -= BB_COL_DOWN_2;
			}
			else {
				m_cnt++;
				if (m_cnt > m_time) {
					//�w��b�ԕ\��������A�t�F�[�h�A�E�g���n�߂�
					m_color.w -= BB_COL_DOWN_2;
				}
			}
			if (m_color.w < -3.0) {
				SetKill();
			}
		}
	}
	else {
			if (m_color.w > BB_COL_PA) {

				//�t�F�[�h�A�E�g����
				m_color.w -= BB_COL_DOWN_2;
			}
			if (PUSH_UP)
				m_vec3D.y = 0;
			if(PUSH_DOWN)
				m_vec3D.y = 150;
			if (PUSH_ENTER)
				m_flag = 4;
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
	if (m_flag > 2) {
		m_contn.Draw(SCREEN_WIDTH / 2 - 210, SCREEN_HEIGHT / 2 - 150, 1, 1, 1, "�܂���ȁ@�t���c�I");
		m_contn.Draw(SCREEN_WIDTH / 2 - 210, SCREEN_HEIGHT / 2 , 1, 1, 1, "�@�@���������ǁ@");
		m_contn.Draw(SCREEN_WIDTH / 2 - 210, SCREEN_HEIGHT / 2 + 150, 1, 1, 1, "�@�@������߂�@");
		m_contn.Draw(SCREEN_WIDTH / 2 - 250, SCREEN_HEIGHT / 2 + m_vec3D.y, 1, 1, 1, "�@�ˁ@�@�@�@�@�@�@");
	}
}