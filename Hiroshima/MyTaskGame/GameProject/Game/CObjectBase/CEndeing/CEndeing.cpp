#include "CEndeing.h"
#include "../GameProject/Game/CScene/CSceneManager.h"

CEnding::CEnding() :CObjectBase(0, eU_Back, eD_Null)
{
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("EndStaff"));
	m_img.SetCenter(ENDEING_SIZ_X / 4, 0);
	m_img.SetSize(ENDEING_SIZ_X / 2, ENDEING_SIZ_Y / 2);
	m_pos3D.x = SCREEN_WIDTH / 2;
	m_pos3D.y = SCREEN_HEIGHT;
	SOUND("BGM_Ending")->Play(false);
	m_vol = 1.0f;
}

CEnding::~CEnding()
{
	SOUND("BGM_Ending")->Stop();
	NEW_SCENE(eTitle)
}

void CEnding::Update()
{
	m_pos3D.y--;
	if (m_pos3D.y < - ENDEING_SIZ_Y / 2) {
		m_color.w--;
		SetKill();
	}
}

