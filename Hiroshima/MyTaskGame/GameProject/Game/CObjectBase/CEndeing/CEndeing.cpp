#include "CEndeing.h"
#include "../GameProject/Game/CScene/CSceneManager.h"

CEnding::CEnding() :CObjectBase(0, eU_Back, eD_UI)
{
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("EndStaff"));
	m_img.SetSize(ENDEING_SIZ_X / 2, ENDEING_SIZ_Y / 2);
	m_img.SetCenter(ENDEING_SIZ_X / 4, 0);
	m_pos3D = CVector3D(SCREEN_WIDTH / 2, SCREEN_HEIGHT * 1.2, 0);
	m_color.w = 2.0;
	SOUND("BGM_Ending")->Play(false);
}

CEnding::~CEnding()
{
	SOUND("BGM_Ending")->Stop();
	NEW_SCENE(eGameStart)
}

void CEnding::Update()
{
	if (m_pos3D.y - SCREEN_HEIGHT / 1.1 + ENDEING_SIZ_Y / 2 > 0)
		m_pos3D.y--;
	else
		m_color.w -= 0.01;

	if (m_color.w < -1.0) {
		SetKill();
	}
}

void CEnding::Draw()
{
	m_img.SetColor(m_color.x, m_color.y, m_color.z, m_color.w);
	m_img.SetPos(m_pos3D.x, m_pos3D.y);
	m_img.Draw();
}