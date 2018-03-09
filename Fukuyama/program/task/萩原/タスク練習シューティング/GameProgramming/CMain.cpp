//�w�b�_�t�@�C���̃C���N���[�h
#include "CMain.h"
#include "glut.h"
#include "CPlayer.h"
#include "CTaskManager.h"
#include "CTaskLinker.h"

//���߂�1�񂾂����s���鏈���̒�`
void CMain::Init() {
	//�v���C���[���쐬
	Player = new CPlayer();
	Player->Init();
	Player->SetVertex(-32,32,-32,32);
	CTaskManager::GetInstance()->Add((CTask*)Player);
}

//�J��Ԃ����s���鏈���̒�`
void CMain::Update() {
	//�^�X�N���X�V���Ă���
	CTaskManager::GetInstance()->UpdateAll();
	//�`�悵�Ă���
	CTaskManager::GetInstance()->DrawAll();
	//�t���O�������Ă�����̂��폜����
	CTaskManager::GetInstance()->KillAppoint();
}
