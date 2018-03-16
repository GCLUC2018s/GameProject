#include "DebugScene.h"
#include "../CSceneManager.h"

CDebugScene::CDebugScene() :CObjectBase(0, eU_System, eD_Null), m_font("HG�ۺ޼��M-PRO", 20)
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
		//�ŏ�����
		m_scene_num = 0;
	}
	if (CInput::GetState(0, CInput::ePush, CInput::eNum1)) {
		//�^�C�g������
		m_scene_num = 1;
	}
	if (CInput::GetState(0, CInput::ePush, CInput::eNum2)) {
		//���C������
		m_scene_num = 2;
	}
	if (CInput::GetState(0, CInput::ePush, CInput::eNum3)) {
		//�{�X����
		m_scene_num = 0;
	}
	if (CInput::GetState(0, CInput::ePush, CInput::eNum4)) {
		//�G���f�B���O����
		m_scene_num = 0;
	}
	if (m_scene_num > -1) {
		SetKill();
	}

}

void CDebugScene::Draw()
{
	m_font.Draw(SCREEN_WIDTH / 2 - 150, SCREEN_HEIGHT / 2 - 150, 1, 1, 0,	"�������͌�@�G���^�[");
	m_font.Draw(SCREEN_WIDTH / 2 - 150, SCREEN_HEIGHT / 2 - 100, 1, 1, 1,	"0�@:�@�ŏ�����@�@�@�@");
	m_font.Draw(SCREEN_WIDTH / 2 - 150, SCREEN_HEIGHT / 2 - 50, 1, 1, 1,	"1�@:�@�^�C�g������@�@");
	m_font.Draw(SCREEN_WIDTH / 2 - 150, SCREEN_HEIGHT / 2	, 1, 1, 1,		"2�@:�@���C������@�@�@");
	m_font.Draw(SCREEN_WIDTH / 2 - 150, SCREEN_HEIGHT / 2 + 50, 1, 1, 1,	"3�@:�@�{�X����@�@�@�@");
	m_font.Draw(SCREEN_WIDTH / 2 - 150, SCREEN_HEIGHT / 2 + 100, 1, 1, 1,	"4�@:�@�G���f�B���O����");

}
