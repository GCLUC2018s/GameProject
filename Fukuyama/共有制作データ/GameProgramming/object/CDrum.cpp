#include "CDrum.h"

C_Drum::C_Drum()
:m_DrumPos_Random(rand() % 3)
, C_Rectangle(E_OBJ, eUDP_Object, eDWP_Object)
{
	//ドラム缶のXポジション設定
	m_PotisionX(DISPLAY_RIGHT);
	//シードで乱数初期化
	srand((unsigned)time(NULL));
	//
	switch (m_DrumPos_Random){
		//case 0の時
		//ドラム缶の位置を真ん中へ
	case 0:
		m_PotisionY(Ypos_SetPos_Center);
		break;
		//case 1の時
		//ドラム缶の位置を上へ
	case 1:
		m_PotisionY(Ypos_SetPos_Up);
		break;
	}
}

//更新処理
void C_Drum::Update(){

}

//描画処理
void C_Drum::Draw(){

}

