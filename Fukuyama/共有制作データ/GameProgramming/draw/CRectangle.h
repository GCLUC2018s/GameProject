#ifndef CRECTANGLE_H
#define CRECTANGLE_H

#include "CTexture.h"
#include "../task/CTask.h"
#include "windows.h"
#include "../CKey.h"

#define W_H		1200 //Window��
#define W_V		900 //Window����
#define DISPLAY_BOTTOM -(W_H/2)    //�f�B�X�v���C�̉��[
#define DISPLAY_TOP W_H/2          //�f�B�X�v���C�̏�[
#define DISPLAY_LEFT -(W_V/2)      //�f�B�X�v���C�̍��[
#define DISPLAY_RIGHT W_V/2        //�f�B�X�v���C�̉E�[
#define PLAYER_LR_SPEED 3     //�v���C���[�̍��E�ړ����x
#define PLAYER_UD_SPEED 1     //�v���C���[�̏㉺�ړ����x
#define SCROLL_PERCENTAGE 60   //�X�N���[���̊�_�i����Ńp�[�Z���g���Z�j
#define SCROLL_POINT W_H/100*SCROLL_PERCENTAGE-(W_H/2)   //�X�N���[���̊�_�̉����W


class C_Rectangle :public CTask{
public:
<<<<<<< HEAD
	C_Rectangle(int id, int updatePrio, int drawPrio) :CTask(id, updatePrio, drawPrio){}
=======
	void Scroll(float left, float right);
>>>>>>> 9e6ac9599803c436e33464c8b2ecadeed50fff5f
	float m_Left, m_Right, m_Bottom, m_Top;
	float m_Adjust;
	void Init(){};
	void Update(){};
	void Render();
	void SetVertex(float left, float right, float bottom, float top);
	bool m_Enabled;
};

#endif