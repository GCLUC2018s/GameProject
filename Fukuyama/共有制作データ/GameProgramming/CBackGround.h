#ifndef CBACKGROUND_H
#define CBACKGROUND_H
#include "object\C_Object.h"

//�w�i�N���X
class C_BackGround : public C_Object{
public:
	//�R���X�g���N�^��ݒ�
	C_BackGround();
	//�X�V����
	void Update();
	//�`�揈��
	void Draw();
};

//�_�N���X
class C_Cloud : public C_Object{
public:
	//�R���X�g���N�^��ݒ�
	C_Cloud();
	//�X�V����
	void Update();
	//�`�揈��
	void Draw();
};
#endif