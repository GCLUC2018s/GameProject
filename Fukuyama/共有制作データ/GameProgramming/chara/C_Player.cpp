#include "C_Player.h"

void C_Player::Init(){
	//アニメーションカウンタの初期化
	m_Anime = 0;
	m_Anime_s = 0;
}

void C_Player::Update(){
	//アニメーションカウンタを1秒分回す
	if (m_Anime < 60)++m_Anime;
	//アニメーションカウンタをリセットし、経過時間を追加する
	else if (m_Anime == 60){
		m_Anime = 0;
		++m_Anime_s;
	}

	
}
void C_Player::Draw(){
	if (!(CKey::Push(VK_RIGHT) 
		|| CKey::Push(VK_LEFT)
		|| CKey::Push(VK_UP)
		|| CKey::Push(VK_DOWN))){
		if (m_Anime >= 0){
			i_Chara_Motion_1.DrawImage(m_Left, m_Right, m_Bottom, m_Top, 0, 90, 135, 0);
		}
	}
}