#ifndef ENEMY3GUARD
#define ENEMY3GUARD
#include"../CObjectBase.h"
/*

����ҁ@��

*/
//�΂̋�
class CEnemy3 :public CObjectBase {
public:
	CEnemy3(CVector3D *pos);
	~CEnemy3();
	void Update();
};




#endif // !ENEMY3GUARD
