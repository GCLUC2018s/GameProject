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
	//対応したシーンクラスを生成
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
	new CTitleBG();
}

void CSceneManager::MainScene(){
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
