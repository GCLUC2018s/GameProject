#ifndef NAGAO_H
#define NAGAO_H
#include "object\CManhole.h"
#include "object\CDrum.h"
class Nagao{
public:
	//�e�X�g�p�R���X�g���N�^���쐬
	Nagao(){
		Drum = new C_Drum();
		Manhole = new C_Manhole();
	}
	C_Drum* Drum;
	C_Manhole* Manhole;
private:
};
#endif