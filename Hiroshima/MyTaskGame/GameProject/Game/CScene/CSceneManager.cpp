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
	case eGameStart:
		GameStartScene();
		break;
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
void CSceneManager::GameStartScene()
{
	new CGameStart();
}

void CSceneManager::TitleScene(){
	//タイトル画面の要素ぶち込む
	SOUND("BGM_Main")->Stop();
	SOUND("BGM_Title")->Play(true);
	new CTitleBG();
}

void CSceneManager::MainScene(){
	//メイン戦闘画面の要素ぶち込む
	SOUND("BGM_Title")->Stop();
	new CBB(60 * 3,true);
	new CPlayer();

	new CEnemy1(&(CVector3D(400, 0, -300)));
	new CEnemy2(&(CVector3D(500, 100, -100)));
	new CEnemy3(&(CVector3D(600, 100, -250)));
	new CEnemy4(&(CVector3D(800, 50, -200)));
	new CEnemy5(&(CVector3D(200, 0, -130)));
	//new CBoss(&(CVector3D(3000, 50, 0)));
	new CGimmick(&(CVector3D(500, 0, -250)));
	new CGimmick(&(CVector3D(250, 0, -150)));
	new CGimmick(&(CVector3D(500, 0, -350)));
//	new CFieldBG();
	new CFieldSky();
	new CFieldCloud();
	new CFieldBamboo();
	new CFieldGround();

	new COhuda(&(CVector3D(500,500,0)));
	new CKoban(&(CVector3D(500,500, 0)));
	new COage(&(CVector3D(500, 450, 0)));
	new CSake(&(CVector3D(450, 500, 0)));
	new CMagatama();

}

void CSceneManager::BossScene(){
	//ボス戦闘画面の要素ぶち込む
}

void CSceneManager::EndScene(){
	//エンディング画面の要素ぶち込む
}
