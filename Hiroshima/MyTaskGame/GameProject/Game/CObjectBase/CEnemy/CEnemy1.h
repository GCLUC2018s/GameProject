#ifndef EBEMY1GUAD
#define EBEMY1GUAD

#include"../CObjectBase.h"
/*

製作者　青木

*/
class CEnemy1 :public CObjectBase {
public:
	CEnemy1(CVector3D *pos);
	~CEnemy1();
	void Update();
};




#endif // !EBEMY1GUAD