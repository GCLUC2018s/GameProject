#include "CKey.h"
#include "windows.h"

//�����R�[�h���̃t���O
//true�̂Ƃ���̃L�[�͉�����Ă���
bool CKey::flg[256];
/*
 push
 k�L�[��������Ă����true
 ������Ă��Ȃ����false
 �g����
 W�L�[��������Ă��邩�H
 if(CKey::Push('W'))
*/
bool CKey::Push(char k) {
	return GetKeyState(k) & 0x8000;
}
/*
 once
 k�L�[�������ꂽ�ŏ���true
 �������܂܂��ƁA���̌��false
 �g����
 W�L�[��������Ă��邩�H
 if(CKey::Once('W'))
 */
bool CKey::Once(char k) {
	//k�L�[��������Ă��邩�H
	if (GetKeyState(k) & 0x8000) {
		//���łɉ�����Ă��邩�H
		if (flg[k]) {
			//������Ă�����false
			return false;
		}
		else {
			//������Ă��Ȃ����
			//flg��true��ݒ�
			flg[k] = true;
			return true;
		}
	}
	else {
		//���̃L�[��������ĂȂ����
		//flg��false�ɐݒ�
		flg[k] = false;
	}
	return false;
}
