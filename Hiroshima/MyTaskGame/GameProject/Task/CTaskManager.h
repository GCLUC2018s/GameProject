#ifndef TASK_MANAGER_GUARD
#define TASK_MANAGER_GUARD

class CTask;
class CTaskLinker;

class CTaskManager
{
private:
	static CTaskManager *mp_instance;	//一個しかいらないから
protected:
	CTaskLinker *mp_U_Top;	//Update用の先頭ポインタ
	CTaskLinker *mp_U_End;	//Update用の末尾ポインタ

	CTaskLinker *mp_D_Top;	//Draw用の先頭ポインタ
	CTaskLinker *mp_D_End;	//Draw用の末尾ポインタ
public:
	CTaskManager();
	~CTaskManager();
	//リスト追加関数
	void Add(CTask *p);
	//リスト内削除関数
	CTask* Kill(CTask *p);
	//リスト内指定削除関数
	void KillAppoint();
	//タスクを全削除
	void KillAll();
	//全タスクの削除フラグをtrueにする
	void SetKillAll();
	//指定のIDのポーズフラグをそれにセットする
	void SetPause(int ID, bool flag);
	//リスト更新関数
	void UpdateAll();
	//リスト描画関数
	void DrawAll();
	// 更新優先度を変更 
	void ChangeUpdatePrio(CTask *p, int prio);
	// 描画優先度を変更 
	void ChangeDrawPrio(CTask *p, int prio);
	////描画順位入れ替え
	//void SwapDrawPrio(CTask *p1, CTask *p2);

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
	void AddTask(CTaskLinker *p, CTaskLinker **pTop, CTaskLinker **pEnd);

	// リストから外す 
	void RemoveTask(CTaskLinker *p, CTaskLinker **pTop, CTaskLinker **pEnd);



};
#endif // !TASK_MANAGER_GUARD

