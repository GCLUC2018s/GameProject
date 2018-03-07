#include "DxLib.h"
#include "math.h"
#include <list>

#include "player.h"
#include "task.h"
#include "taskmanager.h"

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
	
	int color_white = GetColor(255, 255, 255);//色取得
	int time = 1;
	
	//考え方.TaskManagerからTaskのupdate()を呼び出しています
	TaskManager *tm = new TaskManager();

	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0){
		ClearDrawScreen();

		for (int i = 0; i < 10; i++){
			tm->BTask = new Player();
			
		}
		tm->update();
		//ここまで

		ScreenFlip();
	}
	delete tm->BTask;

	//DXライブラリの終了処理
	DxLib_End();
	return 0;
}
