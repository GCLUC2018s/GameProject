#include "Hako.h"
#include"CKey.h"
#include"windows.h"
#include"task\CTaskManager.h"
//�|�[�Y��ʂ̔���p
int Paws = 0;
void Hako::Init(){
	//�e�N�X�`���ǂݍ���
	mTexture.Load("Image(kari).tga");
	mTexture2.Load("spray-icon.tga");
	m_Paws = 0;
	GameScene = 0;
	m_EnemyInterval = 0;
}

void Hako::Update(){
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
		if (m_Paws == 0){
			mTexture.DrawImage(-600, 600, -440, 450, 0, 1200, 900, 0);
				if (m_EnemyInterval < 60){
					m_EnemyInterval += 1;
				}
				if (m_EnemyInterval == 60){
					Enemy = new CEnemy();
					m_EnemyInterval = 0;
				}
			if (CKey::Once('P')){
				//�|�[�Y��
				m_Paws = 1;
			}
		}
		else{
			if (CKey::Once('P')){
				//�|�[�Y����
				m_Paws = 0;
			}
			if (GetKeyState(' ') & 0x8000){
				//�^�C�g����ʂ�
				GameScene = 0;
				m_Paws = 0;
			}
		}
		break;
	}
}