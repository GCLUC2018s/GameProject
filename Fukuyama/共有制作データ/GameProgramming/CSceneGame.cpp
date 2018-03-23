#include"CSceneGame.h"
#include"CKey.h"
#include"windows.h"
#include "CCollider.h"
#include"CMain.h"

//�|�[�Y��ʂ̔���p
int PawsCount = 0;
int m_EnemyCount = 0;

void CSceneGame::Init(){
	//�e�N�X�`���ǂݍ���
	//mTexture.Load("Image(kari).tga");
	//mTexture2.Load("spray-icon.tga");
	m_PawsCount = 0;
	GameScene = 0;
	m_EnemyInterval = 0;
	m_EnemyCount = 0;
}

void CSceneGame::Update(){
	switch (GameScene)
	{
	case 0:
		Title.DrawImage(-600, 600, -450, 450, 0, 1200, 900, 0);
		//�^�C�g�����
		if (GetKeyState(VK_RETURN) & 0x8000){
			//�v���C��ʂɈړ�
			GameScene = 1;
			Drum = new C_Drum();
			Player = new C_Player();
			Enemy = new CEnemy();
			Enemy->Init();
			BackGround = new C_BackGround();
		}
		break;
	case 1:
		//�v���C���
		//�|�[�Y��ʂłȂ��ꍇ
		if (m_PawsCount == 0){
			//mTexture.DrawImage(-600, 600, -440, 450, 0, 1200, 900, 0);
			//�A�C�R���̕`��Ɖ��o
			float m_CoolTime = ICON_SIZE;
			m_CoolTime = m_CoolTime / SPRAY_INTERVAL;      //�X�v���[�̃N�[���^�C���\���i�A�C�R���j

			i_iconShadow.m_Top -= m_CoolTime;
			if (m_EnemyInterval < 60){
				m_EnemyInterval += 1;
			}
			if (m_EnemyInterval == 60 && m_EnemyCount < 10){
				Enemy = new CEnemy();
				Enemy->Init();
				m_EnemyInterval = 0;
				m_EnemyCount += 1;
			}
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
			//if (Player->m_Player_HP == 0){
			//	Drum->m_destroyFlg = true;
			//	/*CTaskManager::GetInstance()->Kill(Player);
			//	CTaskManager::GetInstance()->Kill(Enemy);
			//	CTaskManager::GetInstance()->Kill(BackGround);*/
			//	GameScene = 2;
			//}
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
	case 2:
		GameOver.DrawImage(0, 1200, 900, 0, 0, 1200, 900, 0);
		break;
	}
}

void CSceneGame::Draw(){
	if (GameScene == 1){
		Icon.DrawImage(-585, -495, -435, -345, 0, 90, 90, 0);
		i_iconShadow.Render(0.0f, 0.0f, 0.0f, 0.5f);
	}
}