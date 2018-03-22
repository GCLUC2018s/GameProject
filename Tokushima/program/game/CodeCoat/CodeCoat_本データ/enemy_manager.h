#ifndef ENEMY_MANAGER
#define ENEMY_MANAGER

#include <math.h>
#include <vector>
#include "enemy.h"

class CEnemyManager{
private:
	int m_comb;
	bool m_del_point;
	static CEnemyManager*	mp_instance;
	std::vector<CEnemy*>	m_enemy_list;

	//コンストラクタ
	CEnemyManager();

public:
	~CEnemyManager();
	static CEnemyManager* getInstance();
	static void clearInstance();
	void Init();
	void Update();
	void Draw();
	void LoadFile();
	void CombUpdate();							//追加　	コンボやスコアの処理
	void CombInc(){ m_comb++; };				//			コンボの加算
	void SetDel(bool f){ m_del_point = f; };	//			敵の消滅時に使用(true)、なおUIでリセットする（false）
	void SetComb(int c){ m_comb = c; };			//			コンボのリセット
	int GetComb(){ return m_comb; };			//			コンボ数を返す
	bool GetDel(){ return m_del_point; };		//ここまで　敵の消滅したかのフラグを返す
	std::vector<CEnemy*> getEnemyList() const;
	void Remove(CEnemy* enemy);					//追加enemylistから引数アドレスを削除
};

#endif ENEMY_MANAGER