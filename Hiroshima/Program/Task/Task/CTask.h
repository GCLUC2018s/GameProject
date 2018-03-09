#ifndef TASK_GUARD
#define TASK_GUARD

#include <stdio.h>

//更新順序
enum E_UpdatePrio
{
	eUDP_Tutorial,
	eUDP_Gimmick,
	eUDP_Player,
	eUDP_Camera,
	eUDP_Enemy,
	eUDP_Item,
	eUDP_Map,
	eUDP_Null,
};
//描画順序
enum E_DrawPrio
{
	eDWP_Map,
	eUDP_Gimmick,
	eDWP_Player,
	eDWP_Enemy,
	eUDP_Item,
	eDWP_Tutorial,
	eDWP_Null,
};

//タスクヘッダー
class CTask
{
protected:
	bool m_death_flag;	//死亡フラグ
	bool m_swap_flag;	//入れ替えフラグ
	bool m_pause_flag;	//更新停止フラグ
	int	m_id;

	int m_Update_prio;
	int	m_Draw_prio;

	CTask* m_Update_next;	//自分の次のアドレス（更新）
	CTask* m_Draw_next;		//自分の次のアドレス（描画）
	CTask* m_Update_prev;	//自分の前のアドレス（更新）
	CTask* m_Draw_prev;		//自分の前のアドレス（描画）

public:
	/*
	CTaskクラスのコンストラクタ
	m_id			おそらく０固定でおｋ
	m_updatePrio	↑の更新順序参照
	m_drawPrio		↑の描画順序参照
	*/
	CTask(int id, int updatePrio, int drawPrio);
	virtual ~CTask();
	virtual void Update();	//派生先クラスでの更新を行う関数
	virtual void Draw();	//派生先クラスでの描写を行う関数
	
	//呼び出した対象の死亡フラグを立てる
	void SetDeath() {
		m_death_flag = true;
	};
	static void HitCheck(CTask* t1, CTask* t2);
	static void Swap_Draw(CTask* t1, CTask* t2);
	static void Swap_Update(CTask* t1, CTask* t2);

	friend class CTaskManager;

};
#endif // !TASK_GUARD