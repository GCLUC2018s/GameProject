#include "CSceneManager.h"
#include "DebugScene\DebugScene.h"

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
	case eDebug:
		new CDebugScene();
		break;
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
void CSceneManager::MainScene() {
	//メイン戦闘画面の要素ぶち込む
	SOUND("BGM_Title")->Stop();
	new CBB(60 * 3,true);
	new CBB(60 * 3, 1, false);
	new CPlayer();

	/*new CEnemy1(&(CVector3D(400, 0, -300)));
	new CEnemy2(&(CVector3D(500, 100, -100)));
	new CEnemy3(&(CVector3D(600, 100, -250)));
	new CEnemy4(&(CVector3D(800, 50, -200)));
	new CEnemy5(&(CVector3D(200, 0, -130)));*/
	new CBoss(&(CVector3D(3000, -200, -500)), &(CVector3D(2850, 0, -500)),
		&(CVector3D(3150, 0, -500)), &(CVector3D(3000, 200, -500)));
	new CFire(&(CVector3D(500, 0, -20)));
	new CFire(&(CVector3D(500, 0, -100)));
	new CItemBox(&(CVector3D(1000, 0, -430)), 0);
	new CItemBox(&(CVector3D(1250, 0, -430)), 1);

	//new CBoss(&(CVector3D(3000, -200, -500)), &(CVector3D(2850, 0, -500)),
	//	&(CVector3D(3150, 0, -500)), &(CVector3D(3000, 200, -500)));
	//new CFire(&(CVector3D(500, 0, -20)));
	//new CFire(&(CVector3D(500, 0, -100)));
	//new CItemBox(&(CVector3D(1000, 0, -430)), 0);
	//new CItemBox(&(CVector3D(1250, 0, -430)), 1);
	new CFieldManager();

	new CKoban(&(CVector3D(500,500, 0)));
	new COage(&(CVector3D(500, 450, 0)));
	new CSake(&(CVector3D(450, 500, 0)));
	new CMagatama();	
	//new CKoban(&(CVector3D(310, 0, -130)));
	//new CKoban(&(CVector3D(420, 0, -100)));
	//new CKoban(&(CVector3D(530, 0, -50)));
	//new CKoban(&(CVector3D(640, 0, -180)));
	//new CKoban(&(CVector3D(700, 0, -220)));
	//new COage(&(CVector3D(500, 0, -30)));
	//new CSake(&(CVector3D(450, 0, -30)));
	new CMagatama();
	new CEnemyManager();
	new CKakera(&(CVector3D(450, 450, 0)));
	for (int i = 0; i < 10; i++) {
		new CKakera(&(CVector3D(450 + i * 40, 0, -30)));
	}
}

void CSceneManager::BossScene(){
	//ボス戦闘画面の要素ぶち込む
}

void CSceneManager::EndScene(){
	//エンディング画面の要素ぶち込む
	SOUND("BGM_Main")->Stop();
	new CEnding();
}
