#ifndef CBACKGROUND_H
#define CBACKGROUND_H
#include "object\C_Object.h"

class C_BackGround : public C_Object{
public:
	//�R���X�g���N�^��ݒ�
	C_BackGround();
	//�X�V����
	void Update();
	//�`�揈��
	void Draw();
};

class C_BackGround2 : public C_Object{
public:
	//�R���X�g���N�^��ݒ�
	C_BackGround2();
	//�X�V����
	void Update();
	//�`�揈��
	void Draw();
};
#endif