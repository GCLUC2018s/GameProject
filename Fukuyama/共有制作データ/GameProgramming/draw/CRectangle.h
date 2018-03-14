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
#define SCROLL_POINT W_H/100*SCROLL_PERCENTAGE-(W_H/2)   //スクロールの基準点の横座標
#define SCROLL_SPEED 8

#define Y_FirstPotision1 DISPLAY_BOTTOM+120  //ギミック初期出現位置設定1
#define Y_FirstPotision2 DISPLAY_TOP-390  //ギミック初期出現位置設定2
#define Ypos_SetPos_Center (Y_FirstPotision1+Y_FirstPotision2)/2  //中心出現
#define  Ypos_SetPos_Up (Ypos_SetPos_Center+Y_FirstPotision2)/2　//上出現
#define Ypos_SetPos_Down (Ypos_SetPos_Center+Y_FirstPotision1)/2　//下出現

class C_Rectangle :public CTask{

protected:
	//左右ポジション
	float m_PotisionX(float m_H);

	//上下ポジション
	float m_PotisionY(float m_V);

	C_Rectangle(){
		m_Scroll = 210;
	}

public:
	C_Rectangle(int id, int updatePrio, int drawPrio) :CTask(id, updatePrio, drawPrio){}
	float m_Left, m_Right, m_Bottom, m_Top;
	float m_Adjust;
	void Init(){};
	void Update(){};
	void Render();
	void SetVertex(float left, float right, float bottom, float top);
	bool m_Enabled;
	float m_Scroll;
	void Scroll(C_Rectangle*p);
};

#endif