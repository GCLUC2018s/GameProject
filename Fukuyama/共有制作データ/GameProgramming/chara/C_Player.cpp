#include "C_Player.h"
<<<<<<< HEAD

void C_Player::Update(){

=======
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

	//アニメーションカウンタ初期化待機
	if (!(CKey::Once(VK_RIGHT) || CKey::Once(VK_LEFT)
		|| CKey::Once(VK_UP) || CKey::Once(VK_DOWN))){
		if (m_Anime != 0)m_Anime = 0;
		if (m_Anime_s != 0)m_Anime_s = 0;
	}

	//アニメーションカウンタを1秒分回す
	if (m_Anime_Taiki < 60)++m_Anime_Taiki;
	//アニメーションカウンタをリセットし、経過時間(秒)を追加する
	else if (m_Anime_Taiki == 60){
		m_Anime_Taiki = 0;
		++m_Anime_Taiki_s;
	}

>>>>>>> 9e6ac9599803c436e33464c8b2ecadeed50fff5f
	//右移動
	if (CKey::Push(VK_RIGHT)){
		m_Turn = E_RIGHT;
		m_Right += PLAYER_LR_SPEED;
		m_Left += PLAYER_LR_SPEED;
	}
	//左移動
<<<<<<< HEAD
	if (CKey::Push(VK_LEFT)&&m_Left>=(-W_H)/2){
=======
	else if (CKey::Push(VK_LEFT)){
>>>>>>> 9e6ac9599803c436e33464c8b2ecadeed50fff5f
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

<<<<<<< HEAD
		C_Scroll::Scroll(this);              //スクロール処理
=======
	C_Rectangle::Scroll(m_Left, m_Right);              //スクロール処理
>>>>>>> 9e6ac9599803c436e33464c8b2ecadeed50fff5f
}


//プレイヤーの描画
void C_Player::Draw(){
<<<<<<< HEAD

	//アニメーションカウンタを1秒分回す
	if (m_Anime_Taiki < 60)
		++m_Anime_Taiki;

	//アニメーションカウンタをリセットし、経過時間(秒)を追加する
	else if (m_Anime_Taiki == 60){
		m_Anime_Taiki = 0;
		++m_Anime_Taiki_s;
	}

	i_Chara_Motion_2.DrawImage(m_Left, m_Right, m_Bottom, m_Top, 0, 90, 140, 5);
=======
>>>>>>> 9e6ac9599803c436e33464c8b2ecadeed50fff5f
	//待機モーションの描画
	if (m_Anime_Taiki >= 0 && m_Anime_Taiki <= 60){
		if (m_Turn == E_RIGHT)
			i_Chara_Motion_2.DrawImage(m_Left, m_Right, m_Bottom, m_Top, 0, 90, 140, 5);
		if (m_Turn == E_LEFT)
			i_Chara_Motion_2.DrawImage(m_Left, m_Right, m_Bottom, m_Top, 90, 0, 140, 5);
	}

	//移動モーションの描画(左向き)
		if (CKey::Push(VK_LEFT)||CKey::Push(VK_UP)||CKey::Push(VK_DOWN)){
			//アニメーションカウンタを1秒分回す
			if (m_Anime < 60)++m_Anime;
			//アニメーションカウンタをリセットし、経過時間(秒)を追加する
			if (m_Anime == 60){
				m_Anime = 0;
				++m_Anime_s;
			}
			if (m_Turn == E_LEFT){
			
			}

		}
		else{
			m_Anime = 0;
			m_Anime_s = 0;
		}
}