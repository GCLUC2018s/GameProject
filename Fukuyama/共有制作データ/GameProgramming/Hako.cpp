#include "Hako.h"
#include"CKey.h"
#include"windows.h"
#include"task\CTaskManager.h"
//ポーズ画面の判定用
int Paws = 0;
void Hako::Init(){
	//テクスチャ読み込み
	mTexture.Load("Image(kari).tga");
	mTexture2.Load("spray-icon.tga");
	m_Paws = 0;
	GameScene = 0;
	m_EnemyInterval = 0;
}

void Hako::Update(){
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
		if (m_Paws == 0){
			mTexture.DrawImage(-600, 600, -440, 450, 0, 1200, 900, 0);
				if (m_EnemyInterval < 60){
					m_EnemyInterval += 1;
				}
				if (m_EnemyInterval == 60){
					Enemy = new CEnemy();
					m_EnemyInterval = 0;
				}
			if (CKey::Once('P')){
				//ポーズへ
				m_Paws = 1;
			}
		}
		else{
			if (CKey::Once('P')){
				//ポーズ解除
				m_Paws = 0;
			}
			if (GetKeyState(' ') & 0x8000){
				//タイトル画面へ
				GameScene = 0;
				m_Paws = 0;
			}
		}
		break;
	}
}