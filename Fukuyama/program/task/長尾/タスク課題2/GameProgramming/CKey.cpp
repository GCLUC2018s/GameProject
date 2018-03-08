#include "CKey.h"
#include "windows.h"
extern int AUTOmove;
//文字コード分のフラグ
//trueのところのキーは押されている
bool CKey::flg[256];
/*
 push
 kキーが押されていればtrue
 押されていなければfalse
 使い方
 Wキーが押されているか？
 if(CKey::Push('W'))
*/
bool CKey::Push(char p) {
	return GetKeyState(p) & 0x8000;
}
/*
 once
 kキーが押された最初はtrue
 押したままだと、その後はfalse
 使い方
 Wキーが押されているか？
 if(CKey::Once('W'))
 */
bool CKey::Once(char p) {
	//kキーが押されているか？
	if (GetKeyState(p) & 0x8000) {
		//すでに押されているか？
		if (flg[p]) {
			//押されていたらfalse
			return false;
		}
		else {
			//押されていなければ
			//flgにtrueを設定
			flg[p] = true;
			return true;
		}
	}
	else {
		//そのキーが押されてなければ
		//flgをfalseに設定
		flg[p] = false;
	}
	return false;
}
