#include "CManhole.h"

//初期座標設定
#define FirstPotision W_H/2
//初期出現位置設定
#define Y_FirstPotision1 (-W_V/2)+120
#define Y_FirstPotision2 (W_V/2)-390
#define Under_Ypos_SetPotision (Y_FirstPotision1+Y_FirstPotision2)/2
//上出現
#define  Ypos_SetPos_Up (Under_Ypos_SetPotision+Y_FirstPotision2)/2
//下出現
#define Ypos_SetPos_Down (Under_Ypos_SetPotision+Y_FirstPotision1)/2
//移動
#define MoveSpeed 3
//サイズ設定と初期化コンストラクタ
//Init()と同じ意味
C_Manhole::C_Manhole()
:C_Rectangle(E_OBJ, eUDP_Object, eDWP_Object)
, m_UorD_rand(rand() % 2)
{
	//Texture設定
	//CTextureクラスをインスタンス化
	CTexture mTexture;
	//Textureロード
	mTexture.Load("Manhole.tga");
	//座標を決定
	mTexture.DrawImage(-64, 64, -64, 64, 0, 128, 128, 0);

	//シードで乱数を初期化
	srand((unsigned)time(NULL));

	//x,yの初期位置を決める
	m_PotisionX(FirstPotision);
	if (m_UorD_rand==0){
		m_PotisionY(Ypos_SetPos_Up);
	}
	else if (m_UorD_rand == 1){
		m_PotisionY(Ypos_SetPos_Down);
	}
}

//マンホールの簡易上下ポジション設定
float C_Manhole::m_PotisionY(float m_V){
	float mv = m_V;
	m_Top +=mv;
	m_Bottom += mv;
	return mv;
}

//マンホールの簡易左右ポジション設定
float C_Manhole::m_PotisionX(float m_H){
	float mh = m_H;
	m_Left +=  mh;
	m_Right +=mh;
	return mh;
}

//更新処理
void C_Manhole::Update(){

}

//描画処理
void C_Manhole::Draw(){
	m_Enabled = true;
	Render();
}