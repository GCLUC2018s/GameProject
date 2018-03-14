#ifndef ENEMY2GUARD
#define ENEMY2GUARD
//#include"../CObjectBase.h"
#include "CEnemyBase.h"

#define CHOCHIN_HP 5
#define CHOCHIN_AT 3
#define CHOCHIN_SPEED 4

#define CHOCHIN_FLOAT 0.3f
/*

»ìÒ@Â–Ø

*/
//’ñ“”
class CEnemy2 :public CEnemyBase {
private:
	float m_a;	//•‚—V—p
public:
	CEnemy2(const CVector3D *pos);
	~CEnemy2();
	void Update();
};




#endif // !ENEMY4GUARD
