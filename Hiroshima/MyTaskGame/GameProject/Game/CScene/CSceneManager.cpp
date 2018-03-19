#include "CSceneManager.h"
#include "DebugScene\DebugScene.h"
#include "../GameProject/Source/Fieldsource.h"
#include "../GameProject/Source/Enemysource.h"
#include "../GameProject/Source/Gamesource.h"
#include "../GameProject/Source/Itemsource.h"

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
	SOUND("BGM_Title")->Play(true);
	new CBB(0, 0, true);
	new CTitleBG();
}

void CSceneManager::MainScene() {
	//メイン戦闘画面の要素ぶち込む
	SOUND("BGM_Title")->Stop();
	new CBB(60 * 3, 1, true);
	new CPlayer();

	//new CFire(&(CVector3D(500, 0, -20)));
	//new CFire(&(CVector3D(500, 0, -100)));
	//new CItemBox(&(CVector3D(1000, 0, -430)), 0);
	//new CItemBox(&(CVector3D(1250, 0, -430)), 1);

	new CFieldManager();
	for (int i = 0; i < 10; i++) {
		new CKakera(&(CVector3D(200 + i * 60, 0, 0)));
	}

	new CMagatama();
	new CHPBar(false);
	new CEnemyManager();

}


void CSceneManager::BossScene() {
	//ボス戦闘画面の要素ぶち込む
	SOUND("BGM_Main")->Stop();
	SOUND("BGM_Boss")->Play(true);
	new CBB(0, 0, true);
	new CPlayer();
	new CBossStage();
	new CMagatama();
	new CHPBar(true);
	new CHPBar(false);

}
void CSceneManager::EndScene(){
	//エンディング画面の要素ぶち込む
	SOUND("BGM_Main")->Stop();
	new CEnding();
}
