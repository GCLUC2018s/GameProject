#include "CDrum.h"

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
}

//更新処理
void C_Drum::Update(){

}

//描画処理
void C_Drum::Draw(){

}

