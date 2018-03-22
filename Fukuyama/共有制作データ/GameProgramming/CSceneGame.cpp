#include"CSceneGame.h"
#include"CKey.h"
#include"windows.h"
#include "CCollider.h"
//ポーズ画面の判定用
int PawsCount = 0;

void CSceneGame::Init(){
	//テクスチャ読み込み
	mTexture.Load("Image(kari).tga");
	mTexture2.Load("spray-icon.tga");
	m_PawsCount = 0;
	GameScene = 0;
}

void CSceneGame::Update(){
	switch (GameScene)
	{
	case 0:
		//タイトル画面
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
			//アイコンの描画と演出
			float m_CoolTime = ICON_SIZE;
			m_CoolTime = m_CoolTime / SPRAY_INTERVAL;      //スプレーのクールタイム表示（アイコン）

			i_iconShadow.m_Top -= m_CoolTime;
			if (i_iconShadow.m_Top <= i_iconShadow.m_Bottom){
				i_iconShadow.m_Top = i_iconShadow.m_Bottom;
			}
			if (C_Player::m_Playerpoint->m_Anime_Spray == 0){
				i_iconShadow.m_Top = i_iconShadow.m_Bottom + ICON_SIZE;
			}
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

void CSceneGame::Draw(){
	Icon.DrawImage(-585, -495, -435, -345, 0, 90, 90, 0);
	i_iconShadow.Render(0.0f, 0.0f, 0.0f, 0.5f);
}