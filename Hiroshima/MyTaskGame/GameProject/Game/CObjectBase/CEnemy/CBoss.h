#ifndef BOSSGUARD
#define BOSSGUARD

#include"../CObjectBase.h"
/*

����ҁ@��

*/
class CBoss :public CObjectBase {
public:
	CBoss(CVector3D *pos);
	~CBoss();
	void Update();
};




#endif // !EBEMY1GUARD
