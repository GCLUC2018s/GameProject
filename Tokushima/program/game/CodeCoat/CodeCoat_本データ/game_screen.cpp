#include "game_screen.h"
#include "player_manager.h"
#include "Task\CTaskManager.h"
#include "item_manager.h"
#include "bullet_manager.h"
#include <DxLib.h>
#include "enemy_manager.h"
#include "ui_manager.h"
#include "npc_manager.h"
#include "map_manager.h"
#include "se_manager.h"

int g_stage = 1;

//コンストラクタ
CGameScreen::CGameScreen(){
	m_state = GAME_SCREEN;
	m_gameclear_img[0] = LoadGraph("media\\img\\gm_clear_1.png");
	m_gameclear_img[1] = LoadGraph("media\\img\\gm_clear_2.png");
	m_cpos1 = CVector3D(CLEAR_TEXT_INI_X, CLEAR_TEXT1_INI_Y, 0);
	m_cpos2 = CVector3D(CLEAR_TEXT_INI_X, CLEAR_TEXT2_INI_Y, 0);
	m_count1 = 0;
	m_stop_pos = CLEAR_TEXT_X;
	CItemManager::GetInstance()->Create(&CVector3D(300,0, 300));
	CItemManager::GetInstance()->Create(&CVector3D(500, 0, 300));
	CItemManager::GetInstance()->Create(&CVector3D(700, 0, 300));
	//CItemManager::GetInstance()->Create(&CVector3D(900, 0, 300));
	//CItemManager::GetInstance()->Create(&CVector3D(1100, 0, 300));
	new CPlayerControl;
	new CNpc;
	new CMapControl;
	CEnemyManager::getInstance()->Init();
	CEnemyManager::getInstance()->LoadFile();
	new Ui(CPlayerManager::GetInstance()->GetPlayerAdress()->getBodyPos());
	PlaySoundMem(CSeManager::GetInstance()->getsnd(STAGE_BGM), DX_PLAYTYPE_LOOP);
}

//デストラクタ
CGameScreen::~CGameScreen(){
	CTaskManager::GetInstance()->KillAll();
	StopSoundMem(CSeManager::GetInstance()->getsnd(STAGE_BGM));
}

void CGameScreen::Dest(){
}

//更新処理
void CGameScreen::Update(){
	if (CheckHitKey(KEY_INPUT_V) == 1){
		m_state = GAMESCORE_SCREEN;
	}
	if (CPlayerManager::GetInstance()->GetPlayerAdress()->getlive() == false){
		m_state = GAMEOVER_SCREEN;
	}
	if (CMapManager::GetInstance()->GetMapAdress()->getGoalFlag() == true)//{
		GoalMove();
	//}
	//else{
		CTaskManager::GetInstance()->UpdateAll();
		CTaskManager::GetInstance()->KillAppoint();
		CPlayerManager::GetInstance()->Update();
		CEnemyManager::getInstance()->Update();
	//}
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
	if (CMapManager::GetInstance()->GetMapAdress()->getGoalFlag() == true){
		DrawGraph(m_cpos1.getX(), m_cpos1.getY(), m_gameclear_img[0], TRUE);
		DrawGraph(m_cpos2.getX(), m_cpos2.getY(), m_gameclear_img[1], TRUE);
	}
}

void CGameScreen::GoalMove(){
	if (m_cpos1.getX() > m_stop_pos){
		m_cpos1 -= CVector3D(30, 0, 0);
	}
	else{
		if (m_cpos2.getX() > m_stop_pos)
			m_cpos2 -= CVector3D(30, 0, 0);
	}

	if (m_cpos2.getX() < m_stop_pos){
		if (m_count1 > 200){
			if (m_stop_pos == CLEAR_TEXT_X){
				m_count1 = 0;
				m_stop_pos = CLEAR_TEXT_X2;
			}
			else{ 
				m_state = GAMESCORE_SCREEN; 
			}
		}
		m_count1++;
	}


}

//次のステージへ
SCREEN CGameScreen::GetNextScreen()
{
	return (m_state);
}