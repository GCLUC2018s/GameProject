#ifndef NAGAO_H
#define NAGAO_H
#include "object\CManhole.h"
class Nagao{
public:
	//�e�X�g�p�R���X�g���N�^���쐬
	Nagao(){
		Manhole = new C_Manhole();
	}
	C_Manhole* Manhole;
private:
};
#endif