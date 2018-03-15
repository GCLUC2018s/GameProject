#ifndef CRECTANGLE_H
#define CRECTANGLE_H

#include "CTexture.h"
#include "../task/CTask.h"
#include "windows.h"
#include "../CKey.h"
#include "time.h"
#include "random"

#define W_H		1200 //Window幅
#define W_V		900 //Window高さ
#define DISPLAY_BOTTOM -(W_V/2)    //ディスプレイの下端
#define DISPLAY_TOP W_V/2          //ディスプレイの上端
#define DISPLAY_LEFT -(W_H/2)      //ディスプレイの左端
#define DISPLAY_RIGHT W_H/2        //ディスプレイの右端
#define SCROLL_PERCENTAGE 60   //スクロールの基準点（左基準でパーセント換算）
#define SCROLL_POINT 480   //キャラとスクロールの距離
#define SCROLL_SPEED 6

#define Z_FirstPotision1 DISPLAY_BOTTOM+120 //ギミック初期出現位置設定1
#define Z_FirstPotision2 DISPLAY_TOP-390 //ギミック初期出現位置設定2
#define Zpos_SetPos_Center (Z_FirstPotision1+Z_FirstPotision2)/2 //中心出現
#define Zpos_SetPos_Up (Zpos_SetPos_Center+Z_FirstPotision2)/2//上出現
#define Zpos_SetPos_Down (Zpos_SetPos_Center+Z_FirstPotision1)/2//下出現
#define TestSpeed 3 //ギミック確認用移動マクロ

class C_Rectangle{
protected:
	//左右ポジション
	float m_PotisionX(float m_H);

	//上下ポジション
	float m_PotisionY(float m_V);

public:
	C_Rectangle()
		:m_wide(0)
		,m_high(0)
		,m_Left(0)
		,m_Right(0)
		,m_Bottom(0)
		,m_Top(0)
	{}

	float m_wide, m_high;
	float m_Left, m_Right, m_Bottom, m_Top;
	float m_Adjust;
	void Render();
	void SetVertex(float left, float right, float bottom, float top);
	bool m_Enabled;
};

#endif