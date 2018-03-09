#include "Source/Include.hpp"
#include "Source/Utility/Timer.hpp"
#include "Source/Utility/Font.hpp"

#include "Source/Scene/SceneManager.hpp"
#include "Source/Utility/InputManager.hpp"
#include "Source/Task/CTaskManager.h"
#include "Source/Game/Enemy/EnemyManager.hpp"
#include "Source/Game/Bullet/BulletManager.hpp"

// 初期化処理
bool Init()
{
	// 乱数シード設定
	srand((unsigned int)time(NULL));

	// ウィンドウモードで起動
	ChangeWindowMode(1);
	// アプリ名設定
	SetWindowText(APP_NAME);
	// ウィンドウサイズ設定
	SetGraphMode(WINDOW_WIDTH,WINDOW_HEIGHT,32);
	// ウィンドウがアクティブ時も処理実行
	SetAlwaysRunFlag(true);
#ifndef	_DEBUG
	// Releaseモードならば、ログ出力しない
	SetOutApplicationLogValidFlag(false);
#endif

	// DXライブラリ初期化
	int ans(DxLib_Init());
	// 初期化エラー
	if(ans == -1) return false;

	// デバッグフォント読み込み
	nsGameBoard::g_debug_font = new clFont;
	nsGameBoard::g_debug_font->Init();
	nsGameBoard::g_debug_font->SetShadow(true);

	// シーン管理クラス初期化
	clSceneManager::GetInstance()->Init();

	// 入力管理クラス初期化
	clInputManager::GetInstance()->Init();

	return true;
}

// 終了処理
void Exit()
{
	SN_SAFE_DELETE(nsGameBoard::g_debug_font);

	clInputManager::GetInstance()->ClearInstance();
	clSceneManager::GetInstance()->ClearInstance();
	CTaskManager::GetInstance()->ClearInstance();
	clEnemyManager::GetInstance()->ClearInstance();
	clBulletManager::GetInstance()->ClearInstance();

	// DXライブラリ終了処理
	DxLib_End();
}

// メイン処理
void Main()
{
	CTaskManager::GetInstance()->KillAppoint();

	// 入力判定更新
	clInputManager::GetInstance()->Update();

	// 更新処理
	{
		// エネミーマネージャー更新
		clEnemyManager::GetInstance()->Update();
		// 自弾マネージャー更新
		clBulletManager::GetInstance()->Update();

		// シーンマネージャー更新
		clSceneManager::GetInstance()->Update();
		// タスクマネージャー更新
		CTaskManager::GetInstance()->UpdateAll();

		// デバッグフォント更新
		nsGameBoard::g_debug_font->Update();
	}
	// 描画処理
	{
		// タスクマネージャー描画
		CTaskManager::GetInstance()->DrawAll();
		// デバッグフォント描画
		nsGameBoard::g_debug_font->Draw();
	}
}

int main()
{
	// 初期化
	if(!Init())
	{
		// エラーならば、終了
		return -1;
	}

	clTimer loopTimer;	// メインループ用タイマー

	// 裏画面に描画する設定
	SetDrawScreen(DX_SCREEN_BACK);

	// メインループ
	while(1)
	{
		// 1フレームの時間計測開始
		loopTimer.StartTimer();

		// 画面クリア
		ClearDrawScreen();
		// 画面を黒色に埋める
		DrawBox(0,0,WINDOW_WIDTH,WINDOW_HEIGHT,GetColor(0,0,0),true);

		// メイン処理
		Main();

		// 画面の裏表切り替え
		ScreenFlip();

		// 待ち時間
		do{
		}while(loopTimer.GetTimeMCS() < (1.0/(double)FRAME_RATE));
		// 時間計測停止
		loopTimer.StopTimer();

		// 終了判定
		{
			// Windowsのメッセージ処理
			if(ProcessMessage() == -1) break;
			// 「Esc」キーで終了
			if(clInputManager::GetInstance()->IsPushKey(IK_ESCAPE)) break;
		}
	}

	// 終了
	Exit();

	return 0;
}
