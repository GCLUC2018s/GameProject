#ifndef CDRUM_H
#define CDRUM_H
#include "../draw/CRectangle.h"
#include "C_Object.h"

class C_Drum : public  C_Object{
private:
	int m_DrumPos_Random = rand() % 3;
	void Dmain();
public:
	//�X�V����
	void Update();

	//�`�揈��
	void Draw();

	//�R���X�g���N�^��ݒ�
	C_Drum();

	//�Փ˔���
};

#endif