#include "Nagao.h"

//�R���X�g���N�^����
Nagao::Nagao()
{
	Manhole = new C_Manhole();
}

void Nagao::Update(){
	Manhole->Update();
}

//�`�揈��
void Nagao::Draw(){
	Manhole->Draw();
}
