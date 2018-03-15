#include "C_Player.h"

void C_Player::Update(){

	//右移動
	if (CKey::Push(VK_RIGHT)){
		m_Turn = E_RIGHT;
		m_Scroll += PLAYER_LR_SPEED;
		m_Position.x += PLAYER_LR_SPEED;
	}
	//左移動
	if (CKey::Push(VK_LEFT) && m_Position.x >= (-W_H) / 2){
		m_Turn = E_LEFT;
		m_Scroll -= PLAYER_LR_SPEED;
		m_Position.x -= PLAYER_LR_SPEED;
	}
	//上移動
	if (CKey::Push(VK_UP) && m_Position.z <= DISPLAY_TOP - 390){
		m_Position.z += PLAYER_UD_SPEED;
	}
	//下移動
	if (CKey::Push(VK_DOWN) && m_Position.z >= DISPLAY_BOTTOM){
		m_Position.z -= PLAYER_UD_SPEED;
	}
	m_Scroll = m_Position.x + SCROLL_POINT;
	C_Object::Rect(&m_image,&m_Position);
	C_Object::Scroll(&m_Position,m_Scroll);
}

void C_Test::Update(){
	C_Object::Rect(&m_image, &m_Position);
	C_Object::Scroll(&m_Position,m_Scroll);
}

