#ifndef CMANHOLE_H
#define CMANHOLE_H
#include "C_Object.h"

class C_Manhole : public C_Object{
private:
	//�����_�������m��
	int m_UorD_rand = rand() % 3;
public:
	//�R���X�g���N�^��ݒ�
	C_Manhole();

	//�X�V����
	void Update();

	//�`�揈��
	virtual void Draw();
};

#endif