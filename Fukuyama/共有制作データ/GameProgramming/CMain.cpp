//�w�b�_�t�@�C���̃C���N���[�h
#include "CMain.h"
#include "glut.h"
#include"windows.h"
#include"CKey.h"
//�|�[�Y��ʂ̔���p
int PawsCount = 0;
//���߂�1�񂾂����s���鏈���̒�`
void CMain::Init() {
	//�e�N�X�`���ǂݍ���
	mTexture.Load("Image(kari).tga");
	mTexture2.Load("spray-icon.tga");
	//�^�C�g����ʂ̕\��
	m_Mode = 0;
	m_PawsCount == 0;
}

//�J��Ԃ����s���鏈���̒�`
void CMain::Update() {
	switch (m_Mode)
	{
	case 0:
		//���[�h�I��
		if (GetKeyState('1') & 0x8000){
			//�����e�X�g�G���A��
			m_Mode = 1;
		}
		if (GetKeyState('3') & 0x8000){
			//�������e�X�g�G���A��
			m_Mode = 2;
		}
		if (GetKeyState('5') & 0x8000){
			//�͂��e�X�g�G���A��
			m_Mode = 3;
		}
		if (GetKeyState('7') & 0x8000){
			//�Q�[���^�C�g����
			m_Mode = 4;
			GameScene = 0;
		}
		break;
	case 1:
		//�����e�X�g�G���A
		break;
	case 2:
		//�������e�X�g�G���A
		break;
	case 3:
		//�͂��e�X�g�G���A
		break;
	case 4:
		//�Q�[�����[�h
		switch (GameScene)
		{
		case 0:
			//�^�C�g�����
			mTexture2.DrawImage(-600, 600, -440, 450, 0, 90, 90, 0);
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
				if (CKey::Once('P')){
					//�|�[�Y��
					m_PawsCount =1;
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
		break;
	}
<<<<<<< HEAD
	CTaskManager::GetInstance()->UpdateAll();
	CTaskManager::GetInstance()->DrawAll();
=======

>>>>>>> 189d1420510f60b31020b8a715577dba1d0dd30f
}
