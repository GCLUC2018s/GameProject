#ifndef ENEMY1GUARD
#define ENEMY1GUARD

#include"../CObjectBase.h"
/*

»ìÒ@Â–Ø

*/
//‚¾‚é‚Ü
class CEnemy1 :public CObjectBase {
public:
	CEnemy1(CVector3D *pos);
	~CEnemy1();
	void Update();
};




#endif // !ENEMY1GUARD