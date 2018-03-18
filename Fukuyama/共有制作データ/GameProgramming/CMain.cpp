//�w�b�_�t�@�C���̃C���N���[�h
#include "CMain.h"
#include "glut.h"
#include"CKey.h"
#include"task\CTask.h"
#include"task\CTaskManager.h"
//���߂�1�񂾂����s���鏈���̒�`
void CMain::Init() {
	//�^�C�g����ʂ̕\��
	m_Mode = 0;
	SceneState = 0;
}

//�J��Ԃ����s���鏈���̒�`
void CMain::Update() {
	switch (m_Mode)
	{
	case 0:
		//���[�h�I��
		if (CKey::Once('1') && SceneState == 0){
			//�����e�X�g�G���A��
			ip_Nagao = new Nagao();
			SceneState = 1;
		}
		if (CKey::Once('3') && SceneState == 0){
			//�������e�X�g�G���A��
			ip_Hagi = new Hagi();
			SceneState = 1;
			CTaskManager::GetInstance()->Add(ip_Hagi);
		}
		if (CKey::Once('5') && SceneState == 0){
			//�͂��e�X�g�G���A��
			ip_Hako = new Hako();
			ip_Hako->Init();
			CTaskManager::GetInstance()->Add(ip_Hako);
			SceneState = 1;
		}
		if (CKey::Once('7') && SceneState == 0){
			//�Q�[���^�C�g����
			ip_SceneGame = new CSceneGame();
			ip_SceneGame->Init();
			CTaskManager::GetInstance()->Add(ip_SceneGame);
			SceneState = 1;
		}
		if (CKey::Once(VK_ESCAPE) && SceneState == 1){
			CTaskManager::GetInstance()->KillAll();
			SceneState = 0;
		}
		break;
	}
	CTaskManager::GetInstance()->UpdateAll();
	CTaskManager::GetInstance()->DrawAll();
	CTaskManager::GetInstance()->KillAppoint();
}
