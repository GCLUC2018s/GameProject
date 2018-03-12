#ifndef EBEMY1GUAD
#define EBEMY1GUAD

#include"../CObjectBase.h"
/*

êªçÏé“Å@ê¬ñÿ

*/
class CEnemy1 :public CObjectBase {
public:
	CEnemy1(CVector3D *pos);
	~CEnemy1();
	void Update();
};




#endif // !EBEMY1GUAD