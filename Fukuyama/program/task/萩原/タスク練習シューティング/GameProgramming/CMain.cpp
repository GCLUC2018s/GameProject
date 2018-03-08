//ヘッダファイルのインクルード
#include "CMain.h"
#include "glut.h"
#include "CPlayer.h"
#include "CTaskManager.h"
#include "CTaskLinker.h"

//初めに1回だけ実行する処理の定義
void CMain::Init() {
	Player = new CPlayer();
	Player->Init();
	Player->SetVertex(-32,32,-32,32);
	CTaskManager::GetInstance()->Add((CTask*)Player);
}

//繰り返し実行する処理の定義
void CMain::Update() {
	//タスクを更新していく
	CTaskManager::GetInstance()->UpdateAll();
	CTaskManager::GetInstance()->DrawAll();
}
