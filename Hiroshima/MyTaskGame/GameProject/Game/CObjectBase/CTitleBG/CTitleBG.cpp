#include "CTitleBG.h"
#include "../GameProject/Game/CScene/CSceneManager.h"

CTitleBG::CTitleBG() :CObjectBase(0, eUDP_Tutorial, eDWP_Null)
{
	m_img = *dynamic_cast<CAnimImage*>(GET_RESOURCE("Title"));
	m_img.SetSize(SCREEN_WIDTH, SCREEN_HEIGHT);
}

CTitleBG::~CTitleBG()
{
}

void CTitleBG::Update()
{
	if (PUSH_ENTER) {
		NEW_SCENE(eMain)
		m_destroyFlg = true;
	}
}
