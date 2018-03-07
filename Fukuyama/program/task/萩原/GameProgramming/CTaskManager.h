#ifndef CTASKMANAGER_H
#define CTASKMANAGER_H

#include "CTask.h"

class CTaskManager
{
private:
	static CTaskManager *mpInstance;         //mp_はメンバ兼ポインタ
	CTask *mp_Head;                   
	CTask *mp_Tail;
	CTaskManager() :mp_Head(0), mp_Tail(0){};
public:
	static CTaskManager *Get();
	/*
	mpInstanceでデータ領域を確保するためのメソッド
	新しくCTaskでインスタンスを作成したとき、タスクマネージャーで
	管理するための領域を確保するためにGetを使用する
	*/
	void Add(CTask *p);
	/*
	CTaskのポインタで作成したインスタンスのアドレスを求める
	*/
	void Update();
};

#endif