//プレイヤーの描画
void C_Player::Draw(){

	//アニメーションカウンタを1秒分回す
	if (m_Anime_Taiki <= 60)
		m_Anime_Taiki++;

	//アニメーションカウンタをリセットし
	else if (m_Anime_Taiki > 60){
		m_Anime_Taiki = 0;
	}

	if (!(CKey::Push(VK_LEFT) || CKey::Push(VK_RIGHT) || CKey::Push(VK_UP) || CKey::Push(VK_DOWN))){
		if (m_Anime_Taiki <= 60){
			if (m_Turn == E_RIGHT)
				i_Chara_Motion_2.DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 540, 630, 140, 5);
			else if (m_Turn == E_LEFT)
				i_Chara_Motion_2.DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 630, 540, 140, 5);
		}
	}

	//ランニングアニメのアニメーションカウンタを回す
	if (CKey::Push(VK_LEFT) || CKey::Push(VK_RIGHT) || CKey::Push(VK_UP) || CKey::Push(VK_DOWN)){
		//アニメーションカウンタを1秒分回す
		if (m_Anime < RUN_ANIME){
			m_Anime++;
		}
		//アニメーションカウンタをリセットし、経過時間(秒)を追加する
		if (m_Anime >= RUN_ANIME){
			m_Anime = 0;
		}
	}
	else{
		m_Anime = -1;       //アニメーションを0～の範囲で行うので、使用しない時はー１とします。
	}

	//移動モーション左
	if (CKey::Push(VK_LEFT)){
		if (!CKey::Push(VK_RIGHT)){
			if (m_Anime >= 0 && m_Anime < RUN_ANIME_INTERVAL){
				i_Chara_Motion_2.DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 90, 0, 140, 5);
			}
			else if (m_Anime < RUN_ANIME_INTERVAL * 2){
				i_Chara_Motion_2.DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 180, 90, 140, 5);
			}
			else if (m_Anime < RUN_ANIME_INTERVAL * 3){
				i_Chara_Motion_2.DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 270, 180, 140, 5);
			}
			else if (m_Anime < RUN_ANIME_INTERVAL * 4){
				i_Chara_Motion_2.DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 360, 270, 140, 5);
			}
			else if (m_Anime < RUN_ANIME_INTERVAL * 5){
				i_Chara_Motion_2.DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 450, 360, 140, 5);
			}
			else if (m_Anime < RUN_ANIME_INTERVAL * 6){
				i_Chara_Motion_2.DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 540, 450, 140, 5);
			}
			else if (m_Anime == RUN_ANIME - 1){
				m_Anime = 0;
			}
		}
	}

	//移動モーション右
	if (CKey::Push(VK_RIGHT)){
		if (!CKey::Push(VK_LEFT)){
			if (m_Anime >= 0 && m_Anime < RUN_ANIME_INTERVAL){
				i_Chara_Motion_2.DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 0, 90, 140, 5);
			}
			else if (m_Anime < RUN_ANIME_INTERVAL * 2){
				i_Chara_Motion_2.DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 90, 180, 140, 5);
			}
			else if (m_Anime < RUN_ANIME_INTERVAL * 3){
				i_Chara_Motion_2.DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 180, 270, 140, 5);
			}
			else if (m_Anime <RUN_ANIME_INTERVAL * 4){
				i_Chara_Motion_2.DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 270, 360, 140, 5);
			}
			else if (m_Anime <RUN_ANIME_INTERVAL * 5){
				i_Chara_Motion_2.DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 360, 450, 140, 5);
			}
			else if (m_Anime <RUN_ANIME_INTERVAL * 6){
				i_Chara_Motion_2.DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 450, 540, 140, 5);
			}
			else if (m_Anime == RUN_ANIME - 1){
				m_Anime = 0;
			}
		}
	}
	    //移動モーションの描画(右向き)
		if (CKey::Push(VK_UP)||CKey::Push(VK_DOWN)){
			if (m_Turn == E_RIGHT){
				if (m_Anime >= 0 && m_Anime < RUN_ANIME_INTERVAL){
					i_Chara_Motion_2.DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 0, 90, 140, 5);
				}
				else if (m_Anime < RUN_ANIME_INTERVAL * 2){
					i_Chara_Motion_2.DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 90, 180, 140, 5);
				}
				else if (m_Anime < RUN_ANIME_INTERVAL * 3){
					i_Chara_Motion_2.DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 180, 270, 140, 5);
				}
				else if (m_Anime <RUN_ANIME_INTERVAL * 4){
					i_Chara_Motion_2.DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 270, 360, 140, 5);
				}
				else if (m_Anime <RUN_ANIME_INTERVAL * 5){
					i_Chara_Motion_2.DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 360, 450, 140, 5);
				}
				else if (m_Anime <RUN_ANIME_INTERVAL * 6){
					i_Chara_Motion_2.DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 450, 540, 140, 5);
				}
				else if (m_Anime == RUN_ANIME-1){
					m_Anime = 0;
				}
			}
			if (m_Turn == E_LEFT){
				if (m_Anime >= 0 && m_Anime < RUN_ANIME_INTERVAL){
					i_Chara_Motion_2.DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 90, 0, 140, 5);
				}
				else if (m_Anime < RUN_ANIME_INTERVAL * 2){
					i_Chara_Motion_2.DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 180, 90, 140, 5);
				}
				else if (m_Anime < RUN_ANIME_INTERVAL * 3){
					i_Chara_Motion_2.DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 270, 180, 140, 5);
				}
				else if (m_Anime < RUN_ANIME_INTERVAL * 4){
					i_Chara_Motion_2.DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 360, 270, 140, 5);
				}
				else if (m_Anime < RUN_ANIME_INTERVAL * 5){
					i_Chara_Motion_2.DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 450, 360, 140, 5);
				}
				else if (m_Anime < RUN_ANIME_INTERVAL * 6){
					i_Chara_Motion_2.DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 540, 450, 140, 5);
				}
				else if (m_Anime == RUN_ANIME - 1){
					m_Anime = 0;
				}
			}
		}

		if (CKey::Push(VK_RIGHT) && CKey::Push(VK_LEFT)){
			if (m_Turn == E_RIGHT)
				i_Chara_Motion_2.DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 540, 630, 140, 5);
			else if (m_Turn == E_LEFT)
				i_Chara_Motion_2.DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 630, 540, 140, 5);
		}
}

void C_Test::Draw(){
	glBegin(GL_TRIANGLES);
	glVertex2d(m_image.m_Left, m_image.m_Top);
	glVertex2d(m_image.m_Left, m_image.m_Bottom);
	glVertex2d(m_image.m_Right, m_image.m_Bottom);
	glVertex2d(m_image.m_Left, m_image.m_Top);
	glVertex2d(m_image.m_Right, m_image.m_Bottom);
	glVertex2d(m_image.m_Right, m_image.m_Top);
	glEnd();
}