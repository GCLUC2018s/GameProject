#include "CMainText.h"


CMainText::CMainText() :CObjectBase(0, eU_UI, eD_UI)
{
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("MainText"));
	m_img.SetRect(0, 0, MAIN_TEXT_X, MAIN_TEXT_Y);
	m_img.SetSize(MAIN_TEXT_X / 2, MAIN_TEXT_Y / 2);
	m_img.SetCenter(MAIN_TEXT_X / 4, MAIN_TEXT_Y / 4);
	m_pos3D = CVector3D(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0);
	m_color = CColorRGBA(1, 1, 1, -1.0);
	m_end_flag = false;
	SOUND("SE_DDN")->Play(false);
}

CMainText::~CMainText()
{
}

void CMainText::Update()
{
		m_img.SetColor(1, 1, 1, m_color.w);
	if (m_end_flag == false) {
		//フェードイン
		m_color.w += MAIN_TEXT_UP;
		if (m_color.w > MAIN_TEXT_UP * MAIN_TEXT_TIME) {
			m_end_flag = true;
		}
	}
	else {
		//アウト
		m_color.w -= MAIN_TEXT_UP;
		if (m_color.w < 0) {
			SetKill();
		}
	}
}
