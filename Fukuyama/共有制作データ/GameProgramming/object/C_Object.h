#ifndef C_OBJECT_H
#define C_OBJECT_H

#include "../task/CTask.h"
#include "CVector3.h"
#include "../draw/CRectangle.h"

class C_Object :public CTask{
protected:
	//コンストラクタでidとプライオリティの設定とメンバーの初期化
	C_Object(int id, int updatePrio, int drawPrio)
		:CTask(id, updatePrio, drawPrio)
		, m_Position(0.0f, 0.0f, 0.0f)
		, m_Speed(0.0f, 0.0f, 0.0f)
		, m_Scroll(m_Position.x+480)
		, m_GetScroll(0.0f)
	{}

	C_Rectangle m_image;  //メンバー変数にする
	C_Vector3 m_Position;  //座標を管理
	C_Vector3 m_Speed;  //速度を管理
	float m_GetScroll;  //スクロール基準点の保存
	void Rect(C_Rectangle* m_image,C_Vector3* p);  //ポジションの場所にC_Rectangle表示
	void Scroll(C_Vector3 *p);     //スクロール処理をします
	float m_Scroll;  //スクロール基準点
};

#endif