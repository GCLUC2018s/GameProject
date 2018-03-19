#ifndef ColorBall_H
#define ColorBall_H

#include "../draw/CRectangle.h"
#include "C_Object.h"
#include "../chara/C_Player.h"

enum COLORBALL_STATE{
	E_NAGE,
	E_OKI,
};

class C_ColorBall:public C_Object{
public:
	C_ColorBall()
		:C_Object(E_OBJ, eUDP_Object, eDWP_Object, 0, 0, 0)
		, m_Deltatime(2.0f/FPS)
		, init(false)
	{
		//カラーボールのサイズ
		m_image.SetVertex(0, 50, 0, 50);
		i_ColorBall.Load("image/bg/color/tga/colorball.tga");
	}

	CTexture i_ColorBall;
	float m_Deltatime;     //1秒間の処理回数
	C_Vector3 i_Throwpos;         //投げた位置
	int m_State;               //投げた球か設置の球か
	bool init;
	void Init();
	void Update();
	void Draw();
};

#endif