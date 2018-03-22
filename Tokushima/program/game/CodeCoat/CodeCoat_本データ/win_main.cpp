#include "myLib.h"
#include "game.h"
#include "Include.h"
#include "player_manager.h"
#include "Task\CTaskManager.h"
#include "item_manager.h"
#include "bullet_manager.h"
#include "enemy_manager.h"
#include "ui_manager.h"
#include "npc_manager.h"
#include "map_manager.h"
#include "score_manager.h"


CGame*	g_pMain = NULL;
const bool WINDOW_SCREEN = true;   //true:ウィンドウ

void win_main_init();
void win_main_loop();
void win_main_dest();

/*const int SCREEN_W = 800;
const int SCREEN_H = 600;
int handle, x, add;
int Screen;
int DesktopW, DesktopH;
int OldWindowW, OldWindowH;
int WindowW, WindowH;*/

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	win_main_init();

	while (true){
		win_main_loop();
#if defined(_DEBUG) |defined(DEBUG)
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) exit(-1);
#endif
	}

	win_main_dest();

}

//メイン初期化処理
void win_main_init()
{
	//DerectX関係
	ChangeWindowMode(WINDOW_SCREEN);
	SetGraphMode(1280,720, 32);
	SetWindowText(_T("Code:Coat"));
	if (WINDOW_SCREEN)
	{
	}
	if (DxLib_Init() == -1) //ライブラリの初期化処理
		return;
	SetDrawScreen(DX_SCREEN_BACK);
	srand((unsigned int)time(NULL));
	//GAME関係
	g_pMain = new CGame();
}


//メインループの処理
void win_main_loop(){
	//メイン処理
	g_pMain->Update();
	g_pMain->Draw();
	ScreenFlip();
}

//メイン終了処理
void win_main_dest()
{
	DxLib_End();
	g_pMain->Dest();
	delete g_pMain;
	g_pMain = NULL;
	CPlayerManager::ClearInstance();	//Play
	CMapManager::ClearInstance();		//Map
	CEnemyManager::clearInstance();		//Enemy
	CItemManager::ClearInstance();		//Item
	CBulletManager::ClearInstance();	//Bullet
	CNpcManager::ClearInstance();		//Npc
	CUiManager::ClearInstance();		//Ui
	CTaskManager::ClearInstance();		//Task
	CScoreManager::ClearInstance();		//score
}