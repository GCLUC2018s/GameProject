#include"Hagi.h"

void Hagi::Update(){
	if (i_iconShadow.m_Top > i_iconShadow.m_Bottom)
		i_iconShadow.m_Top -= m_CoolTime;
	if (i_iconShadow.m_Top <= i_iconShadow.m_Bottom){
		i_iconShadow.m_Top = i_iconShadow.m_Bottom;
	}
	//プレイヤーがスプレーを使うとアイコンに影を落とす
	if (i_iconShadow.m_Top<=i_iconShadow.m_Bottom
		&& i_iconShadow.m_Top >= i_iconShadow.m_Bottom
		&& CKey::Once('Z')){
		i_iconShadow.m_Top = i_iconShadow.m_Bottom + 90;
	}
}

void Hagi::Draw(){
	Icon.DrawImage(-585, -495, -435, -345, 0, 90, 90, 0);
	i_iconShadow.Render(0.0f, 0.0f, 0.0f, 0.5f);
}