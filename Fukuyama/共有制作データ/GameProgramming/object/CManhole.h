#ifndef CMANHOLE_H
#define CMANHOLE_H
#include "CRectangle.h"
#include "random"
#include "CMain.h"
#include "CKey.h"
#include "stdio.h"
#include "time.h"

class C_Manhole : public C_Rectangle{
protected:
	//�����_�������m��
	int m_UorD_rand=rand()%2;
	//�}���z�[�����E�|�W�V����
	float m_PotisionX(float m_H);

	//�}���z�[���㉺�|�W�V����
	float m_PotisionY(float m_V);

public:
	//��R���X�g���N�^��ݒ�
	C_Manhole();

	//�X�V����
	void Update();

	//�`�揈��
	void Draw();
};

#endif