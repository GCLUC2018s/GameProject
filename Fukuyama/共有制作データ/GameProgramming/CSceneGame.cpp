#include"CSceneGame.h"
#include"CKey.h"

//ポーズ画面の判定用
int PawsCount = 0;
void CSceneGame::Init(){
	//テクスチャ読み込み
	mTexture.Load("Image(kari).tga");
	mTexture2.Load("spray-icon.tga");
	m_PawsCount == 0;
	GameScene = 0;
}
void CSceneGame::Update(){
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
		if (m_PawsCount == 0){
			mTexture.DrawImage(-600, 600, -440, 450, 0, 1200, 900, 0);
			if (CKey::Once('P')){
				//ポーズへ
				m_PawsCount = 1;
			}
		}
		else{
			if (CKey::Once('P')){
				//ポーズ解除
				m_PawsCount = 0;
			}
			if (GetKeyState(' ') & 0x8000){
				//タイトル画面へ
				GameScene = 0;
				m_PawsCount = 0;
			}
		}
		break;

	}
}