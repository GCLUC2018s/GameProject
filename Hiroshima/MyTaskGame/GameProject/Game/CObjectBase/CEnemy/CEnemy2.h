#ifndef ENEMY2GUARD
#define ENEMY2GUARD
#include"../CObjectBase.h"
/*

����ҁ@��

*/
//��
class CEnemy2 :public CObjectBase {
public:
	CEnemy2(CVector3D *pos);
	~CEnemy2();
	void Update();
};




#endif // !ENEMY4GUARD
