#include "staffroll_screen.h"

//�R���X�g���N�^
CStaffRollScreen::CStaffRollScreen()
{
	m_state = STAFFROLL_SCREEN;
	//������
	m_lasttime = GetNowCount() &INT_MAX;
	for (int a = 0; a < STRING_COUNT; a++)
		scroll[a] = 730;
	m_rogoimage = LoadGraph("media\\img\\title_02.png");
	m_count = 0;
	m_alpha = 255;
	m_alphatime = -170;
	//���[�h
	m_largefont = CreateFontToHandle("���C���I", 50, -1, DX_FONTTYPE_ANTIALIASING);
}

//�f�X�g���N�^
CStaffRollScreen::~CStaffRollScreen(){

}

void CStaffRollScreen::Dest(){}

//���s����
void CStaffRollScreen::Update()
{
	/*if (m_count == 0){
		PlaySoundMem(clear_BGM, DX_PLAYTYPE_LOOP);
		m_count = 1;
	}*/
	if (((GetNowCount() & INT_MAX) - m_lasttime) > GAMECLEAR_TIME){
		m_state = TITLE_SCREEN;//���Ԃ͒���
	}

	scroll[0] -= 2;
	if (scroll[0] < 500)
		scroll[1] -= 2;
	if (scroll[1] < 730)
		scroll[2] -= 2;
	if (scroll[2] < 550)
		scroll[3] -= 2;
	if (scroll[3] < 550)
		scroll[4] -= 2;
	if (scroll[4] < 730)
		scroll[5] -= 2;
	if (scroll[5] < 550)
		scroll[6] -= 2;
	if (scroll[6] < 550)
		scroll[7] -= 2;
	if (scroll[7] < 730)
		scroll[8] -= 2;
	if (scroll[8] < 650)
		scroll[9] -= 2;
	if (scroll[9] < 650)
		scroll[10] -= 2;
	if (scroll[10] < 650)
		scroll[11] -= 2;
	else if (scroll[11] == 230){
		if (m_alphatime < 50)
			m_alphatime++;
		if (m_alphatime >= 0){
			m_alpha = 255 - (255 / 35)*m_alphatime;		//����������
		}
	}
}

//�`��
void CStaffRollScreen::Draw()
{
	ClearDrawScreen();
	DrawStringToHandle(100, scroll[0], "����X�^�b�t", GetColor(255, 255, 255), m_largefont, TRUE);
	DrawStringToHandle(100, scroll[1], "�v���O���}�[", GetColor(255, 255, 255), m_largefont, TRUE);
	DrawStringToHandle(500, scroll[2], "������^", GetColor(255, 255, 255), m_largefont, TRUE);
	DrawStringToHandle(500, scroll[3], "�{�c���", GetColor(255, 255, 255), m_largefont, TRUE);
	DrawStringToHandle(100, scroll[4], "�f�U�C�i�[", GetColor(255, 255, 255), m_largefont, TRUE);
	DrawStringToHandle(500, scroll[5], "���M�ڐ�", GetColor(255, 255, 255), m_largefont, TRUE);
	DrawStringToHandle(500, scroll[6], "�{��@��", GetColor(255, 255, 255), m_largefont, TRUE);
	DrawStringToHandle(100, scroll[7], "���y��", GetColor(255, 255, 255), m_largefont, TRUE);
	DrawStringToHandle(500, scroll[8], "������", GetColor(255, 255, 255), m_largefont, TRUE);
	DrawStringToHandle(500, scroll[9], "�|�P�b�g�T�E���h", GetColor(255, 255, 255), m_largefont, TRUE);
	DrawStringToHandle(500, scroll[10], "On-Jin �`���l�`", GetColor(255, 255, 255), m_largefont, TRUE);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, m_alpha);
	DrawGraph(180, scroll[11], m_rogoimage, TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

//���ɃX�e�[�W
SCREEN CStaffRollScreen::GetNextScreen()
{
	return (m_state);
}