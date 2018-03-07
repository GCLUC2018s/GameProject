#include "CTaskManager.h"

CTaskManager *CTaskManager::mpInstance = 0;

CTaskManager *CTaskManager::Get(){
	if (mpInstance == 0){
		//それぞれのタスクマネージャーインスタンスをポインタで作成
		mpInstance = new CTaskManager();      
	}
	//mpInstanceの中身が変わっているのでそれ以上はインスタンスを作成しない
	return mpInstance;
}

void CTaskManager::Add(CTask *p){

	/*
	Head→Next→Next～Next→Tail
	の順に処理するものとする。
	*/
	if (mp_Head == 0){
		mp_Head = p;             //
		mp_Tail = p;             //
		mp_Tail->mp_Next = 0;    //
	}
}

void CTaskManager::Update(){

}