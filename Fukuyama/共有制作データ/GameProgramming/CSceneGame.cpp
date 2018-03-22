#include"CSceneGame.h"
#include"CKey.h"
#include"windows.h"
#include "CCollider.h"
//�|�[�Y��ʂ̔���p
int PawsCount = 0;

void CSceneGame::Init(){
	//�e�N�X�`���ǂݍ���
	mTexture.Load("Image(kari).tga");
	mTexture2.Load("spray-icon.tga");
	m_PawsCount = 0;
	GameScene = 0;
}

void CSceneGame::Update(){
	switch (GameScene)
	{
	case 0:
		//�^�C�g�����
		if (GetKeyState(VK_RETURN) & 0x8000){
			//�v���C��ʂɈړ�
			GameScene = 1;
		}
		break;
	case 1:
		//�v���C���
		//�|�[�Y��ʂłȂ��ꍇ
		if (m_PawsCount == 0){
			mTexture.DrawImage(-600, 600, -440, 450, 0, 1200, 900, 0);
			//�A�C�R���̕`��Ɖ��o
			float m_CoolTime = ICON_SIZE;
			m_CoolTime = m_CoolTime / SPRAY_INTERVAL;      //�X�v���[�̃N�[���^�C���\���i�A�C�R���j

			i_iconShadow.m_Top -= m_CoolTime;
			if (i_iconShadow.m_Top <= i_iconShadow.m_Bottom){
				i_iconShadow.m_Top = i_iconShadow.m_Bottom;
			}
			if (C_Player::m_Playerpoint->m_Anime_Spray == 0){
				i_iconShadow.m_Top = i_iconShadow.m_Bottom + ICON_SIZE;
			}
			if (CKey::Once('P')){
				//�|�[�Y��
				m_PawsCount = 1;
			}
		}
		else{
			if (CKey::Once('P')){
				//�|�[�Y����
				m_PawsCount = 0;
			}
			if (GetKeyState(' ') & 0x8000){
				//�^�C�g����ʂ�
				GameScene = 0;
				m_PawsCount = 0;
			}
		}
		break;
	}
}

void CSceneGame::Draw(){
	Icon.DrawImage(-585, -495, -435, -345, 0, 90, 90, 0);
	i_iconShadow.Render(0.0f, 0.0f, 0.0f, 0.5f);
}