#include "C_Player.h"

void C_Player::Update(){

	//右移動
	if (CKey::Push(VK_RIGHT)){
		m_Turn = E_RIGHT;
		m_Scroll += PLAYER_LR_SPEED;
		m_Right += PLAYER_LR_SPEED;
		m_Left += PLAYER_LR_SPEED;
	}
	//左移動
	if (CKey::Push(VK_LEFT)&&m_Left>=(-W_H)/2){
		m_Turn = E_LEFT;
		m_Scroll -= PLAYER_LR_SPEED;
		m_Right -= PLAYER_LR_SPEED;
		m_Left -= PLAYER_LR_SPEED;
	}
	//上移動
	if (CKey::Push(VK_UP) &&m_Bottom <= DISPLAY_TOP - 390){
		m_Bottom += PLAYER_UD_SPEED;
		m_Top += PLAYER_UD_SPEED;
	}
	//下移動
	if (CKey::Push(VK_DOWN) && m_Bottom >= DISPLAY_BOTTOM){
		m_Bottom -= PLAYER_UD_SPEED;
		m_Top -= PLAYER_UD_SPEED;
	}

		C_Rectangle::Scroll(this);              //スクロール処理
}


//プレイヤーの描画
void C_Player::Draw(){

	//アニメーションカウンタを1秒分回す
	if (m_Anime_Taiki < 60)
		++m_Anime_Taiki;

	//アニメーションカウンタをリセットし、経過時間(秒)を追加する
	else if (m_Anime_Taiki == 60){
		m_Anime_Taiki = 0;
		++m_Anime_Taiki_s;
	}

	i_Chara_Motion_2.DrawImage(m_Left, m_Right, m_Bottom, m_Top, 0, 90, 140, 5);
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