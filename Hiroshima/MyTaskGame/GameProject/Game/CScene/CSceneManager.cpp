#include "CSceneManager.h"

CSceneManager::CSceneManager(int scene) : CTask(0, eU_Scene, eD_Null)
{
	SetSceneObject(scene);
}

CSceneManager::~CSceneManager()
{
}

void CSceneManager::SetSceneObject(int scene_num)
{
	CTaskManager::GetInstance()->SetKillAll();
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

//みんながいじっていいのは以下の部分
void CSceneManager::TitleScene(){
	//タイトル画面の要素ぶち込む
	SOUND("BGM_Main")->Stop();
	SOUND("BGM_Title")->Play(true);
	new CTitleBG();
}

void CSceneManager::MainScene(){
	//メイン戦闘画面の要素ぶち込む
	SOUND("BGM_Title")->Stop();
	SOUND("BGM_Main")->Play(true);
	new CPlayer();
	new CEnemy1(&(CVector3D(200, 200, 0)));
	new CEnemy2(&(CVector3D(200, 100, 0)));
	new CEnemy3(&(CVector3D(100, 300, 0)));
	new CEnemy4(&(CVector3D(300, 400, 0)));
	new CEnemy5(&(CVector3D(400, 450, 0)));
	//new CBoss(&(CVector3D(3000, 50, 0)));
	new CGimmick(&(CVector3D(500, 500, 0)));
	new CGimmick(&(CVector3D(250, 500, 0)));
	new CGimmick(&(CVector3D(500, 250, 0)));
//	new CFieldBG();
	new CFieldSky();
	new CFieldCloud();
	new CFieldBamboo();
	new CFieldGround();


}

void CSceneManager::BossScene(){
	//ボス戦闘画面の要素ぶち込む
}

void CSceneManager::EndScene(){
	//エンディング画面の要素ぶち込む
}
