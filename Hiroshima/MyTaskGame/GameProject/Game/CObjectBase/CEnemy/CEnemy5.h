#ifndef ENEMY5GUARD
#define ENEMY5GUARD

#include"../CObjectBase.h"
/*

����ҁ@��

*/
//����
class CEnemy5 :public CObjectBase {
public:
	CEnemy5(CVector3D *pos);
	~CEnemy5();
	void Update();
};




#endif // !ENEMY1GUARD