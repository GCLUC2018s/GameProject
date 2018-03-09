#ifndef TASKMANAGER_GUARD
#define TASKMANAGER_GUARD

class CTask;

enum {
	eUpdate,
	eDraw,
};

class CTaskManager
{	
private:
	CTaskManager(); 
	static CTaskManager* mp_instance;	//ゲーム中で使うタスクマネージャーのポインタ。外部からは変えないで。使いたいならGetInstance()でどうぞ
	// リスト追加内部処理 
	void AddTaskIn(CTask **p, CTask **pTop, CTask **pEnd,bool flag);
	// リストから外す 
	void RemoveTask(CTask **p, CTask **pTop, CTask **pEnd,bool flag);

public:
	~CTaskManager();
	//リスト追加関数
	void Add(CTask *p);
	//リスト内削除関数
	CTask* Kill(CTask *p);
	//リスト内指定削除関数
	void KillAppoint();
	//リスト更新関数
	void UpdateAll();
	//リスト描画関数
	void DrawAll();
	/*
	CTaskManagerを生成して変数に格納
	CTaskManagerは、ゲーム中で一個しかいらないので、複数作られるのを阻止する
	*/
	static CTaskManager* GetInstance();
protected:
	CTask* mp_Upd_Top;		  //Updateで使う、先頭を示すポインタ
	CTask* mp_Upd_End;		  //Updateで使う、終わりを示すポインタ
	CTask* mp_Drw_Top;		  //Drawで使う、先頭を示すポインタ
	CTask* mp_Drw_End;		  //Drawで使う、終わりを示すポインタ

};

#endif	//!TASKMANAGER_GUARD