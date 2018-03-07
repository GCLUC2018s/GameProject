#ifndef CTASKMANAGER_H
#define CTASKMANAGER_H

#include "CTask.h"

class CTaskManager
{
private:
	static CTaskManager *mpInstance;         //mp_�̓����o���|�C���^
	CTask *mp_Head;                   
	CTask *mp_Tail;
	CTaskManager() :mp_Head(0), mp_Tail(0){};
public:
	static CTaskManager *Get();
	/*
	mpInstance�Ńf�[�^�̈���m�ۂ��邽�߂̃��\�b�h
	�V����CTask�ŃC���X�^���X���쐬�����Ƃ��A�^�X�N�}�l�[�W���[��
	�Ǘ����邽�߂̗̈���m�ۂ��邽�߂�Get���g�p����
	*/
	void Add(CTask *p);
	/*
	CTask�̃|�C���^�ō쐬�����C���X�^���X�̃A�h���X�����߂�
	*/
	void Update();
};

#endif