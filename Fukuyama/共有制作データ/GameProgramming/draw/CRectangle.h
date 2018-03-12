#ifndef CRECTANGLE_H
#define CRECTANGLE_H

#include "CTexture.h"
#include "../task/CTask.h"
#include "../task/CTaskManager.h"
#include "../CKey.h"

#define DISPLAY_BOTTOM -(W_H/2)    //�f�B�X�v���C�̉��[
#define DISPLAY_TOP W_H/2          //�f�B�X�v���C�̏�[
#define DISPLAY_LEFT -(W_V/2)      //�f�B�X�v���C�̍��[
#define DISPLAY_RIGHT W_V/2        //�f�B�X�v���C�̉E�[

class C_Rectangle:public CTask{
public:
	float m_Left, m_Right, m_Bottom, m_Top;
	float m_Adjust;
	void Init(){};
	void Update(){};
	void Render();
	void SetVertex(float left, float right, float bottom, float top);
	bool m_Enabled;
};

#endif