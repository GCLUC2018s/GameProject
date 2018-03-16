#include "CColorBall.h"
void C_ColorBall::Init(){
	//カラーボールの影の初期位置の奥行を調整します
	i_Throwpos = C_Player::m_Playerpoint->m_Position;
	//カラーボールの影とボールを同期
	m_Position = i_Throwpos;
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

void C_ColorBall::Update()
{
	if (init == false){
		Init();
		init = true;
	}

	m_Speed.x += m_Gravity.x*m_Deltatime;
	m_Speed.y += m_Gravity.y*m_Deltatime;
	m_Speed.z += m_Gravity.z*m_Deltatime;

	m_Position.x += m_Speed.x*m_Deltatime;
	m_Position.y += m_Speed.y*m_Deltatime;
	m_Position.z += m_Speed.z*m_Deltatime;

	m_Position.z += m_Speed.y;

	if (m_Position.z <= i_Throwpos.z){
		SetKill();
	}

	Rect(&m_image, &m_Position);
	Scroll(&m_Position, m_Scroll);
}

void C_ColorBall::Draw(){
	if (init==true)
	i_ColorBall.DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 0, 90, 140, 5);
}