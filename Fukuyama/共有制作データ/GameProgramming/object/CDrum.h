#ifndef CDRUM_H
#define CDRUM_H
#include "CManhole.h"

class C_Drum : public C_Manhole{
public:
	//�X�V����
	void Update();

	//�`�揈��
	void Draw();

	//�R���X�g���N�^��ݒ�
	C_Drum();
};

#endif