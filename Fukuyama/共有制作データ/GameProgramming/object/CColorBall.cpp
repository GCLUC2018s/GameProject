#include "CColorBall.h"


void C_ColorBall::Init(){
	if (C_Player::m_Playerpoint->m_Anime_Throw <= THROW_ANIME + 1){
		m_Anime_Throw = E_THROW;
	}
	else{
		m_Anime_Throw = E_NTHROW;
	}
	//カラーボールの影の初期位置の奥行を調整します
	i_Throwpos = C_Player::m_Playerpoint->m_Position;
	//カラーボールの影とボールを同期
	m_Position = i_Throwpos;

	//投げたカラーボールの場合
	if (m_State == E_NAGE){
		//カラーボールの初期位置の調整
		//右向き
		if (C_Player::m_Playerpoint->m_Turn == E_RIGHT){
			m_Position.x += 40;
			m_Position.z += 80;
			//カラーボールの初速
			m_Speed = C_Vector3(500, 4, 0);
		}
		//左向き
		else if (C_Player::m_Playerpoint->m_Turn == E_LEFT){
			m_Position.x -= 40;
			m_Position.z += 80;
			//カラーボールの初速
			m_Speed = C_Vector3(-500, 4, 0);
		}
	}
	else{
		//カラーボールの初期位置の調整
		//右向き
		if (C_Player::m_Playerpoint->m_Turn == E_RIGHT){
			m_Position.x += 35;
		}
		//左向き
		else if (C_Player::m_Playerpoint->m_Turn == E_LEFT){
			m_Position.x -= 35;
		}
	}

}

void C_ColorBall::Update()
{
	//Initを1度だけ呼びます（コンストラクタではm_PlayerpointがエラーになるためInitで処理します）
	if (init == false){
		Init();
		init = true;
	}

	//投げたカラーボールの場合
	if (m_State == E_NAGE){
		//重力加速度を速度へ反映
		m_Speed.x += m_Gravity.x*m_Deltatime;
		m_Speed.y += m_Gravity.y*m_Deltatime;
		m_Speed.z += m_Gravity.z*m_Deltatime;

		//速度をもとにポジションを更新
		m_Position.x += m_Speed.x*m_Deltatime;
		m_Position.y += m_Speed.y*m_Deltatime;
		m_Position.z += m_Speed.z*m_Deltatime;

		m_Position.z += m_Speed.y;

		//カラーボールが地面に落ちると消します
		if (m_Position.z <= i_Throwpos.z){
			SetKill();
		}
	}

	Rect(&m_image, &m_Position);             //画像の位置をm_Positionと同期します
	Scroll(&m_Position, m_Scroll);           //スクロール処理をします
}

void C_ColorBall::Draw(){

	//カラーボールの描画
	i_ColorBall.DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 0, 90, 140, 5);

}