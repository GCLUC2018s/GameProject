#include "CGameStart.h"
#include "../GameProject/Game/CScene/CSceneManager.h"

CGameStart::CGameStart() :CObjectBase(eID_Null, eU_Back, eD_Null)
{
	SOUND("SE_GameStart")->Play(false);
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("GameStartText"));
	m_img.SetSize(GAME_START_X, GAME_START_Y);
	m_img.SetCenter(GAME_START_X/2, GAME_START_Y/2);
	m_img.SetRect(0, GAME_START_Y * 2, GAME_START_X * 2, GAME_START_Y * 2);
	m_pos3D = CVector3D(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 - GAME_START_Y / 2, 0);
	m_siz = 0.0;
	m_up_siz = 0.001;
	m_end_flag = false;
	m_color.w = -0.1;
	m_cnt = 0;
}

CGameStart::~CGameStart()
{
	NEW_SCENE(eTitle)
}

void CGameStart::Update()
{
	if (m_end_flag) {
		//フェードアウト
		m_color.w -= 0.03;
		if (m_color.w < -3.0) {
			SetKill();
		}

	}
	else {
		//フェードインと、にゅわーと文字が出てくる
		m_color.w += 0.01;
		m_img.SetSize(GAME_START_X, m_siz);
		m_img.SetRect(0, (GAME_START_Y - m_siz) * 2, GAME_START_X * 2 ,GAME_START_Y * 2);
		m_img.SetCenter(GAME_START_X / 2, m_siz - GAME_START_Y);
		m_siz = Price_Up(m_siz, GAME_START_Y, m_up_siz);
		m_up_siz = Price_Up(m_up_siz, GAME_START_Y, 0.01);
		if (m_siz == GAME_START_Y)
			m_cnt++;
		if (m_cnt == GAME_START_TIME) {
			m_end_flag = true;
		}
	}
}
