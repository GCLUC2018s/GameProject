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

	//�R���X�g���N�^
	CEnemyManager();

public:
	~CEnemyManager();
	static CEnemyManager* getInstance();
	static void clearInstance();
	void Init();
	void Update();
	void Draw();
	void LoadFile();
	void CombUpdate();							//�ǉ��@	�R���{��X�R�A�̏���
	void CombInc(){ m_comb++; };				//			�R���{�̉��Z
	void SetDel(bool f){ m_del_point = f; };	//			�G�̏��Ŏ��Ɏg�p(true)�A�Ȃ�UI�Ń��Z�b�g����ifalse�j
	void SetComb(int c){ m_comb = c; };			//			�R���{�̃��Z�b�g
	int GetComb(){ return m_comb; };			//			�R���{����Ԃ�
	bool GetDel(){ return m_del_point; };		//�����܂Ł@�G�̏��ł������̃t���O��Ԃ�
	std::vector<CEnemy*> getEnemyList() const;
	void Remove(CEnemy* enemy);					//�ǉ�enemylist��������A�h���X���폜
};

#endif ENEMY_MANAGER