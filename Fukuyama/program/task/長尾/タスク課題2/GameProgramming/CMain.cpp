//�w�b�_�t�@�C���̃C���N���[�h
#include "CMain.h"
#include "glut.h"
void CMain::Init(){
	mPlayer = new CPlayer();
	mPlayer->Init();
	//���X�g�ɒǉ�
	CTaskManager::GetInstance()->Add(mPlayer);
}
void CMain::Update(){
	CTaskManager::GetInstance()->UpdateAll();
	CTaskManager::GetInstance()->DrawAll();
}