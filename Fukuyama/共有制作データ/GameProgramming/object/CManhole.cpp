#include "CManhole.h"

//サイズ設定と初期化コンストラクタ
//Init()と同じ意味
C_Manhole::C_Manhole()
:C_Object(E_OBJ, eUDP_Object, eDWP_Object)
, m_UorD_rand(rand() % 3)
{
	//シードで乱数を初期化
	srand((unsigned)time(NULL));
	//x,yの初期位置を決める
	m_Position.x+=DISPLAY_RIGHT;
	if (m_UorD_rand==0){
		m_Position.y+=Ypos_SetPos_Center;
	}
	else if (m_UorD_rand == 1){
		m_Position.y+=Ypos_SetPos_Up;
	}
	else if (m_UorD_rand == 2){
		m_Position.y+=Ypos_SetPos_Down;
	}
}

//更新処理
void C_Manhole::Update(){
}

//描画処理
void C_Manhole::Draw(){
	//Texture設定
	//CTextureクラスをインスタンス化
	CTexture mTexturet;
	//Textureロード
	mTexturet.Load("manhole.tga");
	//座標を決定
	mTexturet.DrawImage(-64, 64, -64, 64, 0, 128, 128, 0);
}