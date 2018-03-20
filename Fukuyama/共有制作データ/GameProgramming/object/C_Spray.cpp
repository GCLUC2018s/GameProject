#include "C_Spray.h"


void C_Spray::Init(){

	//カラーボールの影の初期位置の奥行を調整します
	i_ShadowPos = C_Player::m_Playerpoint->m_Position;
	//カラーボールの影とボールを同期
	m_Position = i_ShadowPos;

	//カラーボールの初期位置の調整
	//右向き
	if (C_Player::m_Playerpoint->m_Turn == E_RIGHT){
		m_Position.x += 40;
		m_Position.z += 70;
	}
	//左向き
	else if (C_Player::m_Playerpoint->m_Turn == E_LEFT){
		m_Position.x -= 40;
		m_Position.z += 70;
	}
}

void C_Spray::Update(){

	//Initを1度だけ呼びます（コンストラクタではm_PlayerpointがエラーになるためInitで処理します）
	if (init == false){
		Init();
		init = true;
	}


}

void C_Spray::Draw(){

	//アルファブレンドを有効にする
	glEnable(GL_BLEND);
	//ブレンド方法を指定
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glBegin(GL_TRIANGLES);
	glVertex2d(m_image.m_Left, m_image.m_Top);
	glVertex2d(m_image.m_Left, m_image.m_Bottom);
	glVertex2d(m_image.m_Right, m_image.m_Bottom);
	glVertex2d(m_image.m_Left, m_image.m_Top);
	glVertex2d(m_image.m_Right, m_image.m_Bottom);
	glVertex2d(m_image.m_Right, m_image.m_Top);
	glEnd();

	//アルファブレンドを無効
	glDisable(GL_BLEND);
	//テクスチャを無効
	glDisable(GL_TEXTURE_2D);

}