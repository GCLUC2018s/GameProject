#ifndef ENEMY3GUARD
#define ENEMY3GUARD
#include"../CObjectBase.h"

#define HI_HP 3
#define HI_AT 7
#define HI_SPEED 5
/*

»ìÒ@Â–Ø

*/
//‰Î‚Ì‹Ê
class CEnemy3 :public CObjectBase {
public:
	CEnemy3(CVector3D *pos);
	~CEnemy3();
	void Update();
};




#endif // !ENEMY3GUARD
