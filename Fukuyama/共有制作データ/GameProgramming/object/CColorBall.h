#ifndef ColorBall_H
#define ColorBall_H

#include "../draw/CRectangle.h"
#include "C_Object.h"
#include "../chara/C_Player.h"

enum COLORBALL_STATE{
	E_NAGE,
	E_SET,
};

class C_ColorBall:public C_Object{
public:
	C_ColorBall()
		:C_Object(E_OBJ, eUDP_Object, eDWP_Object, 0, 0, 0)
		, m_Deltatime(2.0f/FPS)
		, init(false)
	{
		//カラーボールのステータスを設定します
		if (CKey::Push('C'))state = E_NAGE;
		if (CKey::Push('X'))state = E_SET;

		//カラーボールのサイズ
		m_image.SetVertex(0, 50, 0, 50);
		i_ColorBall.Load("../image/chara/chara_motion_2_16bit.tga");
	}

	CTexture i_ColorBall;
	float m_Deltatime;     //1秒間の処理回数
	C_Vector3 i_Throwpos;         //投げた位置
	int state;               //投げた球か設置の球か
	bool init;
	void Init();
	void Update();
	void Draw();
};

#endif