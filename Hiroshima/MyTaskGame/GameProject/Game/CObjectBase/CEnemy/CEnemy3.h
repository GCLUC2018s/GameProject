#ifndef ENEMY3GUARD
#define ENEMY3GUARD
#include"../CObjectBase.h"

#define HI_HP 3
#define HI_AT 7
#define HI_SPEED 5

#define HI_FLOAT 0.1f
/*

»ìÒ@Â–Ø

*/
//‰Î‚Ì‹Ê
class CEnemy3 :public CObjectBase {
private:
	float m_a;	//•‚—V—p
public:
	CEnemy3(CVector3D *pos);
	~CEnemy3();
	void Update();
};




#endif // !ENEMY3GUARD
