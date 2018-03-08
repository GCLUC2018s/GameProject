/**
* @file		CTaskManager.h
* @brief	タスクシステム管理クラス
* @author	ryoji anzai,yuki yamaji 
*/

#ifndef TASKMANAGER_GUARD
#define TASKMANAGER_GUARD

//#include "CTask.h"

class CTaskLinker;
class CTask;


class CTaskManager
{
private:
	CTaskManager();
	static CTaskManager* mp_instance;	//シングルトン化のためのポインタ
protected:
	CTaskLinker *mp_updHead;		// Update用 先頭要素を指すポインタ
	CTaskLinker *mp_updTail;		// Update用 末尾要素を指すポインタ

	CTaskLinker *mp_drwHead;		// Draw用 先頭要素を指すポインタ
	CTaskLinker *mp_drwTail;		// Draw用 末尾要素を指すポインタ

public:
	~CTaskManager();
	//リスト追加関数
	void Add(CTask *p);
	//リスト内削除関数
	CTask* Kill(CTask *p);
	//リスト内指定削除関数
	void KillAppoint();
	//リスト内全削除関数
	void KillAll();
	//リスト更新関数
	void UpdateAll();
	//リスト描画関数
	void DrawAll();
	//当たり判定関数
	void CollisionAll();

	// 更新優先度を変更 
	void ChangeUpdatePrio(CTask *p, int prio);
	// 描画優先度を変更 
	void ChangeDrawPrio(CTask *p, int prio);

	//タスク取得関数
	CTask* GetTask(int id);
	//タスクカウント関数
	int GetCount(int id);

	//CTaskManagerを生成して変数に格納
	static CTaskManager* GetInstance();
	//格納されているものを削除
	static void ClearInstance();

private:
	// リスト追加内部処理 
	void AddTaskInner( CTaskLinker *p, CTaskLinker **pHead, CTaskLinker **pTail );

	// リストから外す 
	void RemoveTaskLinker( CTaskLinker *p, CTaskLinker **pHead, CTaskLinker **pTail );

};

#endif