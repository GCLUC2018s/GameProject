#include "CTaskManager.h"

CTaskManager *CTaskManager::mpInstance = 0;

CTaskManager *CTaskManager::Get(){
	if (mpInstance == 0){
		//���ꂼ��̃^�X�N�}�l�[�W���[�C���X�^���X���|�C���^�ō쐬
		mpInstance = new CTaskManager();      
	}
	//mpInstance�̒��g���ς���Ă���̂ł���ȏ�̓C���X�^���X���쐬���Ȃ�
	return mpInstance;
}

void CTaskManager::Add(CTask *p){

	/*
	Head��Next��Next�`Next��Tail
	�̏��ɏ���������̂Ƃ���B
	*/
	if (mp_Head == 0){
		mp_Head = p;             //
		mp_Tail = p;             //
		mp_Tail->mp_Next = 0;    //
	}
}

void CTaskManager::Update(){

}