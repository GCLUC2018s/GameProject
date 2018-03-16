#include "game_screen.h"
#include "player_manager.h"
#include "Task\CTaskManager.h"
#include "item_manager.h"
#include "bullet_manager.h"
#include <DxLib.h>
#include "enemy_manager.h"
#include "ui_manager.h"
#include "npc_manager.h"

int g_stage = 1;

//コンストラクタ
CGameScreen::CGameScreen(){
	m_state = GAME_SCREEN;
	CItemManager::GetInstance()->Create(&CVector3D(300,0, 300));
	CItemManager::GetInstance()->Create(&CVector3D(500, 0, 300));
	CItemManager::GetInstance()->Create(&CVector3D(700, 0, 300));
	CItemManager::GetInstance()->Create(&CVector3D(900, 0, 300));
	CItemManager::GetInstance()->Create(&CVector3D(1100, 0, 300));
	new CPlayerControl;
	new CNpc;
	CEnemyManager *em = CEnemyManager::getInstance();
	new Ui(CPlayerManager::GetInstance()->GetPlayerAdress()->getBodyPos());
}

//デストラクタ
CGameScreen::~CGameScreen(){}

void CGameScreen::Dest(){
}

//更新処理
void CGameScreen::Update(){
	CTaskManager::GetInstance()->UpdateAll();
	CTaskManager::GetInstance()->KillAppoint();
	CPlayerManager::GetInstance()->Update();
	CEnemyManager::getInstance()->Update();
}

void CGameScreen::Draw()
{
	ClearDrawScreen();
	/*m_Mcnt.draw();
	m_Pcnt.draw();
	m_Icnt.draw();
	m_Tcnt.draw();
	m_Pcnt.draw();*/
	CTaskManager::GetInstance()->DrawAll();
}

//次のステージへ
SCREEN CGameScreen::GetNextScreen()
{
	return (m_state);
}