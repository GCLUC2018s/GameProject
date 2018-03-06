//�w�b�_�[�t�@�C��
#include "gameclear_screen.h"

//�R���X�g���N�^
CGameClearScreen::CGameClearScreen()
{
	m_state = GAMECLEAR_SCREEN;
}

//�f�X�g���N�^
CGameClearScreen::~CGameClearScreen(){}

//���[�h
void CGameClearScreen::Load(){}

//�����[�X
void CGameClearScreen::Release(){}

//������
void CGameClearScreen::Init(){}

//���s����
void CGameClearScreen::Update()
{
	if (CheckHitKey(KEY_INPUT_C) == 1) m_state = TITLE_SCREEN;
}

//�`��
void CGameClearScreen::Draw()
{
	ClearDrawScreen();
	DrawString(10, 100, "SELECT Screen Hit C key to Title Screen", GetColor
		(255, 255, 255));
}

//���̃X�e�[�W��
SCREEN CGameClearScreen::GetNextScreen()
{
	return(m_state);
}