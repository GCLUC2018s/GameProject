#ifndef CMATRIX33_H
#define CMATRIX33_H
#include <string.h>
class CMatrix33{
public:
	//�R���X�g���N�^�Ŗ���������h��
	CMatrix33(){
		memset(m, 0, sizeof(m));
	}
	float m[3][3];
	void firstcount();
};
#endif