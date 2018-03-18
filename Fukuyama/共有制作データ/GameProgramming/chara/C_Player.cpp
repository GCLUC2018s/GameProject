#include "C_Player.h"

C_Player *C_Player::m_Playerpoint = 0;

void C_Player::Jump(C_Vector3& pos, C_Vector3& speed, const C_Vector3& gravity, float deltatime)
{
	speed.x += gravity.x*deltatime;
	speed.y += gravity.y*deltatime;
	speed.z += gravity.z*deltatime;

	pos.x += speed.x*deltatime;
	pos.y += speed.y*deltatime;
	pos.z += speed.z*deltatime;
	printf("最終結果（%f,%f,%f)    ", pos.x, pos.y, pos.z);
	printf("デルタタイム    %f\n", deltatime);
	//return pos;
}

void C_Player::Update(){

	if (m_Anime_Jump < 60){
		m_Anime_Jump++;
	}

	//Cキーでカラーボールを投げます
	if (CKey::Once('C')){
		C_ColorBall* ColorBall = new C_ColorBall();
	}

	//Xキーでカラーボールを設置します
	if (CKey::Once('X')){
		C_ColorBall* ColorBall = new C_ColorBall();
	}

	//もし着地モーション中なら操作ができない
	if (m_Anime_Jump > JUMP_ANIME){
		//Sキーでジャンプします
		if (CKey::Once('S') && m_Jump == E_NJUMP){
			//ジャンプしているかどうかタグをつけます
			m_Jump = E_JUMP;
			//ジャンプ処理を行う時間を計算します。
			m_JumpTime = -2 * (JUMP_FIRST_SPEED / m_Gravity.y);
		}
		//右移動
		if (CKey::Push(VK_RIGHT)){
			m_Turn = E_RIGHT;
			m_Scroll += PLAYER_LR_SPEED;
			m_Position.x += PLAYER_LR_SPEED;
			i_JumpPoint.x += PLAYER_LR_SPEED;
		}
		//左移動
		if (CKey::Push(VK_LEFT) && m_Position.x >= (-W_H) / 2){
			m_Turn = E_LEFT;
			m_Scroll -= PLAYER_LR_SPEED;
			m_Position.x -= PLAYER_LR_SPEED;
			i_JumpPoint.x -= PLAYER_LR_SPEED;
		}
		//上移動
		if (CKey::Push(VK_UP) && i_JumpPoint.z <= DISPLAY_TOP - 390){
			m_Position.z += PLAYER_UD_SPEED;
			i_JumpPoint.z += PLAYER_UD_SPEED;
		}
		//下移動
		if (CKey::Push(VK_DOWN) && i_JumpPoint.z >= DISPLAY_BOTTOM + 120 ){
			m_Position.z -= PLAYER_UD_SPEED;
			i_JumpPoint.z -= PLAYER_UD_SPEED;
		}
	}

		//ジャンプ中処理
	if (m_Jump==E_JUMP){
		//ジャンプ中の軌道計算
		Jump(m_Position, m_Speed, m_Gravity, 2.0f / FPS);
			m_Position.z += m_Speed.y;
		m_JumpTime -= 2.0 / FPS;
		//着地時処理
		if (m_JumpTime <= 0){
			//滞空時間の初期化
			m_JumpTime = 0;
			//ジャンプタグを無効化
			m_Jump = E_NJUMP;
			//位置計算用変数の初期化
			m_Position.y = 0;
			//ジャンプの初速を再設定
			m_Speed.y = JUMP_FIRST_SPEED;
			//影の位置とプレイヤーの位置を同期
			i_JumpPoint=m_Position;
			//着地時のアニメ用変数の初期化
			m_Anime_Jump = 0;
			//着地時誤差調整
			m_Position.z += 18;
			i_JumpPoint.z += 18;
		}
	}

	//スクロール基準点
	m_Scroll = m_Position.x + SCROLL_POINT;

	//スクロール処理（キャラと影）
	C_Object::Scroll(&m_Position, m_Scroll);
	C_Object::Scroll(&i_JumpPoint, m_Scroll);

	//キャラの描画位置をポジションと同期
	C_Object::Rect(&m_image,&m_Position);
	//影の描画位置をポジションと同期
	C_Object::Rect(&i_Shadow, &i_JumpPoint);
}

//プレイヤーの描画
void C_Player::Draw(){

	//影の描画
	i_Chara_Motion_2.DrawImage(i_Shadow.m_Left, i_Shadow.m_Right, i_Shadow.m_Bottom-3, i_Shadow.m_Top-3, 630, 720, 275, 140);

	//ジャンプしていない。かつ、投げモーション中でない。かつ、着地モーション中でない
	if (m_Jump == E_NJUMP&&m_Throw == E_NTHROW){
		m_Anime_Throw = 0;

		//着地アニメーション
		if (m_Anime_Jump <= JUMP_ANIME){
			if (m_Turn==E_RIGHT)
				i_Chara_Motion_2.DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 540, 630, 275, 140);
			else if (m_Turn==E_LEFT)
				i_Chara_Motion_2.DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 630, 540, 275, 140);
		}
		//着地硬直中でないなら
		else if(m_Anime_Jump>JUMP_ANIME){

			//移動用のキー入力があるなら
			if (CKey::Push(VK_LEFT) || CKey::Push(VK_RIGHT) || CKey::Push(VK_UP) || CKey::Push(VK_DOWN)){

				//ランニングアニメーションの描画
				RunAnime(&i_Chara_Motion_2, E_PLAYER);

			}
			else{
				m_Anime = -1;       //アニメーションを0～の範囲で行うので、使用しない時はー１とします。
					
				//待機絵の描画
				TaikiAnime(&i_Chara_Motion_2, E_PLAYER);
			}
		}
	}

	//ジャンプ中のアニメーション
	if (m_Jump == E_JUMP){
		//右向き
		if (m_Turn == E_RIGHT){
			if (m_Speed.y > 0){
				i_Chara_Motion_2.DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 360, 450, 275, 140);
			}
			else if (m_Speed.y < 0){
				i_Chara_Motion_2.DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 450, 540, 275, 140);
			}
		}
		//左向き
		else if (m_Turn == E_LEFT){
			if (m_Speed.y > 0){
				i_Chara_Motion_2.DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 450, 360, 275, 140);
			}
			else if (m_Speed.y < 0){
				i_Chara_Motion_2.DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 540, 450, 275, 140);
			}
		}
	}
}


//テストクラス

void C_Test::Update(){
	C_Object::Rect(&m_image, &m_Position);
	C_Object::Scroll(&m_Position, m_Scroll);
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