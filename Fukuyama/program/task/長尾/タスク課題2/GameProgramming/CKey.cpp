#include "CKey.h"
#include "windows.h"
extern int AUTOmove;
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
bool CKey::Push(char p) {
	return GetKeyState(p) & 0x8000;
}
/*
 once
 k�L�[�������ꂽ�ŏ���true
 �������܂܂��ƁA���̌��false
 �g����
 W�L�[��������Ă��邩�H
 if(CKey::Once('W'))
 */
bool CKey::Once(char p) {
	//k�L�[��������Ă��邩�H
	if (GetKeyState(p) & 0x8000) {
		//���łɉ�����Ă��邩�H
		if (flg[p]) {
			//������Ă�����false
			return false;
		}
		else {
			//������Ă��Ȃ����
			//flg��true��ݒ�
			flg[p] = true;
			return true;
		}
	}
	else {
		//���̃L�[��������ĂȂ����
		//flg��false�ɐݒ�
		flg[p] = false;
	}
	return false;
}
