#include "CSceneManager.h"

CSceneManager::CSceneManager(int scene) : CTask(0, eUDP_Scene, eDWP_Null)
{
	//CTaskManager::GetInstance()->KillAll();
	SetSceneObject(scene);
	m_destroyFlg = true;
}

CSceneManager::~CSceneManager()
{
}

void CSceneManager::SetSceneObject(int scene_num)
{
	//�Ή������V�[���N���X�𐶐�
	switch (scene_num)
	{
	case eTitle:
		TitleScene();
		break;
	case eMain:
		MainScene();
		break;
	case eBoss:
		BossScene();
		break;
	case eEnd:
		EndScene();
		break;
	default:
		break;
	}
}

void CSceneManager::TitleScene(){
	SOUND("BGM_Title")->Play(true);
	new CTitleBG();
}

void CSceneManager::MainScene(){
	SOUND("BGM_Title")->Stop();
	SOUND("BGM_Main")->Play(true);
	new CPlayer();
	new CEnemy1(&(CVector3D(200, 200, 0)));
	new CGimmick(&(CVector3D(500, 500, 0)));
	new CGimmick(&(CVector3D(250, 500, 0)));
	new CGimmick(&(CVector3D(500, 250, 0)));
}

void CSceneManager::BossScene(){
}

void CSceneManager::EndScene(){
}
