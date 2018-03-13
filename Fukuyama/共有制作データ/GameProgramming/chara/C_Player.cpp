#include "C_Player.h"
#include <stdio.h>

#define PLAYER_SCROLL ((100-SCROLL_PERCENTAGE)/100)*1200    //プレイヤーとスクロール基準点の距離
#define PLAYER_START_BOTTOM -135               //プレイヤーの初期位置（下）←上下位置調整は下のみ変更してください。
#define PLAYER_START_TOP (PLAYER_START_BOTTOM+135)          //プレイヤーの初期位置（上）
#define PLAYER_START_RIGHT (-PLAYER_SCROLL)          //プレイヤーの初期位置（右）
#define PLAYER_START_LEFT (PLAYER_START_RIGHT-90)       //プレイヤーの初期位置（左）

void C_Player::Init(){
	//アニメーションカウンタの初期化
	m_Anime = 0;
	m_Anime_s = 0;
	//プレイヤーのサイズ
	SetVertex(PLAYER_START_LEFT, PLAYER_START_RIGHT, PLAYER_START_BOTTOM, PLAYER_START_TOP);
}


void C_Player::Update(){

	//アニメーションカウンタを1秒分回す
	if (m_Anime_Taiki < 60)++m_Anime_Taiki;
	//アニメーションカウンタをリセットし、経過時間(秒)を追加する
	else if (m_Anime_Taiki == 60){
		m_Anime_Taiki = 0;
		++m_Anime_Taiki_s;
	}

	//右移動
	if (CKey::Push(VK_RIGHT)){
		m_Turn = E_RIGHT;
		m_Right += PLAYER_LR_SPEED;
		m_Left += PLAYER_LR_SPEED;
	}
	//左移動
	else if (CKey::Push(VK_LEFT)){
		m_Turn = E_LEFT;
		m_Right -= PLAYER_LR_SPEED;
		m_Left -= PLAYER_LR_SPEED;
	}
	//上移動
	else if (CKey::Push(VK_UP) && (m_Bottom >= DISPLAY_BOTTOM&&m_Bottom <= DISPLAY_TOP - 390)){
		m_Bottom += PLAYER_UD_SPEED;
		m_Top += PLAYER_UD_SPEED;
	}
	//下移動
	else if (CKey::Push(VK_DOWN) && (m_Bottom >= DISPLAY_BOTTOM&&m_Bottom <= DISPLAY_TOP - 390)){
		m_Bottom -= PLAYER_UD_SPEED;
		m_Top -= PLAYER_UD_SPEED;
	}

	C_Rectangle::Scroll(m_Left, m_Right);              //スクロール処理
}


//プレイヤーの描画
void C_Player::Draw(){
	//待機モーションの描画
	if (!(CKey::Push(VK_RIGHT)
		|| CKey::Push(VK_LEFT)
		|| CKey::Push(VK_UP)
		|| CKey::Push(VK_DOWN))){
		if (m_Anime_Taiki >= 0){
			if (m_Turn == E_RIGHT)
				i_Chara_Motion_2.DrawImage(m_Left, m_Right, m_Bottom, m_Top, 0, 90, 135, 0);
			if (m_Turn == E_LEFT)
				i_Chara_Motion_2.DrawImage(m_Left, m_Right, m_Bottom, m_Top, 90, 0, 135, 0);
		}
		//1秒でアニメーションカウンタをリセットします
		else if (m_Anime_Taiki_s == 1){
			m_Anime_Taiki = 0;
			m_Anime_Taiki_s = 0;
		}
	}
	//移動モーションの描画
	else{
		//アニメーションカウンタを1秒分回す
		if (m_Anime < 60)++m_Anime;
		//アニメーションカウンタをリセットし、経過時間(秒)を追加する
		else if (m_Anime == 60){
			m_Anime = 0;
			++m_Anime_s;
		}
	}
}