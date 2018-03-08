//ヘッダファイルのインクルード
#include "CMain.h"
#include "glut.h"
void CMain::Init(){
	mPlayer = new CPlayer();
	mPlayer->Init();
	//リストに追加
	CTaskManager::GetInstance()->Add(mPlayer);
}
void CMain::Update(){
	CTaskManager::GetInstance()->UpdateAll();
	CTaskManager::GetInstance()->DrawAll();
}