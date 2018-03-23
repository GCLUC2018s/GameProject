#include "C_Object.h"

float C_Object::m_Scroll = SCROLL_POINT;

void C_Object::Rect(C_Rectangle *image,const C_Vector3* pos){
	image->m_wide = (image->m_Right - image->m_Left) / 2;  //ポジションからC_Rectangleの左右までの距離
	image->m_high = (image->m_Top - image->m_Bottom);  //高さ
	image->m_Right = pos->x + image->m_wide;
	image->m_Left = pos->x - image->m_wide;
	image->m_Bottom = pos->z;
	image->m_Top = image->m_Bottom +image->m_high;
	return;
}

void C_Object::Scroll(C_Vector3 *m_pos,float m_Scroll){
	if (CKey::Push(VK_RIGHT) && m_Scroll >= DISPLAY_RIGHT){
		m_pos->x -= SCROLL_SPEED;
		if (m_id == E_PLAYER){
			m_Scroll -= SCROLL_SPEED;
		}
	}
	return;
}


/*
ランニングアニメの描画
image・・・使用する画像
id・・・キャラクターの識別（m_idを使用してください）
*/
void C_Object::RunAnime(CTexture *image, int id){

	//ランニングアニメーションカウンタを1秒分回す
	if (m_Anime < RUN_ANIME){
		m_Anime++;
	}
	//ランニングアニメーションカウンタをリセットします。
	if (m_Anime >= RUN_ANIME){
		m_Anime = 0;
	}

	//idがプレイヤーの時の描画を行います
	if (id == E_PLAYER){
		//移動モーション左
		if (CKey::Push(VK_LEFT)){
			if (!CKey::Push(VK_RIGHT)){
				if (m_Anime >= 0 && m_Anime < RUN_ANIME_INTERVAL){
					image->DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 90, 0, 140, 5);
				}
				else if (m_Anime < RUN_ANIME_INTERVAL * 2){
					image->DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 180, 90, 140, 5);
				}
				else if (m_Anime < RUN_ANIME_INTERVAL * 3){
					image->DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 270, 180, 140, 5);
				}
				else if (m_Anime < RUN_ANIME_INTERVAL * 4){
					image->DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 360, 270, 140, 5);
				}
				else if (m_Anime < RUN_ANIME_INTERVAL * 5){
					image->DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 450, 360, 140, 5);
				}
				else if (m_Anime < RUN_ANIME_INTERVAL * 6){
					image->DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 540, 450, 140, 5);
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
					image->DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 0, 90, 140, 5);
				}
				else if (m_Anime < RUN_ANIME_INTERVAL * 2){
					image->DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 90, 180, 140, 5);
				}
				else if (m_Anime < RUN_ANIME_INTERVAL * 3){
					image->DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 180, 270, 140, 5);
				}
				else if (m_Anime < RUN_ANIME_INTERVAL * 4){
					image->DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 270, 360, 140, 5);
				}
				else if (m_Anime < RUN_ANIME_INTERVAL * 5){
					image->DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 360, 450, 140, 5);
				}
				else if (m_Anime < RUN_ANIME_INTERVAL * 6){
					image->DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 450, 540, 140, 5);
				}
				else if (m_Anime == RUN_ANIME - 1){
					m_Anime = 0;
				}
			}
		}

		//移動モーションの描画(右向き)
		if (CKey::Push(VK_UP) || CKey::Push(VK_DOWN)){
			if (m_Turn == E_RIGHT){
				if (m_Anime >= 0 && m_Anime < RUN_ANIME_INTERVAL){
					image->DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 0, 90, 140, 5);
				}
				else if (m_Anime < RUN_ANIME_INTERVAL * 2){
					image->DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 90, 180, 140, 5);
				}
				else if (m_Anime < RUN_ANIME_INTERVAL * 3){
					image->DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 180, 270, 140, 5);
				}
				else if (m_Anime < RUN_ANIME_INTERVAL * 4){
					image->DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 270, 360, 140, 5);
				}
				else if (m_Anime < RUN_ANIME_INTERVAL * 5){
					image->DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 360, 450, 140, 5);
				}
				else if (m_Anime < RUN_ANIME_INTERVAL * 6){
					image->DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 450, 540, 140, 5);
				}
				else if (m_Anime == RUN_ANIME - 1){
					m_Anime = 0;
				}
			}
			if (m_Turn == E_LEFT){
				if (m_Anime >= 0 && m_Anime < RUN_ANIME_INTERVAL){
					image->DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 90, 0, 140, 5);
				}
				else if (m_Anime < RUN_ANIME_INTERVAL * 2){
					image->DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 180, 90, 140, 5);
				}
				else if (m_Anime < RUN_ANIME_INTERVAL * 3){
					image->DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 270, 180, 140, 5);
				}
				else if (m_Anime < RUN_ANIME_INTERVAL * 4){
					image->DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 360, 270, 140, 5);
				}
				else if (m_Anime < RUN_ANIME_INTERVAL * 5){
					image->DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 450, 360, 140, 5);
				}
				else if (m_Anime < RUN_ANIME_INTERVAL * 6){
					image->DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 540, 450, 140, 5);
				}
				else if (m_Anime == RUN_ANIME - 1){
					m_Anime = 0;
				}
			}
		}

		//右と左を同時に入力した場合は待機絵を描画
		if (CKey::Push(VK_RIGHT) && CKey::Push(VK_LEFT)){
			if (m_Turn == E_RIGHT)
				image->DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 540, 630, 140, 5);
			else if (m_Turn == E_LEFT)
				image->DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 630, 540, 140, 5);
		}
	}

	//プレイヤー以外のキャラクターのランニングアニメーション
	else{
		//左向き
		if (m_Turn == E_LEFT){
			if (m_Anime >= 0 && m_Anime < RUN_ANIME_INTERVAL){
				image->DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 90, 0, 140, 5);
			}
			else if (m_Anime < RUN_ANIME_INTERVAL * 2){
				image->DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 180, 90, 140, 5);
			}
			else if (m_Anime < RUN_ANIME_INTERVAL * 3){
				image->DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 270, 180, 140, 5);
			}
			else if (m_Anime < RUN_ANIME_INTERVAL * 4){
				image->DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 360, 270, 140, 5);
			}
			else if (m_Anime < RUN_ANIME_INTERVAL * 5){
				image->DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 450, 360, 140, 5);
			}
			else if (m_Anime < RUN_ANIME_INTERVAL * 6){
				image->DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 540, 450, 140, 5);
			}
			else if (m_Anime == RUN_ANIME - 1){
				m_Anime = 0;
			}
		}
		//右向き
		else{
			if (m_Anime >= 0 && m_Anime < RUN_ANIME_INTERVAL){
				image->DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 0, 90, 140, 5);
			}
			else if (m_Anime < RUN_ANIME_INTERVAL * 2){
				image->DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 90, 180, 140, 5);
			}
			else if (m_Anime < RUN_ANIME_INTERVAL * 3){
				image->DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 180, 270, 140, 5);
			}
			else if (m_Anime < RUN_ANIME_INTERVAL * 4){
				image->DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 270, 360, 140, 5);
			}
			else if (m_Anime < RUN_ANIME_INTERVAL * 5){
				image->DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 360, 450, 140, 5);
			}
			else if (m_Anime < RUN_ANIME_INTERVAL * 6){
				image->DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 450, 540, 140, 5);
			}
			else if (m_Anime == RUN_ANIME - 1){
				m_Anime = 0;
			}
		}

	}
}



/*
待機アニメの描画
image・・・使用する画像
id・・・キャラクターの識別（m_idを使用してください）
*/
void C_Object::TaikiAnime(CTexture *image, int id){

	//待機用アニメーションカウンタを1秒分回す
	if (m_Anime_Taiki <= 60)
		m_Anime_Taiki++;

	//待機用アニメーションカウンタをリセット
	else if (m_Anime_Taiki > 60)
		m_Anime_Taiki = 0;


	//移動用のキー入力がなければ待機絵を描画
	if (m_Anime_Taiki <= 60){
		if (m_Turn == E_RIGHT)
			image->DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 540, 630, 140, 5);
		else if (m_Turn == E_LEFT)
			image->DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 630, 540, 140, 5);
	}
}
void C_Object::EnemyTaiki(CTexture *image, int id){
	if (m_Turn == E_RIGHT)
		image->DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 714, 804, 140, 5);
	else if (m_Turn == E_LEFT)
		image->DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 804, 714, 140, 5);
}