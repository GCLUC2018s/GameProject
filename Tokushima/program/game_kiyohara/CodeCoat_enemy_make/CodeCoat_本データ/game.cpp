//#include "screen.h"
#include "Scene\SceneBase.h"
//#include "gametitle_screen.h"
//#include "gameclear_screen.h"
#include "game_screen.h"
//#include "screen_gameover.h"
#include "game.h"
//#include "gamescore_screen.h"

CGame::CGame(){}
CGame::~CGame(){}

void CGame::Init()
{
	m_now_screen = GAME_SCREEN;
	m_pScreen = NULL;
}


void CGame::Update(){
	if (m_pScreen == NULL){
		switch (m_now_screen){
		case TITLE_SCREEN:
			//m_pScreen = new CTitleScreen();
			break;
		case GAME_SCREEN:
			m_pScreen = new CGameScreen();
			break;
		case GAMECLEAR_SCREEN:
			//m_pScreen = new CGameClearScreen();
			break;
		case GAMEOVER_SCREEN:
			//m_pScreen = new CGameOverScreen();
			break;
		case GAMESCORE_SCREEN:
			//m_pScreen = new CGameScoreScreen();
			break;
		default:
			assert(false);
		}
		/*m_pScreen->Load();
		m_pScreen->Init();*/
	}
	else{
		m_pScreen->Update();
		if (m_now_screen != m_pScreen->GetNextScreen()){
			m_now_screen = m_pScreen->GetNextScreen();
			m_pScreen->Dest();
			delete m_pScreen;
			m_pScreen = NULL;
		}
	}
}


void CGame::Draw()
{
	if (m_pScreen){
		m_pScreen->Draw();
	}
}

void CGame::Dest()
{
	if (m_pScreen){
		delete m_pScreen;
		m_pScreen = NULL;
	}
}