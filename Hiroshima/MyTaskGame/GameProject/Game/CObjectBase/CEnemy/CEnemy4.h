#ifndef ENEMY4GUARD
#define ENEMY4GUARD
#include"../CObjectBase.h"
/*

����ҁ@��

*/
//���܂�����
class CEnemy4 :public CObjectBase {
public:
	CEnemy4(CVector3D *pos);
	~CEnemy4();
	void Update();
};




#endif // !ENEMY4GUARD
