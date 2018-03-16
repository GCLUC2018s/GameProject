#include "CDrum.h"
//テクスチャクラスをインスタンス化
CTexture mTexture;
//アニメーションカウント
int m_DrumAnimationCount = 60;
//コンストラクタで初期化
C_Drum::C_Drum()
:C_Object(E_OBJ, eUDP_Object, eDWP_Object, DISPLAY_LEFT, 0, 0)
, m_DrumPos_Random(rand() % 3)
{
	//シードで乱数を初期化
	srand((unsigned)time(NULL));
	//0の場合、真ん中に配置
	if (m_DrumPos_Random == 0){
		m_Position.z += Zpos_SetPos_Center;
	}
	//1の場合、上に配置
	else if (m_DrumPos_Random == 1){
		m_Position.z += Zpos_SetPos_Up;
	}
	//2の場合、下に配置
	else if (m_DrumPos_Random == 2){
		m_Position.z += Zpos_SetPos_Down;
	}
	mTexture.Load("object/Drum.tga");
}

//更新処理
void C_Drum::Update(){
	Scroll(&m_Position, m_Scroll);
	m_Position.x += 2;
	m_DrumAnimationCount--;
	if (m_DrumAnimationCount >= 48){
		mTexture.DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 0, 128, 128, 0);
	}
	else if (m_DrumAnimationCount <= 48 && m_DrumAnimationCount >= 36){
		mTexture.DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 512, 640, 128, 0);
	}
	else if (m_DrumAnimationCount <= 36 && m_DrumAnimationCount >= 24){
		mTexture.DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 384, 512, 128, 0);
	}
	else if (m_DrumAnimationCount <= 24 && m_DrumAnimationCount >= 12){
		mTexture.DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 256, 384, 128, 0);
	}
	else if (m_DrumAnimationCount <= 12 && m_DrumAnimationCount >= 0){
		mTexture.DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 128, 256, 128, 0);
	}
	else{
		m_DrumAnimationCount = 60;
	}
}

//描画処理
void C_Drum::Draw(){
	m_image.SetVertex(-64, 64, -64, 64);
	Rect(&m_image, &m_Position);
}

