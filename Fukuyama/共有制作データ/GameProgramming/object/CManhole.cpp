#include "CManhole.h"

//サイズ設定と初期化コンストラクタ
//Init()と同じ意味
C_Manhole::C_Manhole()
:C_Object(E_OBJ, eUDP_Object, eDWP_Object, DISPLAY_RIGHT, 0, 0)
, m_UorD_rand(rand() % 3)
{
	//シードで乱数を初期化
	srand((unsigned)time(NULL));
	//0の場合、真ん中に配置
	if (m_UorD_rand == 0){
		m_Position.z += Zpos_SetPos_Center;
	}
	//1の場合、上に配置
	else if (m_UorD_rand == 1){
		m_Position.z += Zpos_SetPos_Up;
	}
	//2の場合、下に配置
	else if (m_UorD_rand == 2){
		m_Position.z += Zpos_SetPos_Down;
	}
}

//更新処理
void C_Manhole::Update(){
	Scroll(&m_Position, m_Scroll);
	//右辺が画面左端よりも小さくなった場合
	if (m_image.m_Right<DISPLAY_LEFT){
		//削除して、新しく追加
		SetKill();
		new C_Manhole();
	}
	//右辺が画面左端よりも大きい場合
	else{
		//スクロールする
		
	}
	if (CKey::Push('A')){
		m_Position.x -= TestSpeed;
	}
	//描画
	Rect(&m_image, &m_Position);
	printf("%f\n", m_image.m_Top);
}

//描画処理
void C_Manhole::Draw(){
	//Texture設定
	//CTextureクラスをインスタンス化
	CTexture mTexture;
	//Textureロード
	mTexture.Load("object/manhole.tga");
	//座標を決定
	mTexture.DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top, 0, 128, 128, 0);
	m_image.SetVertex(-64, 64, -64, 64);
}