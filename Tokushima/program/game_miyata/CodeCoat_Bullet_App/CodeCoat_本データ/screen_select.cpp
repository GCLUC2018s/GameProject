#include "screen_select.h"

//�R���X�g���N�^
CSelectScreen::CSelectScreen()
{
	m_state = SELECT_SCREEN;
}

//�f�X�g���N�^
CSelectScreen::~CSelectScreen(){}

//���[�h
void CSelectScreen::Load(){}

//�����[�X
void CSelectScreen::Release(){}

//������
void CSelectScreen::Init(){}

//���s����
void CSelectScreen::Update()
{
	if (CheckHitKey(KEY_INPUT_C) == 1) m_state = TITLE_SCREEN;
}

//�`��
void CSelectScreen::Draw()
{
	ClearDrawScreen();
	DrawString(10, 100, "SELECT Screen Hit C key to Title Screen", GetColor(255, 255, 255));
}


//���ɃX�e�[�W
SCREEN CSelectScreen::GetNextScreen()
{
	return (m_state);
}