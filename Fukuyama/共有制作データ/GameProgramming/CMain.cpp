//ヘッダファイルのインクルード
#include "CMain.h"
#include "glut.h"
#include"windows.h"
#include"CKey.h"
//ポーズ画面の判定用
int PawsCount = 0;
//初めに1回だけ実行する処理の定義
void CMain::Init() {
	//テクスチャ読み込み
	mTexture.Load("Image(kari).tga");
	mTexture2.Load("spray-icon.tga");
	//タイトル画面の表示
	Mode = 0;
	PawsCount == 0;
}

//繰り返し実行する処理の定義
void CMain::Update() {
	switch (Mode)
	{
	case 0:
		//モード選択
		if (GetKeyState('1') & 0x8000){
			//長尾テストエリアへ
			Mode = 1;
		}
		if (GetKeyState('3') & 0x8000){
			//萩しゃんテストエリアへ
			Mode = 2;
		}
		if (GetKeyState('5') & 0x8000){
			//はこテストエリアへ
			Mode = 3;
		}
		if (GetKeyState('7') & 0x8000){
			//ゲームタイトルへ
			Mode = 4;
			GameScene = 0;
		}
		break;
	case 1:
		//長尾テストエリア
		break;
	case 2:
		//萩しゃんテストエリア
		break;
	case 3:
		//はこテストエリア
		break;
	case 4:
		//ゲームモード
		switch (GameScene)
		{
		case 0:
			//タイトル画面
			mTexture2.DrawImage(-600, 600, -440, 450, 0, 90, 90, 0);
			if (GetKeyState(VK_RETURN) & 0x8000){
				//プレイ画面に移動
				GameScene = 1;
			}
			break;
		case 1:
				//プレイ画面
			//ポーズ画面でない場合
			if (PawsCount == 0){
				mTexture.DrawImage(-600, 600, -440, 450, 0, 1200, 900, 0);
				if (CKey::Once('P')){
					//ポーズへ
					PawsCount =1;
				}
			}
			else{
				if (CKey::Once('P')){
					//ポーズ解除
					PawsCount = 0;
				}
				if (GetKeyState(' ') & 0x8000){
					//タイトル画面へ
					GameScene = 0;
					PawsCount = 0;
				}
			}
			break;

		}
		break;
	}

}
