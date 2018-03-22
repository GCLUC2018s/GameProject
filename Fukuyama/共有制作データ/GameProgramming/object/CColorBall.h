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
		//�J���[�{�[���̃T�C�Y
		m_image.SetVertex(0, 30, 0, 30);
		//�e�̃T�C�Y
		i_Shadow.SetVertex(0, 30, 0, 50);

		i_ColorBall.Load("image/bg/color/tga/colorball03.tga");
	}
private:
	C_Vector3 ShadowPos;
	CTexture i_ColorBall;
	float m_Deltatime;       //1�b�Ԃ̏�����
	C_Vector3 i_Throwpos;         //�������ʒu
	int m_State;        //�����������ݒu�̋���
	bool init;
	void Init();
	void Update();
	void Draw();
};

#endif