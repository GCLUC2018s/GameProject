#include "gametitle_screen.h"
int stagenum;
//�R���X�g���N�^
CTitleScreen::CTitleScreen()
{
	m_state = TITLE_SCREEN;
}

//�f�X�g���N�^
CTitleScreen::~CTitleScreen() {}

void CTitleScreen::Dest(){}
//���[�h
void CTitleScreen::Load() {
	
}

//������
void CTitleScreen::Init(){
	
}

//���s����
void CTitleScreen::Update()
{
	if (CheckHitKey(KEY_INPUT_A) == 1) m_state = GAME_SCREEN;
}

//�`��
void CTitleScreen::Draw()
{
	ClearDrawScreen();
	DrawString(10, 100, "TITLE Screen Hit A key to Next Screen", GetColor
		(255, 255, 255));
}

//���̃X�e�[�W��
SCREEN CTitleScreen::GetNextScreen()
{
	return (m_state);
}