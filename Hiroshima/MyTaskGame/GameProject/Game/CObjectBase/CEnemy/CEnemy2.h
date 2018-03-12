#ifndef ENEMY2GUARD
#define ENEMY2GUARD
#include"../CObjectBase.h"

#define CHOCHIN_HP 5
#define CHOCHIN_AT 3
#define CHOCHIN_SPEED 4
/*

»ìÒ@Â–Ø

*/
//’ñ“”
class CEnemy2 :public CObjectBase {
private:
	float a;
public:
	CEnemy2(CVector3D *pos);
	~CEnemy2();
	void Update();
};




#endif // !ENEMY4GUARD
