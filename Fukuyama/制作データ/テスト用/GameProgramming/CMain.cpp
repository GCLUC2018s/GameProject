//�w�b�_�t�@�C���̃C���N���[�h
#include "CMain.h"
#include "glut.h"
#include "test.h"
test tes;
//���߂�1�񂾂����s���鏈���̒�`
void CMain::Init() {
	tes.Init();
}

//�J��Ԃ����s���鏈���̒�`
void CMain::Update() {
	tes.Update();
	tes.Render();
}
