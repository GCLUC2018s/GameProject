#ifndef BOSSGUARD
#define BOSSGUARD

#define BOSS_HP 100
#define BOSS_AT 20
#define BOSS_SPEED 5

//#include"../CObjectBase.h"
#include"BossBase.h"
/*

����ҁ@��

*/

/*
�{���F
�e�X�g�쐬���������̃N���X�ł�
���̃R�����g�́A���ۍ��o����������Ă�
*/
class CBoss :public CBossBase {
protected:
	int m_test;
public:
	CBoss(const CVector3D *pos);
	~CBoss();
	void Update();
};




#endif // !BOSSGUARD
