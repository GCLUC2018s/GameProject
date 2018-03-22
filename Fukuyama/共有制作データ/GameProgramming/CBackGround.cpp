#include "CBackGround.h"

#define TextureimageWide_BG 600

//背景用テクスチャをインスタンス化
CTexture BG1;
CTexture BG2;
//背景クラスのコンストラクタ
C_BackGround::C_BackGround()
:C_Object(E_BG, eUDP_Map, eDWP_Map, 0, 0, -450)
{
	BG1.Load("Asphalt&Sky.tga");
	m_image.SetVertex(-600, 600, -450, 450);
	BG2.Load("Asphalt&Sky.tga");
}

//背景クラスの更新処理
void C_BackGround::Update(){
	Scroll(&m_Position, m_Scroll);
	BG1.DrawImage(m_image.m_Left, m_image.m_Right, m_image.m_Bottom, m_image.m_Top //座標
		, 0, 1200, 900, 0 /*テクスチャ座標*/);
	BG2.DrawImage(m_image.m_Left + TextureimageWide_BG * 2, m_image.m_Right + TextureimageWide_BG * 2, m_image.m_Bottom, m_image.m_Top,
		0, 1200, 900, 0);
	if (m_image.m_Right <= -TextureimageWide_BG){
		m_Position.x += TextureimageWide_BG * 2;
	}
}

//テクスチャクラスを雲用にInstance化
CTexture i_CloudTexture;

//雲クラスのコンストラクタ
C_Cloud::C_Cloud()
:C_Object(E_BG, eUDP_Map, eDWP_Map, 0, 0, 0)
{
	//大きさを設定します
	m_image.SetVertex(-64, 64, -64, 64);
}

//雲クラスの更新処理
void C_Cloud::Update(){
	//スクロール
	Scroll(&m_Position, m_Scroll);
}

//背景クラスの描画処理
void C_BackGround::Draw(){
	Rect(&m_image, &m_Position);
}

//雲クラスの描画処理
void C_Cloud::Draw(){
	Rect(&m_image, &m_Position);
}