
//�w�b�_�[�t�@�C��
#include "game_screen.h"

//�R���X�g���N�^
CGameScreen::CGameScreen()
{
	m_state = GAME_SCREEN;
}

//�f�X�g���N�^
CGameScreen::~CGameScreen(){}

//���[�h
void CGameScreen::Load(){
	//map.loadMap();
	//map.loadItem();
}

//�����[�X
void CGameScreen::Release(){}

//������
void CGameScreen::Init(){}

//���s����
void CGameScreen::Update()
{
	if (CheckHitKey(KEY_INPUT_E) == 1) m_state = GAMEOVER_SCREEN;
	if (CheckHitKey(KEY_INPUT_F) == 1) m_state = GAMECLEAR_SCREEN;
}

//�`��
void CGameScreen::Draw()
{
	ClearDrawScreen();
	//map.drawMap();
	DrawString(10, 100, "Game Screen Hit E key to Gameover Screen\n F key to Gameclear Screen", GetColor
		(255, 255, 255));
}

//���̃X�e�[�W��
SCREEN CGameScreen::GetNextScreen()
{
	return(m_state);
}