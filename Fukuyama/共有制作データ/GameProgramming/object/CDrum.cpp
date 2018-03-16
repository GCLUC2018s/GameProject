#include "CDrum.h"
//テクスチャクラスをインスタンス化
CTexture mTexture;

int C_Drum::Dmain(){
	//シードで乱数を初期化
	srand((unsigned)time(NULL));
	return 0;
}

//アニメーションカウント
int m_DrumAnimationCount = 30;
//ドラム缶の移動処理
#define Drum_Move 10
//コンストラクタで初期化
C_Drum::C_Drum()
:C_Object(E_OBJ, eUDP_Object, eDWP_Object, DISPLAY_RIGHT, 0, 0)
, m_DrumPos_Random(rand() % 3)
{
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
	//画面左端に行った時
	if (m_Position.x < DISPLAY_LEFT){
		SetKill();
		new C_Drum();
	}
	m_DrumAnimationCount--;
	m_Position.x -= Drum_Move;
	//アニメーション処理
	if (m_DrumAnimationCount >= 24){
		mTexture.DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 0, 128, 128, 0);
	}
	else if (m_DrumAnimationCount <= 24 && m_DrumAnimationCount >= 18){
		mTexture.DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 128, 256, 128, 0);
	}
	else if (m_DrumAnimationCount <= 18 && m_DrumAnimationCount >= 12){
		mTexture.DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 256, 384, 128, 0);
	}
	else if (m_DrumAnimationCount <= 12 && m_DrumAnimationCount >= 6){
		mTexture.DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 384, 512, 128, 0);
	}
	else if (m_DrumAnimationCount <= 6 && m_DrumAnimationCount >= 0){
		mTexture.DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 512, 640, 128, 0);
	}
	else{
		m_DrumAnimationCount = 30;
	}
}

//描画処理
void C_Drum::Draw(){
	m_image.SetVertex(-64, 64, -64, 64);
	Rect(&m_image, &m_Position);
}

