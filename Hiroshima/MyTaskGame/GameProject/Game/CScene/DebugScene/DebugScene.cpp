#include "DebugScene.h"
#include "../CSceneManager.h"

CDebugScene::CDebugScene() :CObjectBase(0, eU_System, eD_Null), m_font("HG丸ｺﾞｼｯｸM-PRO", 20)
{
	m_scene_num = -1;
}

CDebugScene::~CDebugScene()
{
	NEW_SCENE(m_scene_num + 1)
}

void CDebugScene::Update()
{
	if (CInput::GetState(0, CInput::ePush, CInput::eNum0)) {
		//最初から
		m_scene_num = 0;
	}
	if (CInput::GetState(0, CInput::ePush, CInput::eNum1)) {
		//タイトルから
		m_scene_num = 1;
	}
	if (CInput::GetState(0, CInput::ePush, CInput::eNum2)) {
		//メインから
		m_scene_num = 2;
	}
	if (CInput::GetState(0, CInput::ePush, CInput::eNum3)) {
		//ボスから
		m_scene_num = 0;
	}
	if (CInput::GetState(0, CInput::ePush, CInput::eNum4)) {
		//エンディングから
		m_scene_num = 0;
	}
	if (m_scene_num > -1) {
		SetKill();
	}

}

void CDebugScene::Draw()
{
	m_font.Draw(SCREEN_WIDTH / 2 - 150, SCREEN_HEIGHT / 2 - 150, 1, 1, 0,	"数字入力後　エンター");
	m_font.Draw(SCREEN_WIDTH / 2 - 150, SCREEN_HEIGHT / 2 - 100, 1, 1, 1,	"0　:　最初から　　　　");
	m_font.Draw(SCREEN_WIDTH / 2 - 150, SCREEN_HEIGHT / 2 - 50, 1, 1, 1,	"1　:　タイトルから　　");
	m_font.Draw(SCREEN_WIDTH / 2 - 150, SCREEN_HEIGHT / 2	, 1, 1, 1,		"2　:　メインから　　　");
	m_font.Draw(SCREEN_WIDTH / 2 - 150, SCREEN_HEIGHT / 2 + 50, 1, 1, 1,	"3　:　ボスから　　　　");
	m_font.Draw(SCREEN_WIDTH / 2 - 150, SCREEN_HEIGHT / 2 + 100, 1, 1, 1,	"4　:　エンディングから");

}
