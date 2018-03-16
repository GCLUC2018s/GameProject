//ヘッダファイルのインクルード
#include "CMain.h"
#include "glut.h"
#include"CKey.h"
#include"task\CTask.h"
#include"task\CTaskManager.h"
//初めに1回だけ実行する処理の定義
void CMain::Init() {
	//タイトル画面の表示
	m_Mode = 0;
	SceneState = 0;
}

//繰り返し実行する処理の定義
void CMain::Update() {
	switch (m_Mode)
	{
	case 0:
		//モード選択
		if (CKey::Once('1') && SceneState == 0){
			//長尾テストエリアへ
			ip_Nagao = new Nagao();
			SceneState = 1;
		}
		if (CKey::Once('3') && SceneState == 0){
			//萩しゃんテストエリアへ
			ip_Hagi = new Hagi();
			SceneState = 1;
			CTaskManager::GetInstance()->Add(ip_Hagi);
		}
		if (CKey::Once('5') && SceneState == 0){
			//はこテストエリアへ
			ip_Hako = new Hako();
			ip_Hako->Init();
			CTaskManager::GetInstance()->Add(ip_Hako);
			SceneState = 1;
		}
		if (CKey::Once('7') && SceneState == 0){
			//ゲームタイトルへ
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
