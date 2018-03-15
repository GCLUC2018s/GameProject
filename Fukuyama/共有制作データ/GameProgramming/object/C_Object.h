#ifndef C_OBJECT_H
#define C_OBJECT_H

#include "../task/CTask.h"
#include "CVector3.h"
#include "../draw/CRectangle.h"

class C_Object :public CTask{
public:
	//コンストラクタでidとプライオリティの設定とメンバーの初期化
	C_Object(int id, int updatePrio, int drawPrio, float posx, float posy, float posz)
		:CTask(id, updatePrio, drawPrio)
		, init(false)
		, m_Position(posx, posy, posz)
		, m_Speed(0.0f, 0.0f, 0.0f)
		, m_Gravity(0.0f,-9.8f,0.0f)
	{}
	bool init;  //Initを通ったかどうか
	void Init();
	C_Vector3 m_Position;  //座標を管理
	static float m_Scroll;  //スクロール基準点
protected:
	C_Rectangle m_image;  //メンバー変数にする
	C_Vector3 m_Speed;  //速度を管理
	C_Vector3 m_Gravity;  //重力
	void Rect(C_Rectangle* m_image,const C_Vector3* pos);  //ポジションの場所にC_Rectangle表示
	void Scroll(C_Vector3 *m_pos,float m_Scroll);     //スクロール処理をします
};
#endif