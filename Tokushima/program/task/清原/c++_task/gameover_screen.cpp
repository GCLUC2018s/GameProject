
//�w�b�_�[�t�@�C��
#include "gameover_screen.h"

//�R���X�g���N�^
CGameOverScreen::CGameOverScreen()
{
	m_state = GAMEOVER_SCREEN;
}

//�f�X�g���N�^
CGameOverScreen::~CGameOverScreen(){}

//���[�h
void CGameOverScreen::Load(){}

//�����[�X
void CGameOverScreen::Release(){}

//������
void CGameOverScreen::Init(){}

//���s����
void CGameOverScreen::Update()
{
	if (CheckHitKey(KEY_INPUT_C) == 1) m_state = TITLE_SCREEN;
}

//�`��
void CGameOverScreen::Draw()
{
	ClearDrawScreen();
	DrawString(10, 100, "SELECT Screen Hit C key to Title Screen", GetColor
		(255, 255, 255));
}

//���̃X�e�[�W��
SCREEN CGameOverScreen::GetNextScreen()
{
	return( m_state );
}