#ifndef ColorBall_H
#define ColorBall_H

#include "../draw/CRectangle.h"
#include "C_Object.h"
#include "../chara/C_Player.h"
#include "../task/CTaskManager.h"

#define DELTATIME 1.0f / FPS

enum COLORBALL_STATE{
	E_NAGE,
	E_OKI,
};

class C_ColorBall:public C_Object{
public:
	C_ColorBall()
		:C_Object(E_ATACK, eUDP_Object, eDWP_Object, 0, 0, 0)
		, ShadowPos(0.0f,0.0f,0.0f)
		, m_Deltatime(DELTATIME)
		, init(false)
	{
		//カラーボールのサイズ
		m_image.SetVertex(0, 30, 0, 30);
		//影のサイズ
		i_Shadow.SetVertex(0, 30, 0, 50);

		i_ColorBall.Load("image/bg/color/tga/colorball03.tga");
	}
private:
	C_Vector3 ShadowPos;
	CTexture i_ColorBall;
	float m_Deltatime;       //1秒間の処理回数
	C_Vector3 i_Throwpos;         //投げた位置
	int m_State;        //投げた球か設置の球か
	bool init;
	void Init();
	void Update();
	void Draw();
};

#endif