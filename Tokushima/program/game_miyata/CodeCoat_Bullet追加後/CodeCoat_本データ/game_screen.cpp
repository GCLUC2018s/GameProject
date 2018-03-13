#include "game_screen.h"
#include "player_manager.h"
#include "Task\CTaskManager.h"
#include "item_manager.h"
#include "bullet_manager.h"
#include <DxLib.h>
int g_stage = 1;

//�R���X�g���N�^
CGameScreen::CGameScreen(){
	m_state = GAME_SCREEN;
	CItemManager::GetInstance()->Create(&CVector2D(300, 300));
	CItemManager::GetInstance()->Create(&CVector2D(500, 300));
	CItemManager::GetInstance()->Create(&CVector2D(700, 300));
	CItemManager::GetInstance()->Create(&CVector2D(900, 300));
	CItemManager::GetInstance()->Create(&CVector2D(1100, 300));
	new CMapControl;

}

//�f�X�g���N�^
CGameScreen::~CGameScreen(){}

void CGameScreen::Dest(){
}

//���[�h
void CGameScreen::Load(){
	//m_bgm = LoadSoundMem("media\\mp3\\main\\game_maoudamashii_6_dangeon09.mp3");
	/*m_Mcnt.loadFiles();
	m_Pcnt.loadFiles();
	m_Tcnt.load();
	m_Icnt.LoadFiles();*/
}

//������
void CGameScreen::Init(){
	/*m_Mcnt.Init();
	m_Pcnt.init();
	m_Tcnt.init();*/
}


//�X�V����
void CGameScreen::Update(){
	/*m_Mcnt.move(m_Pcnt.getMoveAmount());
	m_Icnt.move(m_Pcnt.getMoveAmount());
	m_Pcnt.move(&m_Mcnt,&m_Icnt);
	m_Tcnt.move(m_Pcnt.getBodyPos());
	m_Icnt.eraseidata();

	if (m_Tcnt.GetTime() == 0){
		m_state = GAMEOVER_SCREEN;
	}*/
	CTaskManager::GetInstance()->UpdateAll();
	CTaskManager::GetInstance()->KillAppoint();
	CPlayerManager::GetInstance()->Update();

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

//���̃X�e�[�W��
SCREEN CGameScreen::GetNextScreen()
{
	return (m_state);
}