#include"Hagi.h"

void Hagi::Update(){
	float m_CoolTime = ICON_SIZE;
		m_CoolTime=m_CoolTime/ SPRAY_INTERVAL;      //スプレーのクールタイム表示（アイコン）

	i_iconShadow.m_Top -= m_CoolTime;
	if (i_iconShadow.m_Top <= i_iconShadow.m_Bottom){
		i_iconShadow.m_Top = i_iconShadow.m_Bottom;
	}
	if (C_Player::m_Playerpoint->m_Anime_Spray == 0){
		i_iconShadow.m_Top = i_iconShadow.m_Bottom + ICON_SIZE;
	}
}

void Hagi::Draw(){
	Icon.DrawImage(-585, -495, -435, -345, 0, 90, 90, 0);
	i_iconShadow.Render(0.0f, 0.0f, 0.0f, 0.5f);
}