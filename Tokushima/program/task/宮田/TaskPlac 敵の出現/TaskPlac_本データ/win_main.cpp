#include "DxLib.h"
#include "math.h"

//#include "player.h"
#include "task.h"
#include "taskmanager.h"
#include "player.h"
#include "enemy.h"

using namespace std;

//ウィンドウ画面のメイン
int WINAPI WinMain(HINSTANCE hl, HINSTANCE hP, LPSTR IpC,
	int nC)
{
	ChangeWindowMode(TRUE);
	SetGraphMode(800, 600, 32);
	SetMainWindowText("サンプルプログラム");

	//DXライブラリ初期化
	if (DxLib_Init() == -1)return -1;

	// グラフィックの描画先を裏画面にセット
	SetDrawScreen(DX_SCREEN_BACK);

	int time = 1;
	int color_white = GetColor(255, 255, 255);//色取得
	/*for (int i = 0; i < 10; i++){
		new CTask(i, i, i);
	}*/

	new CPlayer();
	new CEnemy();

	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0){
		ClearDrawScreen();
		clsDx();
		CTaskManager::GetInstance()->UpdateAll();
		CTaskManager::GetInstance()->DrawAll();
		CTaskManager::GetInstance()->KillAppoint();
		ScreenFlip();
	}
	//DXライブラリの終了処理
	DxLib_End();
	return 0;
}
