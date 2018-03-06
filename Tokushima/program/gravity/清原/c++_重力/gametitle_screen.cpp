//�w�b�_�[�t�@�C��
#include "gametitle_screen.h"

//�R���X�g���N�^
CGameTitleScreen::CGameTitleScreen()
{
	m_state = TITLE_SCREEN;
}

//�f�X�g���N�^
CGameTitleScreen::~CGameTitleScreen(){}

//���[�h
void CGameTitleScreen::Load(){}

//�����[�X
void CGameTitleScreen::Release(){}

//������
void CGameTitleScreen::Init(){}

//���s����
void CGameTitleScreen::Update()
{
	
	if (CheckHitKey(KEY_INPUT_A) == 1) m_state = GAME_SCREEN;
}

//�`��
void CGameTitleScreen::Draw()
{
	ClearDrawScreen();
	DrawString(10, 100, "TITLE Screen Hit A key to Next Screen", GetColor
		(255, 255, 255));
}

//���̃X�e�[�W��
SCREEN CGameTitleScreen::GetNextScreen()
{
	return(m_state);
}