#include"CTask.h"
#include"CMain.h"
#include"CPlayer.h"
#include"CTaskManager.h"
CPlayer *ePlayer;
void CMain::Init(){
	ePlayer = new CPlayer();
	ePlayer->Init();
	CTaskManager::GetInstance()->Add(ePlayer);
}
void CMain::Update(){
	CTaskManager::GetInstance()->UpdateAll();
	CTaskManager::GetInstance()->DrawAll();
}