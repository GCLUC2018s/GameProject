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
		//mTexture2.DrawImage(-600, 600, -440, 450, 0, 90, 90, 0);
		if (GetKeyState(VK_RETURN) & 0x8000){
			//プレイ画面に移動
			GameScene = 1;
		}
		break;
	case 1:
		Player->m_Objvalue = Enemy->m_Objvalue = 10;
		if (C_Collider::Collision(Player, Enemy, &Player->i_JumpPoint, &Enemy->m_Position)){
			Player->m_Position.x += Player->m_Colimage.m_AdjustX;
			Player->m_Position.z += Player->m_Colimage.m_AdjustZ;
			Player->i_JumpPoint.x += Player->m_Colimage.m_AdjustX;
			Player->i_JumpPoint.z += Player->m_Colimage.m_AdjustZ;
		}
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
